/**
* @author Hexin
 * @version 1.0
 */
#include <stdio.h>

void toBaseN(unsigned long, int);

int main(void) {
    unsigned long n;
    int d;
    printf("Enter 2 integers (q to quit):\n");
    while (scanf("%lu%d", &n, &d) == 2) {
        printf("base-%d equivalent: ", d);
        toBaseN(n, d);
        putchar('\n');
        printf("Enter 2 integers (q to quit):\n");
    }
    printf("Done");
    return 0;
}

void toBaseN(unsigned long n, int i) {
    if (n == 0) {
        if (i < 2)
            printf("Undefine Behavior.\n");
        else if (i > 0) // 当 n 一开始就是 0 时，直接输出 '0'
            putchar('0');
        return;
    }
    if (n >= i)
        toBaseN(n / i, i);
    /*
    输出字符时直接使用余数，而不是对应的数字字符
    putchar(r);   // r 是 0 ~ i-1 的整数，putchar 期望的是 ASCII 字符
    当 r = 0 时，putchar(0) 输出空字符（不可见）；当 r = 1 时，输出 ASCII
    码为 1 的字符（SOH），而不是字符 '1'。对于十六进制中的 10（即 A）等也无法正确输出。
    正确写法：将余数转换为对应的字符（支持 2~36 进制）：     */
    int r = n % i;
    char c = (r < 10) ? ('0' + r) : ('A' + (r - 10));
    putchar(c);
}
