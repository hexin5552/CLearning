/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#define SIZE 4
int main(void) {
    short dates[SIZE];
    short * pti;
    short index;
    double bills[SIZE];
    double * ptf;
    pti = &dates[0];
    ptf = &bills[0];
    printf("%23s %15s\n", "short", "double");
    for (index = 0; index < SIZE; index++)
        printf("pointers + %d: %11p %15p\n", index, pti + index, ptf + index);
    return 0;
}