#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include "fb.h"
#include "bmp.h"
#include "touch.h"
#include "elevator.h"
#include "debug.h"

#define AD_WIDTH        200
#define AD_HEIGHT       460
#define AD_COUNT        2
#define AD_SWITCH_INTERVAL_MS  5000

#define BTN_W           100
#define BTN_H           96

static volatile int g_running = 1;

typedef struct {
    int x, y, w, h;
    int floor;
    const char *name;
} button_rect_t;

static button_rect_t g_buttons[] = {
    {600, 384, BTN_W, BTN_H, 1, "1F"},
    {700, 384, BTN_W, BTN_H, 2, "2F"},
    {600, 288, BTN_W, BTN_H, 3, "3F"},
    {700, 288, BTN_W, BTN_H, 4, "4F"},
    {600, 192, BTN_W, BTN_H, 5, "5F"},
    {700, 192, BTN_W, BTN_H, 6, "6F"},
    {600, 96,  BTN_W, BTN_H, 7, "7F"},
    {700, 96,  BTN_W, BTN_H, 8, "8F"},
    {600, 0,   BTN_W, BTN_H, 9, "9F"},
    {700, 0,   BTN_W, BTN_H, 10, "10F"}
};

static int g_btn_state[FLOOR_COUNT] = {0};
static bmp_t *g_btn_bmp_unlit[FLOOR_COUNT];
static bmp_t *g_btn_bmp_lit[FLOOR_COUNT];

static int g_ad_index = 0;
static uint32_t g_last_ad_switch_ms = 0;

static pthread_mutex_t g_lcd_mutex = PTHREAD_MUTEX_INITIALIZER;

static void signal_handler(int sig) {
    if (sig == SIGINT || sig == SIGTERM) {
        printf("\n[MAIN] Received signal %d, exiting...\n", sig);
        g_running = 0;
    }
}

static void draw_background(void) {
    pthread_mutex_lock(&g_lcd_mutex);
    
    bmp_t *bg = bmp_get_cached("restore1.bmp");
    if (bg) {
        fb_fill_rect(0, 0, LCD_WIDTH, LCD_HEIGHT, 0x000000);
        fb_draw_bmp(0, 0, bg->data, bg->width, bg->height);
    }
    
    pthread_mutex_unlock(&g_lcd_mutex);
}

static void draw_ad(int index) {
    pthread_mutex_lock(&g_lcd_mutex);
    
    char path[32];
    sprintf(path, "ad%d.bmp", index + 1);
    
    bmp_t *ad = bmp_get_cached(path);
    if (ad) {
        fb_draw_bmp(0, 0, ad->data, ad->width, ad->height);
        fb_flush_rect(0, 0, ad->width, ad->height);
    }
    
    pthread_mutex_unlock(&g_lcd_mutex);
}

static void draw_floor(void) {
    pthread_mutex_lock(&g_lcd_mutex);
    
    char path[32];
    sprintf(path, "%d.bmp", elevator_get_current_floor());
    
    bmp_t *bmp = bmp_get_cached(path);
    if (bmp) {
        fb_draw_bmp(360, 110, bmp->data, bmp->width, bmp->height);
        fb_flush_rect(360, 110, bmp->width, bmp->height);
    }
    
    pthread_mutex_unlock(&g_lcd_mutex);
}

static void draw_button(int idx, int lit) {
    if (idx < 0 || idx >= FLOOR_COUNT) return;
    
    pthread_mutex_lock(&g_lcd_mutex);
    
    button_rect_t *btn = &g_buttons[idx];
    bmp_t *bmp = lit ? g_btn_bmp_lit[idx] : g_btn_bmp_unlit[idx];
    
    if (bmp) {
        fb_draw_bmp(btn->x, btn->y, bmp->data, bmp->width, bmp->height);
        fb_flush_rect(btn->x, btn->y, bmp->width, bmp->height);
    }
    
    pthread_mutex_unlock(&g_lcd_mutex);
}

static void draw_all_buttons(void) {
    for (int i = 0; i < FLOOR_COUNT; i++) {
        draw_button(i, g_btn_state[i]);
    }
}

static int find_button_by_coords(int x, int y) {
    for (int i = 0; i < FLOOR_COUNT; i++) {
        button_rect_t *btn = &g_buttons[i];
        if (x >= btn->x && x < btn->x + btn->w &&
            y >= btn->y && y < btn->y + btn->h) {
            return i;
        }
    }
    return -1;
}

static int is_in_ad_region(int x, int y) {
    return (x >= 0 && x < AD_WIDTH && y >= 0 && y < AD_HEIGHT);
}

