/*
 * 终端工具函数实现（框架代码，不要修改）
 * 依赖：POSIX termios + ANSI 转义序列
 */

#include "tools/term.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>
#include <sys/time.h>
#include <termios.h>
#include <unistd.h>

static struct termios g_orig_termios;
static int g_orig_saved = 0;
static int g_raw_active = 0;
static int g_atexit_registered = 0;
static int g_sigint_installed = 0;

/* 保存原始终端设置，避免重复读取。 */
static void save_original_once(void) {
  if (g_orig_saved)
    return;
  tcgetattr(STDIN_FILENO, &g_orig_termios);
  g_orig_saved = 1;
}

/* 程序退出时恢复终端模式并显示光标。 */
static void cleanup_on_exit(void) {
  if (g_raw_active)
    term_leave_raw();
  show_cursor();
}

/* SIGINT 兜底：默认 SIGINT 会直接终止进程，atexit 注册的清理不一定运行；
 * 我们把它改成走 exit() 路径，这样 cleanup_on_exit 一定会被调到，
 * 终端不会被遗留在 raw 模式 + 光标隐藏的状态里。
 * 退出码 130 是约定俗成的 "128 + SIGINT(2)"。 */
/* 捕获 Ctrl-C 并通过 exit() 触发终端清理。 */
static void on_sigint(int sig) {
  (void)sig;
  exit(130);
}

/* 进入非规范、无回显的 raw 输入模式。 */
void term_enter_raw(void) {
  if (g_raw_active)
    return;
  save_original_once();

  struct termios raw = g_orig_termios;
  raw.c_lflag &= ~(ICANON | ECHO);
  raw.c_cc[VMIN] = 0;
  raw.c_cc[VTIME] = 0;
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
  g_raw_active = 1;

  if (!g_atexit_registered) {
    atexit(cleanup_on_exit);
    g_atexit_registered = 1;
  }
  if (!g_sigint_installed) {
    signal(SIGINT, on_sigint);
    g_sigint_installed = 1;
  }
}

/* 离开 raw 输入模式并恢复原始终端设置。 */
void term_leave_raw(void) {
  if (!g_raw_active)
    return;
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &g_orig_termios);
  g_raw_active = 0;
}

/* 清空终端屏幕并把光标移动到左上角。 */
void clear_screen(void) {
  printf("\033[2J\033[H");
  fflush(stdout);
}

/* 将光标移动到指定的终端行列位置。 */
void move_cursor(int row, int col) {
  printf("\033[%d;%dH", row, col);
  fflush(stdout);
}

/* 隐藏终端光标。 */
void hide_cursor(void) {
  printf("\033[?25l");
  fflush(stdout);
}

/* 显示终端光标。 */
void show_cursor(void) {
  printf("\033[?25h");
  fflush(stdout);
}

/* 检查标准输入是否已有可读取的按键数据。 */
int kbhit(void) {
  fd_set rfds;
  struct timeval tv;
  FD_ZERO(&rfds);
  FD_SET(STDIN_FILENO, &rfds);
  tv.tv_sec = 0;
  tv.tv_usec = 0;
  int r = select(STDIN_FILENO + 1, &rfds, NULL, NULL, &tv);
  return r > 0 && FD_ISSET(STDIN_FILENO, &rfds);
}

/* 非阻塞读取一个按键，没有输入时返回 -1。 */
int getch_nb(void) {
  if (!kbhit())
    return -1;
  unsigned char c;
  ssize_t n = read(STDIN_FILENO, &c, 1);
  return (n == 1) ? (int)c : -1;
}

/* 按指定毫秒数暂停当前线程。 */
void sleep_ms(int ms) {
  if (ms <= 0)
    return;
  usleep((useconds_t)ms * 1000);
}
