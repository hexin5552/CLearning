#ifndef TERM_H
#define TERM_H

/*
 * 终端工具函数集（框架代码，不要修改）
 * 当成黑盒使用即可。
 */

void term_enter_raw(void);
void term_leave_raw(void);

void clear_screen(void);

void move_cursor(int row, int col);
void hide_cursor(void);
void show_cursor(void);

int kbhit(void);
int getch_nb(void);

void sleep_ms(int ms);

#endif
