#include "debug.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <signal.h>
#include "elevator.h"

log_level_t g_log_level = LOG_LEVEL_INFO;

static FILE *log_file = NULL;

void log_init(void) {
    log_file = fopen("/tmp/elevator.log", "w");
    if (!log_file) {
        fprintf(stderr, "[DEBUG] Warning: Cannot open log file\n");
    }
    
    g_log_level = LOG_LEVEL_INFO;
}

void log_close(void) {
    if (log_file) {
        fclose(log_file);
        log_file = NULL;
    }
}

void log_printf(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    
    vprintf(fmt, args);
    va_end(args);
    
    if (log_file) {
        va_start(args, fmt);
        vfprintf(log_file, fmt, args);
        va_end(args);
        fflush(log_file);
    }
}

void debug_init(void) {
    log_init();
}

void debug_process(uint32_t now_ms) {
}

void debug_print_status(void) {
    LOG_INFO("Elevator status:");
    LOG_INFO("  Floor: %d", g_elevator.current_floor);
    LOG_INFO("  State: %s", 
             g_elevator.state == STATE_IDLE ? "IDLE" :
             g_elevator.state == STATE_MOVING ? "MOVING" :
             g_elevator.state == STATE_ARRIVAL ? "ARRIVAL" :
             g_elevator.state == STATE_DOOR_OPEN ? "DOOR_OPEN" : "UNKNOWN");
    LOG_INFO("  Direction: %s",
             g_elevator.direction == DIR_UP ? "UP" :
             g_elevator.direction == DIR_DOWN ? "DOWN" : "STOP");
    
    char inner[64] = "";
    char outer_up[64] = "";
    char outer_down[64] = "";
    int pos = 0;
    
    for (int f = 1; f <= FLOOR_COUNT; f++) {
        if (g_elevator.inner_requested[f]) {
            pos += sprintf(inner + pos, "%d ", f);
        }
    }
    if (pos == 0) strcpy(inner, "none");
    
    pos = 0;
    for (int f = 1; f <= FLOOR_COUNT; f++) {
        if (g_elevator.outer_up[f]) {
            pos += sprintf(outer_up + pos, "%d ", f);
        }
    }
    if (pos == 0) strcpy(outer_up, "none");
    
    pos = 0;
    for (int f = 1; f <= FLOOR_COUNT; f++) {
        if (g_elevator.outer_down[f]) {
            pos += sprintf(outer_down + pos, "%d ", f);
        }
    }
    if (pos == 0) strcpy(outer_down, "none");
    
    LOG_INFO("  Inner requests: %s", inner);
    LOG_INFO("  Outer up: %s", outer_up);
    LOG_INFO("  Outer down: %s", outer_down);
    LOG_INFO("  Selected floor: %d", g_elevator.selected_floor);
}