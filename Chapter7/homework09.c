/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>

int main(void) {
    unsigned int n, i, j;
    int isPrime;
    printf("Please enter an integer, only support unsigned int:\n");
    scanf("%u", &n);
    for (i = 2; i <= n; i++) {
        isPrime = 1;
        for (j = 2; j < i; j++) {
            if (i % j == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime == 1)
            printf("%d ", i);
    }
    printf("is prime\n");
    return 0;
}
