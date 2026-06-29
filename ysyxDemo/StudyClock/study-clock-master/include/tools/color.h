#ifndef COLOR_H
#define COLOR_H

/*
 * ANSI 颜色宏
 * ANSI 转义序列格式：\033[<参数>m
 *   0      重置
 *   1      粗体
 *   2      暗淡
 *   30-37  前景色（黑红绿黄蓝紫青白）
 *   90-97  加亮前景色
 *
 * 两种用法：
 *
 *   1) "前缀 + 重置" 风格，适合带 %d/%s 等格式说明的字符串
 *        printf(C_RED "出错：%d" C_RESET "\n", code);
 *
 *   2) "包裹宏" 风格，适合纯字面值
 *        printf(GREEN("已记下") "\n");
 *
 *   两种风格都依赖一站式 Ch2.1 提到的规则：
 *   相邻字符串字面值会在编译期被自动拼成一条。
 */

#define C_RESET "\033[0m"
#define C_BOLD "\033[1m"
#define C_DIM "\033[2m"
#define C_ITALIC "\033[3m"
#define C_UNDER "\033[4m"

#define C_BLACK "\033[30m"
#define C_RED "\033[31m"
#define C_GREEN "\033[32m"
#define C_YELLOW "\033[33m"
#define C_BLUE "\033[34m"
#define C_MAGENTA "\033[35m"
#define C_CYAN "\033[36m"
#define C_WHITE "\033[37m"

#define C_B_RED "\033[91m"
#define C_B_GREEN "\033[92m"
#define C_B_YELLOW "\033[93m"
#define C_B_BLUE "\033[94m"
#define C_B_MAGENTA "\033[95m"
#define C_B_CYAN "\033[96m"
#define C_B_WHITE "\033[97m"

#define BOLD(s) C_BOLD s C_RESET
#define DIM(s) C_DIM s C_RESET
#define RED(s) C_RED s C_RESET
#define GREEN(s) C_GREEN s C_RESET
#define YELLOW(s) C_YELLOW s C_RESET
#define BLUE(s) C_BLUE s C_RESET
#define MAGENTA(s) C_MAGENTA s C_RESET
#define CYAN(s) C_CYAN s C_RESET

#define BRED(s) C_BOLD C_RED s C_RESET
#define BGREEN(s) C_BOLD C_GREEN s C_RESET
#define BYELLOW(s) C_BOLD C_YELLOW s C_RESET
#define BCYAN(s) C_BOLD C_CYAN s C_RESET
#define BMAGENTA(s) C_BOLD C_MAGENTA s C_RESET

#endif
