#ifndef TOUCH_H
#define TOUCH_H

#include <stdint.h>

#define TOUCH_DEVICE     "/dev/input/event0"
#define SCREEN_WIDTH     800
#define SCREEN_HEIGHT    480

#define DEBOUNCE_MS     50
#define MIN_PRESS_MS    100
#define MAX_PRESS_MS    2000

typedef enum {
    TOUCH_ACTION_NONE,
    TOUCH_ACTION_PRESS,
    TOUCH_ACTION_MOVE,
    TOUCH_ACTION_RELEASE
} touch_action_t;

typedef struct {
    int x, y;
    touch_action_t action;
    uint32_t timestamp_ms;
} touch_event_t;

int touch_init(void);
void touch_close(void);
int touch_read_event(touch_event_t *ev);

void touch_set_range(int x_min, int x_max, int y_min, int y_max);

uint32_t touch_get_ms(void);

#endif