#include "touch.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <linux/input.h>
#include <sys/time.h>

static int ts_fd = -1;
static int last_x = 0, last_y = 0;
static int is_pressed = 0;
static uint32_t press_start_ms = 0;

// 触摸屏原始坐标范围（需要根据实际设备校准）
// GEC6818 开发板常见范围
static int raw_x_min = 0;
static int raw_x_max = 1023;
static int raw_y_min = 0;
static int raw_y_max = 1023;

uint32_t touch_get_ms(void) {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (uint32_t)(tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int touch_init(void) {
    ts_fd = open(TOUCH_DEVICE, O_RDONLY | O_NONBLOCK);
    if (ts_fd < 0) {
        perror("[TOUCH] Failed to open touch device");
        return -1;
    }
    
    printf("[TOUCH] Touch device opened: %s\n", TOUCH_DEVICE);
    printf("[TOUCH] Screen resolution: %dx%d\n", SCREEN_WIDTH, SCREEN_HEIGHT);
    printf("[TOUCH] Raw coordinate range: X[%d-%d], Y[%d-%d]\n",
           raw_x_min, raw_x_max, raw_y_min, raw_y_max);
    printf("[TOUCH] Origin: Bottom-left corner\n");
    
    return 0;
}

void touch_close(void) {
    if (ts_fd >= 0) {
        close(ts_fd);
        ts_fd = -1;
    }
}

void touch_set_range(int x_min, int x_max, int y_min, int y_max) {
    raw_x_min = x_min;
    raw_x_max = x_max;
    raw_y_min = y_min;
    raw_y_max = y_max;
    printf("[TOUCH] Range updated: X[%d-%d], Y[%d-%d]\n",
           raw_x_min, raw_x_max, raw_y_min, raw_y_max);
}

/**
 * @brief 坐标映射函数
 * 
 * 将原始坐标映射到屏幕逻辑坐标
 * 原点：左下角
 * X轴：向右为正 (0 -> SCREEN_WIDTH)
 * Y轴：向上为正 (0 -> SCREEN_HEIGHT)
 */
static void map_coordinate(int raw_x, int raw_y, int *logic_x, int *logic_y) {
    int x_range = raw_x_max - raw_x_min;
    int y_range = raw_y_max - raw_y_min;
    
    if (x_range <= 0) x_range = 1;
    if (y_range <= 0) y_range = 1;
    
    // 线性映射
    *logic_x = (raw_x - raw_x_min) * (SCREEN_WIDTH - 1) / x_range;
    *logic_y = (raw_y - raw_y_min) * (SCREEN_HEIGHT - 1) / y_range;
    
    // Y轴翻转：原始Y轴向下为正，转换为向上为正
    *logic_y = (SCREEN_HEIGHT - 1) - *logic_y;
    
    // 边界裁剪
    if (*logic_x < 0) *logic_x = 0;
    if (*logic_x >= SCREEN_WIDTH) *logic_x = SCREEN_WIDTH - 1;
    if (*logic_y < 0) *logic_y = 0;
    if (*logic_y >= SCREEN_HEIGHT) *logic_y = SCREEN_HEIGHT - 1;
}

int touch_read_event(touch_event_t *ev) {
    if (!ev || ts_fd < 0) return 0;
    
    struct input_event events[64];
    ssize_t nread;
    
    nread = read(ts_fd, events, sizeof(events));
    if (nread < 0 || nread == 0) {
        return 0;
    }
    
    ssize_t num_events = nread / sizeof(struct input_event);
    
    for (ssize_t i = 0; i < num_events; i++) {
        struct input_event *e = &events[i];
        
        if (e->type == EV_ABS) {
            if (e->code == ABS_X) {
                last_x = e->value;
            } else if (e->code == ABS_Y) {
                last_y = e->value;
            }
        }
        else if (e->type == EV_KEY && e->code == BTN_TOUCH) {
            if (e->value == 1) {
                is_pressed = 1;
                press_start_ms = touch_get_ms();
            }
            else if (e->value == 0) {
                if (is_pressed) {
                    uint32_t press_duration = touch_get_ms() - press_start_ms;
                    
                    if (press_duration >= MIN_PRESS_MS && press_duration < MAX_PRESS_MS) {
                        int logic_x, logic_y;
                        map_coordinate(last_x, last_y, &logic_x, &logic_y);
                        
                        ev->x = logic_x;
                        ev->y = logic_y;
                        ev->action = TOUCH_ACTION_RELEASE;
                        ev->timestamp_ms = press_start_ms;
                        
                        printf("[TOUCH] Raw: (%d,%d) -> Logic: (%d,%d) [duration=%dms]\n", 
                               last_x, last_y, ev->x, ev->y, (int)press_duration);
                        
                        is_pressed = 0;
                        return 1;
                    }
                }
                is_pressed = 0;
            }
        }
    }
    
    return 0;
}