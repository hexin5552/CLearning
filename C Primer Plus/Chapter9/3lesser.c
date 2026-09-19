/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
int imin(int, int);
int main(void) {
    int evil1, evil2;
    printf("Enter a pair of integer (q to quit):\n");
    while (scanf("%d %d", &evil1, &evil2) == 2) {
        printf("The lesser of %d and %d is %d.\n", evil1, evil2, imin(evil1, evil2));
        printf("Enter a pair of integer (q to quit):\n");
    }
    printf("Bye.\n");
    return 0;
}

int imin(int m, int n) {
    int min;

    return m > n ? n : m;
}