#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <stdint.h>
#include <stdbool.h>

#define FLOOR_COUNT      10
#define FLOOR_MOVE_TIME_MS     500
#define BLINK_INTERVAL_MS      750
#define BLINK_CYCLES           3
#define DOOR_OPEN_TIME_MS      2000
#define SELECTED_TIMEOUT_MS    5000
#define LONG_PRESS_TIME_MS     3000

typedef enum {
    STATE_IDLE,
    STATE_MOVING,
    STATE_ARRIVAL,
    STATE_DOOR_OPEN,
    STATE_RESET
} elevator_state_t;

typedef enum {
    DIR_STOP,
    DIR_UP,
    DIR_DOWN
} elevator_direction_t;

typedef struct {
    int current_floor;
    elevator_direction_t direction;
    elevator_state_t state;
    bool inner_requested[FLOOR_COUNT + 1];
    bool outer_up[FLOOR_COUNT + 1];
    bool outer_down[FLOOR_COUNT + 1];
    int selected_floor;
    uint32_t selected_expire_ms;
    
    uint32_t last_move_ms;
    int blink_count;
    uint32_t last_blink_ms;
    bool blink_visible;
    uint32_t door_start_ms;
} elevator_t;

extern elevator_t g_elevator;

void elevator_init(void);
void elevator_reset(void);

void elevator_add_inner_request(int floor);
void elevator_add_outer_up_request(int floor);
void elevator_add_outer_down_request(int floor);

void elevator_process(uint32_t now_ms);

int elevator_get_current_floor(void);
elevator_state_t elevator_get_state(void);
elevator_direction_t elevator_get_direction(void);

#endif