#include "timer.h"
#include "display.h"
#include "tools/color.h"
#include "tools/term.h"
#include <stdio.h>
#include <time.h>

void timer_countdown(void);

/* ---- 框架代码（不要修改） ---- */

/* 把秒数格式化成 "HH:MM:SS" */
static void format_hms(int total_sec, char *buf, int bufsize) {
    int h = total_sec / 3600;
    int m = (total_sec % 3600) / 60;
    int s = total_sec % 60;
    snprintf(buf, bufsize, "%02d:%02d:%02d", h, m, s);
}

/* 画一帧计时器界面（清屏后重画） */
static void draw_frame(const char *description, const char *timebuf) {
    clear_screen();
    move_cursor(2, 4);
    printf(C_CYAN "+--------------------------------------+" C_RESET);
    move_cursor(4, 4);
    printf("  " C_CYAN "Focusing：" C_RESET C_BOLD "%s" C_RESET, description);
    move_cursor(7, 4);
    printf("           " C_BOLD C_B_GREEN "%s" C_RESET, timebuf);
    move_cursor(10, 4);
    printf("  " DIM("[ press q to quit ]"));
    move_cursor(12, 4);
    printf(C_CYAN "+--------------------------------------+" C_RESET);
    fflush(stdout);
}

/* ---- 请将下面的函数实现完整 ---- */
void timer_countdown(void) {
    printf(C_CYAN "Are you ready? \n" C_RESET);
    for (int i = 3; i >= 1; i--) {
        printf(C_YELLOW "%d...\n" C_RESET, i);
        fflush(stdout); //立即输出，防止缓存
        sleep_ms(1000);
    }
    clear_screen();
}

int timer_run(const char *description) {
    term_enter_raw();
    hide_cursor();

    time_t start = time(NULL);
    int last_sec = -1;
    char timebuf[16];
    while (1) {
        int elapsed = (int) (time(NULL) - start);

        if (elapsed != last_sec) {
            format_hms(elapsed, timebuf, sizeof(timebuf));

            if (g_fancy_display)
                //选作扩展：大字显示若实现了display.c则可以调用display_draw_timer(description, timebuf);
                display_draw_timer(description, timebuf);
            else
                draw_frame(description, timebuf);

            last_sec = elapsed;
        }

        int ch = getch_nb();
        if (ch == 'q')
            break;

        sleep_ms(80);
    }

    show_cursor();
    term_leave_raw();
    return (int) (time(NULL) - start);
}
