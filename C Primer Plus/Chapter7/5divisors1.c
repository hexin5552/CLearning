/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
int main(void) {
    long num;
    printf("Please enter a digit:");
    scanf("%ld", &num);
    for (int div = 2; div * div <= num; div++) {
        if (num % div == 0) {
            if (div * div != num)
                printf("%d is divisible by %d and %d.\n", num, div, num / div);
            else
                printf("%d is divisible by %d.\n", num, div);
        }
    }
    return 0;
}