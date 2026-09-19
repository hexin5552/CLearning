/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
char *pr(char *str);
int main(void) {
    char *x = pr("Ho Ho Ho!");
    //a、将打印什么?
    //Ho Ho Ho!!oH oH oH
    //b、x是指针类型
    //c、x = H
    //d、*--pc是指针向左移动一次，--*pc是把指针指向的值-1
    //e、第一次会打印空字符（不可见），然后 pc 移到最后一个
    //有效字符，后续逆序打印会少打印最前面的字符，并且最终
    //pc 会越界（访问 str-1），导致未定义行为。
    //f、2个while循环测试正向打印和逆向打印
    char *y = pr(" ");
    //g、第一个循环不执行（*pc 为 '\0'），pc 仍指向 '\0'。
    //进入 do-while 后，*--pc 会使 pc 移到 str-1，
    //访问越界内存并打印未知字符，随后循环继续递减直
    //到程序崩溃或产生不可预知的结果——未定义行为。
    //h、必传入一个非空的有效字符串
    return 0;
}
char *pr(char *str) {
    char *pc;

    pc = str;
    while (*pc)
        putchar(*pc++);

    do {
        putchar(*--pc);
    }while (pc - str);
    return pc;
}