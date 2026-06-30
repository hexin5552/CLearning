/**
* @author Hexin
 * @version 1.0
*/
#include <stdio.h>
#include <string.h>
#define NAME "GIGATHINK, INC"
#define ADDRESS "101 Megabuck Plaza"
#define PLACE "Megapolics, CA 94904"
#define WIDTH 40
#define SPACE ' '

void show_n_char(char ch, int num);

int main(void) {
    int spaces;

    // 第一行：************************
    show_n_char('*', WIDTH);
    putchar('\n');

    // 公司名（居中）
    show_n_char(SPACE, 12);
    printf("%s\n", NAME);

    // 地址（居中）
    spaces = (WIDTH - strlen(ADDRESS)) / 2;
    show_n_char(SPACE, spaces);
    printf("%s\n", ADDRESS);

    // 地点（必须重新居中！！！）
    spaces = (WIDTH - strlen(PLACE)) / 2;
    show_n_char(SPACE, spaces);
    printf("%s\n", PLACE);

    // 最后一行
    show_n_char('*', WIDTH);
    putchar('\n');

    return 0;
}

// 打印字符函数（正确）
void show_n_char(char ch, int num) {
    for (int count = 0; count < num; count++)
        putchar(ch);
}