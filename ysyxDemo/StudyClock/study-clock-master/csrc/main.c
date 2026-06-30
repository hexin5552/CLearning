#include "record.h"
#include "storage.h"
#include "timer.h"
#include "tools/color.h"
#include "tools/term.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../include/storage.h"
#include "../include/tools/color.h"

int g_fancy_display = 0;

#define LOOKBACK_DAYS 7
#define QUOTE_BUF_SIZE 512

/* 提示符（带颜色）；用于所有 read_line 调用 */
#define PROMPT C_CYAN "> " C_RESET

/* ---- 框架代码（不要修改） ---- */

typedef enum {
    STATE_GREETING,
    STATE_COLLECT_TODAY,
    STATE_MENU,
    STATE_TIMER_DESC,
    STATE_TIMER_RUN,
    STATE_EXIT
} AppState;

typedef struct {
    Record *records;
    int today_y, today_m, today_d;
    int back_y, back_m, back_d;
    char timer_desc[RECORD_CONTENT_MAX];
    AppState state;
} App;

typedef enum { READ_EOF, READ_OK, READ_TRUNCATED } ReadLineResult;

/* 丢弃当前行中 fgets 没读完的剩余内容（被 read_line 调用） */
static void discard_line_rest(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
    }
}

static void compute_dates(App *app);

static ReadLineResult read_line(const char *prompt, char *buf, int bufsize);

static void sanitize(char *s);

static AppState handle_greeting(App *app);

static AppState handle_collect_today(App *app);

static AppState handle_menu(App *app);

static AppState handle_timer_desc(App *app);

static AppState handle_timer_run(App *app);

/* ---- 主入口（框架代码，不要修改） ---- */

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--fancy") == 0)
            g_fancy_display = 1;
    }
    srand((unsigned) time(NULL));

    App app;
    memset(&app, 0, sizeof(app));

    /* INIT */
    app.records = storage_load(STORAGE_FILE);
    compute_dates(&app);
    app.state = STATE_GREETING;

    /* 主循环：switch 状态机 */
    while (app.state != STATE_EXIT) {
        switch (app.state) {
            case STATE_GREETING:
                app.state = handle_greeting(&app);
                break;
            case STATE_COLLECT_TODAY:
                app.state = handle_collect_today(&app);
                break;
            case STATE_MENU:
                app.state = handle_menu(&app);
                break;
            case STATE_TIMER_DESC:
                app.state = handle_timer_desc(&app);
                break;
            case STATE_TIMER_RUN:
                app.state = handle_timer_run(&app);
                break;
            default:
                app.state = STATE_EXIT;
                break;
        }
    }

    printf(BGREEN("Bye. Keep cheering.") "\n");
    record_free_all(app.records);
    return 0;
}

/* ---- 请将下面的函数实现完整 ---- */
static void compute_dates(App *app) {
    /* 在这里实现
     * tips:
     *  - tm_year 是从1900年至今的时间
     *  - 为了索引实现的便利性，tm_mon被设计为从0开始
     *
     * 更多信息参阅 man localtime
     * */
    time_t now = time(NULL);
    struct tm *tm_now = localtime(&now);
    app->today_y = tm_now->tm_year + 1900;
    app->today_m = tm_now->tm_mon + 1;
    app->today_d = tm_now->tm_mday;

    time_t back = now - LOOKBACK_DAYS * 24 * 3600;
    struct tm *tm_back = localtime(&back);
    app->back_y = tm_back->tm_year + 1900;
    app->back_m = tm_back->tm_mon + 1;
    app->back_d = tm_back->tm_mday;
}

static ReadLineResult read_line(const char *prompt, char *buf, int bufsize) {
    printf("%s", prompt);
    fflush(stdout);
    if (fgets(buf, bufsize, stdin) == NULL)
        return READ_EOF;

    char *nl = strchr(buf, '\n');
    if (nl != NULL) {
        *nl = '\0';
        return READ_OK;
    } else {
        //输入太长，丢弃剩余
        discard_line_rest();
        return READ_TRUNCATED;
    }
}

static void sanitize(char *s) {
    /*
     * 在这里实现
     * 清理用户输入里的 '|'
     * 把 '|' 替换成空格，避免破坏文件格式
     * */
    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] == '|')
            s[i] = ' ';
}

static AppState handle_greeting(App *app) {
    clear_screen();
    printf(C_CYAN "========== Welcome! ==========\n" C_RESET);

    int found = 0;
    Record *cur = app->records;
    while (cur != NULL) {
        if (record_match_date(cur, app->back_y, app->back_m, app->back_d)) {
            printf(C_YELLOW " %04d-%02d-%02d: %s\n" C_RESET, cur->year, cur->month, cur->day, cur->content);
            found = 1;
        }
        cur = cur->next;
    }

    if (!found) {
        char quote[QUOTE_BUF_SIZE];
        if (storage_random_quote(QUOTES_FILE, quote, sizeof(quote)) == 0) {
            printf(C_GREEN " Famous quote of the day: %s\n" C_RESET, quote);
        } else
            printf(C_GREEN " Today is without records from yesterday, but you can make a record today! \n" C_RESET);
    }

    printf("\n");
    return STATE_COLLECT_TODAY;
}

static AppState handle_collect_today(App *app) {
    char buf[RECORD_CONTENT_MAX];
    ReadLineResult res = read_line("What did you learn today? ", buf, sizeof(buf));
    if (res == READ_EOF)
        return STATE_EXIT;

    if (buf[0] != '\0') {
        sanitize(buf);
        Record *r = record_new(app->today_y, app->today_m, app->today_d, buf);
        if (r != NULL) {
            record_append(&app->records, r);
            if (storage_append_one(STORAGE_FILE, r) != 0)
                fprintf(stderr, "Warining: Fail to append records to files\n");
        }
    }

    return STATE_MENU;
}

static AppState handle_menu(App *app) {
    (void)app;
    printf("\n");
    printf("1. " C_CYAN "Start timing" C_RESET "\n");
    printf("2. " C_CYAN "Record one more item" C_RESET "\n");
    printf("q. " C_CYAN "Exit" C_RESET "\n");

    char buf[2];
    ReadLineResult res = read_line("Please select (1/2/q): ", buf, sizeof(buf));
    if (res == READ_EOF)
        return STATE_EXIT;

    if (buf[0] == '1')
        return STATE_TIMER_DESC;
    else if (buf[0] == '2')
        return STATE_COLLECT_TODAY;
    else if (buf[0] == 'q' || buf[0] == 'Q')
        return STATE_EXIT;
    else
        return STATE_MENU;
}

static AppState handle_timer_desc(App *app) {
    char buf[RECORD_CONTENT_MAX];
    ReadLineResult res = read_line("What need to be focused on today? ", buf, sizeof(buf));
    if (res == READ_EOF)
        return STATE_EXIT;

    if (buf[0] != '\0') {
        strncpy(app->timer_desc, buf, sizeof(app->timer_desc) - 1);
        app->timer_desc[sizeof(app->timer_desc) - 1] = '\0';
    } else
        strcpy(app->timer_desc, "Focusing...");

    return STATE_TIMER_RUN;
}

static AppState handle_timer_run(App *app) {
    timer_countdown();
    int total_sec = timer_run(app->timer_desc);

    int h = total_sec / 3600;
    int m = (total_sec % 3600) / 60;
    int s = total_sec % 60;

    printf(C_YELLOW " Focus for %d h %d m %d s " C_RESET "\n", h, m, s);
    printf("Press Enter to continue...");
    fflush(stdout);
    getchar(); //等待用户按回车，避免直接跳到菜单看不清楚

    return STATE_MENU;
}
