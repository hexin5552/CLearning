#ifndef DEBUG_H
#define DEBUG_H

#include <stdint.h>

typedef enum {
    LOG_LEVEL_ERROR = 0,
    LOG_LEVEL_WARN,
    LOG_LEVEL_INFO,
    LOG_LEVEL_DEBUG,
    LOG_LEVEL_VERBOSE
} log_level_t;

extern log_level_t g_log_level;

#define LOG_ERROR(fmt, ...)   log_printf("[ERR] " fmt "\n", ##__VA_ARGS__)
#define LOG_WARN(fmt, ...)    log_printf("[WARN] " fmt "\n", ##__VA_ARGS__)
#define LOG_INFO(fmt, ...)    log_printf("[INFO] " fmt "\n", ##__VA_ARGS__)
#define LOG_DEBUG(fmt, ...)   log_printf("[DEBUG] " fmt "\n", ##__VA_ARGS__)

void log_init(void);
void log_close(void);
void log_printf(const char *fmt, ...);

void debug_init(void);
void debug_process(uint32_t now_ms);

#endif