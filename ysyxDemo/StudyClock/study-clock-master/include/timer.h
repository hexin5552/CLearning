#ifndef TIMER_H
#define TIMER_H

/* "准备好开始了吗？3...2...1..." 倒数动画 */
void timer_countdown(void);

/* 启动正计时器；按 q 退出；返回总用时（秒） */
int timer_run(const char *description);

/* 选做扩展：大字体显示开关（--fancy 命令行参数控制） */
extern int g_fancy_display;

#endif
