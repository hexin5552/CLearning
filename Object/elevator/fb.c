#include "fb.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <linux/fb.h>

uint32_t *lcd_buf = NULL;
int lcd_fd = -1;
static uint32_t *bg_buf = NULL;

int fb_init(void) {
    lcd_fd = open("/dev/fb0", O_RDWR);
    if (lcd_fd < 0) {
        perror("[FB] Failed to open /dev/fb0");
        return -1;
    }

    struct fb_var_screeninfo var_info;
    struct fb_fix_screeninfo fix_info;
    
    if (ioctl(lcd_fd, FBIOGET_VSCREENINFO, &var_info) < 0) {
        perror("[FB] Failed to get screen info");
        close(lcd_fd);
        return -1;
    }
    
    if (ioctl(lcd_fd, FBIOGET_FSCREENINFO, &fix_info) < 0) {
        perror("[FB] Failed to get fix screen info");
        close(lcd_fd);
        return -1;
    }

    printf("[FB] Screen: %dx%d, %d bpp, line_len=%d\n",
           var_info.xres, var_info.yres, var_info.bits_per_pixel, fix_info.line_length);

    int buf_size = LCD_WIDTH * LCD_HEIGHT * FB_PIXEL_SIZE;
    lcd_buf = (uint32_t *)mmap(NULL, buf_size, PROT_READ | PROT_WRITE, MAP_SHARED, lcd_fd, 0);
    if (lcd_buf == MAP_FAILED) {
        perror("[FB] Failed to mmap framebuffer");
        close(lcd_fd);
        return -1;
    }
    
    bg_buf = (uint32_t *)malloc(buf_size);
    if (!bg_buf) {
        perror("[FB] Failed to allocate background buffer");
        munmap(lcd_buf, buf_size);
        close(lcd_fd);
        return -1;
    }

    printf("[FB] Framebuffer mapped at %p, size %d bytes\n", lcd_buf, buf_size);
    return 0;
}

void fb_close(void) {
    if (bg_buf) {
        free(bg_buf);
        bg_buf = NULL;
    }
    if (lcd_buf) {
        munmap(lcd_buf, LCD_WIDTH * LCD_HEIGHT * FB_PIXEL_SIZE);
        lcd_buf = NULL;
    }
    if (lcd_fd >= 0) {
        close(lcd_fd);
        lcd_fd = -1;
    }
}

void fb_draw_bmp(int x, int y, const uint8_t *data, int w, int h) {
    if (!lcd_buf || !data) return;
    
    for (int row = 0; row < h; row++) {
        int sy = y + row;
        if (sy < 0 || sy >= LCD_HEIGHT) continue;
        
        for (int col = 0; col < w; col++) {
            int sx = x + col;
            if (sx < 0 || sx >= LCD_WIDTH) continue;
            
            int buf_idx = sy * LCD_WIDTH + sx;
            int data_idx = (h - 1 - row) * w * 4 + col * 4;
            
            uint8_t b = data[data_idx];
            uint8_t g = data[data_idx + 1];
            uint8_t r = data[data_idx + 2];
            uint8_t a = data[data_idx + 3];
            
            if (a > 128) {
                lcd_buf[buf_idx] = (a << 24) | (r << 16) | (g << 8) | b;
            }
        }
    }
}

void fb_fill_rect(int x, int y, int w, int h, uint32_t color) {
    if (!lcd_buf) return;
    
    for (int row = 0; row < h; row++) {
        int sy = y + row;
        if (sy < 0 || sy >= LCD_HEIGHT) continue;
        
        for (int col = 0; col < w; col++) {
            int sx = x + col;
            if (sx < 0 || sx >= LCD_WIDTH) continue;
            
            int buf_idx = sy * LCD_WIDTH + sx;
            lcd_buf[buf_idx] = color;
        }
    }
}

void fb_copy_from_bg(int x, int y, int w, int h) {
    if (!lcd_buf || !bg_buf) return;
    
    for (int row = 0; row < h; row++) {
        int sy = y + row;
        if (sy < 0 || sy >= LCD_HEIGHT) continue;
        
        for (int col = 0; col < w; col++) {
            int sx = x + col;
            if (sx < 0 || sx >= LCD_WIDTH) continue;
            
            int buf_idx = sy * LCD_WIDTH + sx;
            lcd_buf[buf_idx] = bg_buf[buf_idx];
        }
    }
}

void fb_save_bg_region(int x, int y, int w, int h) {
    if (!lcd_buf || !bg_buf) return;
    
    for (int row = 0; row < h; row++) {
        int sy = y + row;
        if (sy < 0 || sy >= LCD_HEIGHT) continue;
        
        for (int col = 0; col < w; col++) {
            int sx = x + col;
            if (sx < 0 || sx >= LCD_WIDTH) continue;
            
            int buf_idx = sy * LCD_WIDTH + sx;
            bg_buf[buf_idx] = lcd_buf[buf_idx];
        }
    }
}

void fb_flush_screen(void) {
    if (lcd_fd < 0 || !lcd_buf) return;
    lseek(lcd_fd, 0, SEEK_SET);
    ssize_t ret = write(lcd_fd, lcd_buf, LCD_WIDTH * LCD_HEIGHT * FB_PIXEL_SIZE);
    (void)ret;
}

void fb_flush_rect(int x, int y, int w, int h) {
    if (lcd_fd < 0 || !lcd_buf) return;
    
    int start = y * LCD_WIDTH + x;
    lseek(lcd_fd, start * FB_PIXEL_SIZE, SEEK_SET);
    for (int row = 0; row < h; row++) {
        ssize_t ret = write(lcd_fd, &lcd_buf[start + row * LCD_WIDTH], w * FB_PIXEL_SIZE);
        (void)ret;
    }
}