#ifndef FB_H
#define FB_H

#include <stdint.h>

#define LCD_WIDTH   800
#define LCD_HEIGHT  480

#define FB_PIXEL_SIZE   4

extern uint32_t *lcd_buf;
extern int lcd_fd;

int fb_init(void);
void fb_close(void);
void fb_draw_bmp(int x, int y, const uint8_t *data, int w, int h);
void fb_fill_rect(int x, int y, int w, int h, uint32_t color);
void fb_copy_from_bg(int x, int y, int w, int h);
void fb_flush_screen(void);
void fb_flush_rect(int x, int y, int w, int h);

#endif