/**
* @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#define MONTH 12
#define YEARS 5
int main(void) {
    const float rain[YEARS][MONTH] = {
        { 4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6 },
        { 8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3 },
        { 9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4 },
        { 7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2 },
        { 7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2 }
    };
    int year, month;
    float subot, total;
    const float *pt = &rain[0][0];
    for (total = 0, year = 0; year < YEARS; year++) {
        for (subot = 0, month = 0; month < MONTH; month++)
            subot += *pt++;
        printf("%5d %15.1f\n", 2010 + year, subot);
        total += subot;
    }
    printf("\nThe yearly average is %.1f inches.\n\n", total / YEARS);
    printf("MONTHLY AVERAGES:\n\n");
    printf(" Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct  Nov  Dec\n");
    printf("\n");
    pt = &rain[0][0];
    for (total = 0, month = 0; month < MONTH; month++) {
        for (year = 0, subot = 0; year < YEARS; year++)
            subot += *pt++;
        printf("%4.1f ", subot / YEARS);
    }
    printf("\n");
    return 0;
}
/*
函数调用参数必须完整匹配
调用函数时，实参的数量、类型和顺序必须与形参严格一致。漏传参数会导致未定义行为。

指针类型决定解引用结果的类型
若指针指向数组（如 int (*p)[10]），解引用得到的是整个数组，不能直接与元素类型的变量进行算术运算或赋值。必须逐层解引用或使用正确的指针类型（如 int * 指向元素）。

累加变量在每次循环前重置
计算多个批次的和时，每个批次开始前应将累加变量清零，否则会把上一批次的结果带入当前批次。

遍历结束后指针不会自动复位
用一个指针遍历完数组后，它指向末尾之后的位置。若需再次遍历同一数组，必须重新将指针指向数组开头（或改用下标访问，更安全）。

优先使用数组下标而非指针算术
除非有明确的性能需求或指针练习目的，使用 arr[i][j] 比手动管理 ptr++ 更直观且不易越界。
 */