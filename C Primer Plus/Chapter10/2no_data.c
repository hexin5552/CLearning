/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#define SIZE 4
int main(void) {
    int noData [SIZE];
    int i;
    printf("%2s%14s\n", "i", "noData[i]");
    for (i = 0; i < SIZE; i++)
        printf("%2d%14d\n", i, noData[i]);
    return 0;
}