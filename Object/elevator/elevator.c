#include "elevator.h"
#include <stdio.h>
#include <string.h>

elevator_t g_elevator;

static int has_any_request(void) {
    for (int f = 1; f <= FLOOR_COUNT; f++) {
        if (g_elevator.inner_requested[f] || 
            g_elevator.outer_up[f] || 
            g_elevator.outer_down[f]) {
            return 1;
        }
    }
    return 0;
}

static int has_forward_request(void) {
    if (g_elevator.direction == DIR_UP) {
        for (int f = g_elevator.current_floor + 1; f <= FLOOR_COUNT; f++) {
            if (g_elevator.inner_requested[f] || g_elevator.outer_up[f]) {
                return 1;
            }
        }
    } else if (g_elevator.direction == DIR_DOWN) {
        for (int f = g_elevator.current_floor - 1; f >= 1; f--) {
            if (g_elevator.inner_requested[f] || g_elevator.outer_down[f]) {
                return 1;
            }
        }
    }
    return 0;
}

static void determine_direction(void) {
    int has_up = 0, has_down = 0;
    for (int f = 1; f <= FLOOR_COUNT; f++) {
        if (g_elevator.inner_requested[f] || 
            g_elevator.outer_up[f] || 
            g_elevator.outer_down[f]) {
            if (f > g_elevator.current_floor) has_up = 1;
            if (f < g_elevator.current_floor) has_down = 1;
        }
    }
    if (has_up) g_elevator.direction = DIR_UP;
    else if (has_down) g_elevator.direction = DIR_DOWN;
    else g_elevator.direction = DIR_STOP;
}

static int should_stop(int floor) {
    if (g_elevator.inner_requested[floor]) return 1;
    if (g_elevator.direction == DIR_UP && g_elevator.outer_up[floor]) return 1;
    if (g_elevator.direction == DIR_DOWN && g_elevator.outer_down[floor]) return 1;
    return 0;
}

static void clear_floor_requests(int floor) {
    g_elevator.inner_requested[floor] = 0;
    g_elevator.outer_up[floor] = 0;
    g_elevator.outer_down[floor] = 0;
}

void elevator_init(void) {
    memset(&g_elevator, 0, sizeof(g_elevator));
    g_elevator.current_floor = 1;
    g_elevator.direction = DIR_STOP;
    g_elevator.state = STATE_IDLE;
    g_elevator.selected_floor = -1;
    
    printf("[ELEVATOR] Initialized at floor %d\n", g_elevator.current_floor);
}

void elevator_reset(void) {
    printf("[ELEVATOR] Resetting system...\n");
    
    for (int f = 1; f <= FLOOR_COUNT; f++) {
        g_elevator.inner_requested[f] = 0;
        g_elevator.outer_up[f] = 0;
        g_elevator.outer_down[f] = 0;
    }
    
    g_elevator.current_floor = 1;
    g_elevator.direction = DIR_STOP;
    g_elevator.state = STATE_IDLE;
    g_elevator.selected_floor = -1;
    
    printf("[ELEVATOR] Reset complete, returning to floor 1\n");
}

void elevator_add_inner_request(int floor) {
    if (floor < 1 || floor > FLOOR_COUNT) {
        fprintf(stderr, "[ELEVATOR] Warning: Invalid floor %d for inner request\n", floor);
        return;
    }
    
    if (!g_elevator.inner_requested[floor]) {
        g_elevator.inner_requested[floor] = 1;
        printf("[INFO] Inner request added: floor %d\n", floor);
    }
}

void elevator_add_outer_up_request(int floor) {
    if (floor < 1 || floor > FLOOR_COUNT) {
        fprintf(stderr, "[ELEVATOR] Warning: Invalid floor %d for outer up request\n", floor);
        return;
    }
    
    if (!g_elevator.outer_up[floor]) {
        g_elevator.outer_up[floor] = 1;
        printf("[INFO] Outer up request added: floor %d\n", floor);
    }
}