static void switch_ad(void) {
    g_ad_index = (g_ad_index + 1) % AD_COUNT;
    draw_ad(g_ad_index);
    g_last_ad_switch_ms = touch_get_ms();
    LOG_INFO("Ad switched to: ad%d.bmp", g_ad_index + 1);
}

static int load_all_bmps(void) {
    if (bmp_load_all() != 0) {
        LOG_ERROR("Failed to initialize BMP cache");
        return -1;
    }
    
    char path[32];
    
    for (int i = 0; i < FLOOR_COUNT; i++) {
        sprintf(path, "%02d.bmp", i + 1);
        g_btn_bmp_unlit[i] = bmp_load(path);
        if (!g_btn_bmp_unlit[i]) {
            LOG_WARN("Failed to load %s", path);
        }
        
        sprintf(path, "%03d.bmp", i + 1);
        g_btn_bmp_lit[i] = bmp_load(path);
        if (!g_btn_bmp_lit[i]) {
            LOG_WARN("Failed to load %s", path);
        }
    }
    
    for (int i = 1; i <= 10; i++) {
        sprintf(path, "%d.bmp", i);
        if (!bmp_get_cached(path)) {
            bmp_t *bmp = bmp_load(path);
            (void)bmp;
        }
    }
    
    for (int i = 1; i <= AD_COUNT; i++) {
        sprintf(path, "ad%d.bmp", i);
        if (!bmp_get_cached(path)) {
            bmp_t *bmp = bmp_load(path);
            (void)bmp;
        }
    }
    
    return 0;
}

static void ui_init(void) {
    draw_background();
    
    draw_ad(0);
    g_last_ad_switch_ms = touch_get_ms();
    
    draw_floor();
    draw_all_buttons();
    
    fb_flush_screen();
}

static void run_main_loop(void) {
    touch_event_t ev;
    uint32_t last_time = 0;
    
    while (g_running) {
        uint32_t now_ms = touch_get_ms();
        
        while (touch_read_event(&ev)) {
            printf("[TOUCH] Screen coordinates: (%d, %d)\n", ev.x, ev.y);
            
            if (is_in_ad_region(ev.x, ev.y)) {
                printf("[TOUCH] Clicked AD region, switching ad\n");
                switch_ad();
            } else {
                int btn_idx = find_button_by_coords(ev.x, ev.y);
                if (btn_idx >= 0) {
                    int floor = g_buttons[btn_idx].floor;
                    printf("[TOUCH] Clicked button %d (floor %d)\n", btn_idx, floor);
                    
                    elevator_add_inner_request(floor);
                    
                    if (!g_btn_state[btn_idx]) {
                        printf("[TOUCH] Lighting button %d\n", btn_idx);
                        g_btn_state[btn_idx] = 1;
                        draw_button(btn_idx, 1);
                    } else {
                        printf("[TOUCH] Button %d already lit\n", btn_idx);
                    }
                } else {
                    printf("[TOUCH] Clicked outside button and ad regions\n");
                }
            }
        }
        
        if (now_ms - last_time >= 100) {
            elevator_process(now_ms);
            
            if (now_ms - g_last_ad_switch_ms >= AD_SWITCH_INTERVAL_MS) {
                switch_ad();
            }
            
            last_time = now_ms;
        }
        
        usleep(10000);
    }
}

int main(int argc, char *argv[]) {
    printf("===========================================\n");
    printf("  GEC6818 Elevator Control System v2.0\n");
    printf("  Screen: %dx%d\n", LCD_WIDTH, LCD_HEIGHT);
    printf("===========================================\n");
    
    signal(SIGINT, signal_handler);
    signal(SIGTERM, signal_handler);
    signal(SIGPIPE, SIG_IGN);
    
    if (fb_init() != 0) {
        LOG_ERROR("Framebuffer init failed");
        return -1;
    }
    
    if (touch_init() != 0) {
        LOG_ERROR("Touch init failed");
        fb_close();
        return -1;
    }
    
    if (load_all_bmps() != 0) {
        LOG_ERROR("BMP load failed");
        touch_close();
        fb_close();
        return -1;
    }
    
    elevator_init();
    debug_init();
    
    ui_init();
    
    LOG_INFO("System started successfully");
    LOG_INFO("Features: Inner request, outer call, arrival blink, door open");
    LOG_INFO("Ad region: (0,0) %dx%d, auto-switch every %ds", 
             AD_WIDTH, AD_HEIGHT, AD_SWITCH_INTERVAL_MS / 1000);
    LOG_INFO("Buttons: %d floors (1F-10F)", FLOOR_COUNT);
    
    run_main_loop();
    
    LOG_INFO("Shutting down...");
    
    bmp_cache_destroy();
    touch_close();
    fb_close();
    log_close();
    
    LOG_INFO("Goodbye!");
    return 0;
}