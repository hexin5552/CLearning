/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>

int Fibonacci(unsigned long long);

int fibonacci(unsigned long long);

int main(void) {
    int res = Fibonacci(9);
    int res1 = fibonacci(9);
    printf("%d\n", res);
    printf("%d", res1);
    return 0;
}

int Fibonacci(unsigned long long i1) {
    //递归法
    if (i1 == 0)
        return 0;
    else if (i1 <= 1)
        return 1;
    else if (i1 >= 2) {
        return Fibonacci(i1 - 1) + Fibonacci(i1 - 2);
    }
}

int fibonacci(unsigned long long i1) {
    if (i1 == 0)
        return 0;
    else if (i1 <= 1)
        return 1;
    int first = 0;
    int second = 1;
    for (int i = 2; i <= i1; i++) {
        int next = first + second;
        first = second;
        second = next;
    }
    return second;
}