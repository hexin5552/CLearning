/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#define SIZE 8
long format(int n);
int main(void) {
    int by_two[SIZE];
    int index;

    for (index = 0; index <= SIZE; index++)
        by_two[index] = 2 * index;
    for (index = 0; index <= SIZE; index++)
        printf("%d|", by_two[index]);
    printf("\n");

    return 0;
}

long format(int n) {
    return n * n;
}