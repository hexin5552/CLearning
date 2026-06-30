/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#define SIZE 4
int main(void) {
    int someData[SIZE] = {100, 201};
    int i;
    printf("%2s%14s\n", "i", "someData[i]");
    for (i = 0; i < SIZE; i++)
        printf("%2d%14d\n", i, someData[i]);
    return 0;
}