#include "display.h"
#include "tools/color.h"
#include "tools/term.h"
#include <stdio.h>
#include <string.h>

#include "../include/tools/color.h"

#define FILL_BLOCK "██"
#define EMPTY_BLOCK "  "
#define DIGIT_WIDTH 6
#define DIGIT_SPACE 2
#define COLON_WIDTH 2
#define COLON_SPACE 2

/* 选做 TODO: 实现 display_draw_timer
 *
 * 思路：
 *   1. 定义 FONT[10][5][3] 三维数组，存储 0–9 的 5×3 像素字模
 *      （1 = 填充，0 = 空白）
 *
 *      例如数字 "2" 的字模：
 *        ███     {1,1,1}
 *          █     {0,0,1}
 *        ███ =>  {1,1,1}
 *        █       {1,0,0}
 *        ███     {1,1,1}
 *
 *   2. 定义 COLON[5] 一维数组，存储冒号的字模（第 1、3 行有点）
 *
 *   3. 写 draw_digit(row, col, digit)：
 *      嵌套循环遍历 FONT[digit]，
 *      在 (row+r, col+c*2) 处打印 "██"（填充）或 "  "（空白）
 *
 *   4. 写 draw_colon(row, col)：类似，只有一列
 *
 *   5. 在本函数中：
 *      - clear_screen()
 *      - 画边框和描述文字
 *      - 逐字符解析 timebuf ("HH:MM:SS")
 *      - 遇到数字调 draw_digit，遇到 ':' 调 draw_colon
 *      - 画操作提示
 *
 *   启用方式：./build/study-clock --fancy
 */
static const int FONT[10][5][3] = {
    //0
    {
        {1, 1, 1},
        {1, 0, 1},
        {1, 0, 1},
        {1, 0, 1},
        {1, 1, 1}
    },
    //1
    {
        {0, 1, 0},
        {1, 1, 0},
        {0, 1, 0},
        {0, 1, 0},
        {1, 1, 1}
    },
    //2
    {
        {1, 1, 1},
        {0, 0, 1},
        {1, 1, 1},
        {1, 0, 0},
        {1, 1, 1}
    },
    //3
    {
        {1, 1, 1},
        {0, 0, 1},
        {1, 1, 1},
        {0, 0, 1},
        {1, 1, 1}
    },
    //4
    {
        {1, 0, 1},
        {1, 0, 1},
        {1, 1, 1},
        {0, 0, 1},
        {0, 0, 1}
    },
    // 5
    {
        {1, 1, 1},
        {1, 0, 0},
        {1, 1, 1},
        {0, 0, 1},
        {1, 1, 1}
    },
    // 6
    {
        {1, 1, 1},
        {1, 0, 0},
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    },
    // 7
    {
        {1, 1, 1},
        {0, 0, 1},
        {0, 0, 1},
        {0, 0, 1},
        {0, 0, 1}
    },
    // 8
    {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    },
    // 9
    {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1},
        {0, 0, 1},
        {1, 1, 1}
    }
};
static const int COLON[5] = {0, 1, 0, 1, 0};

static void draw_digit(int row, int col, int digit) {
    for (int r = 0; r < 5; r++) {
        move_cursor(row + r, col);
        for (int c = 0; c < 3; c++)
            if (FONT[digit][r][c])
                printf(FILL_BLOCK);
            else
                printf(EMPTY_BLOCK);
    }
}

static void draw_colon(int row, int col) {
    for (int r = 0; r < 5; r++) {
        move_cursor(row + r, col);
        if (COLON[r])
            printf(FILL_BLOCK);
        else
            printf(EMPTY_BLOCK);
    }
}

void display_draw_timer(const char *description, const char *timebuf) {
    clear_screen();
    /* 画边框和标题 */
    move_cursor(2, 4);
    printf(C_CYAN "+------------------------------------------+" C_RESET);
    move_cursor(4, 4);
    printf(" " C_CYAN "Focusing: " C_RESET C_BOLD "%s" C_RESET, description);
    /* 绘制时间：第7行开始，居中显示 */
    int start_row = 7;
    int start_col = 8;

    int len = strlen(timebuf);
    int col_offset = start_col;
    for (int i = 0; i < len; i++)
        if (timebuf[i] >= '0' && timebuf[i] <= '9') {
            draw_digit(start_row, col_offset, timebuf[i] - '0');
            col_offset += DIGIT_WIDTH + DIGIT_SPACE; //每个数字占3列 2字符宽，加一个间隔（空2列）
        } else if (timebuf[i] == ':') {
            draw_colon(start_row, col_offset + 1);
            col_offset += COLON_WIDTH + COLON_SPACE;
        }

    /* 底部显示 */
    move_cursor(15, 4);
    printf(" " DIM("[ Press q to quit ]"));
    move_cursor(17, 4);
    printf(C_CYAN "+------------------------------------------+" C_RESET);

    fflush(stdout);
}