void elevator_add_outer_down_request(int floor) {
    if (floor < 1 || floor > FLOOR_COUNT) {
        fprintf(stderr, "[ELEVATOR] Warning: Invalid floor %d for outer down request\n", floor);
        return;
    }
    
    if (!g_elevator.outer_down[floor]) {
        g_elevator.outer_down[floor] = 1;
        printf("[INFO] Outer down request added: floor %d\n", floor);
    }
}

void elevator_process(uint32_t now_ms) {
    switch (g_elevator.state) {
        case STATE_IDLE:
            if (has_any_request()) {
                determine_direction();
                g_elevator.state = STATE_MOVING;
                g_elevator.last_move_ms = now_ms;
                printf("[INFO] Start moving %s\n", 
                       g_elevator.direction == DIR_UP ? "UP" : "DOWN");
            }
            break;
            
        case STATE_MOVING:
            if (now_ms - g_elevator.last_move_ms >= FLOOR_MOVE_TIME_MS) {
                if (g_elevator.direction == DIR_UP && g_elevator.current_floor < FLOOR_COUNT) {
                    g_elevator.current_floor++;
                } else if (g_elevator.direction == DIR_DOWN && g_elevator.current_floor > 1) {
                    g_elevator.current_floor--;
                } else {
                    g_elevator.state = STATE_IDLE;
                    g_elevator.direction = DIR_STOP;
                    printf("[INFO] Reached boundary, stopping\n");
                    break;
                }
                
                g_elevator.last_move_ms = now_ms;
                
                if (should_stop(g_elevator.current_floor)) {
                    clear_floor_requests(g_elevator.current_floor);
                    
                    g_elevator.state = STATE_ARRIVAL;
                    g_elevator.blink_count = 0;
                    printf("[INFO] Arrived at floor %d\n", g_elevator.current_floor);
                    break;
                }
                
                if (!has_forward_request()) {
                    g_elevator.direction = (g_elevator.direction == DIR_UP) ? DIR_DOWN : DIR_UP;
                    if (!has_any_request()) {
                        g_elevator.state = STATE_IDLE;
                        g_elevator.direction = DIR_STOP;
                        printf("[INFO] No more requests, stopping\n");
                    } else {
                        printf("[INFO] Reversing direction to %s\n",
                               g_elevator.direction == DIR_UP ? "UP" : "DOWN");
                    }
                }
            }
            break;
            
        case STATE_ARRIVAL:
            if (g_elevator.blink_count == 0) {
                g_elevator.last_blink_ms = now_ms;
                g_elevator.blink_visible = true;
                g_elevator.blink_count = 1;
            } else if (now_ms - g_elevator.last_blink_ms >= BLINK_INTERVAL_MS) {
                g_elevator.blink_visible = !g_elevator.blink_visible;
                g_elevator.last_blink_ms = now_ms;
                g_elevator.blink_count++;
                
                if (g_elevator.blink_count > BLINK_CYCLES * 2) {
                    g_elevator.state = STATE_DOOR_OPEN;
                    g_elevator.door_start_ms = now_ms;
                    printf("[INFO] Doors opening at floor %d\n", g_elevator.current_floor);
                }
            }
            break;
            
        case STATE_DOOR_OPEN:
            if (now_ms - g_elevator.door_start_ms >= DOOR_OPEN_TIME_MS) {
                g_elevator.state = STATE_IDLE;
                printf("[INFO] Doors closing at floor %d\n", g_elevator.current_floor);
            }
            break;
            
        case STATE_RESET:
            elevator_reset();
            g_elevator.state = STATE_IDLE;
            break;
    }
}

int elevator_get_current_floor(void) {
    return g_elevator.current_floor;
}

elevator_state_t elevator_get_state(void) {
    return g_elevator.state;
}

elevator_direction_t elevator_get_direction(void) {
    return g_elevator.direction;
}