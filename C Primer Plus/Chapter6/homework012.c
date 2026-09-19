/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
int main(void) {
    double d1, d2;
    long int count, sign = 1;

    scanf("%ld", &count);
    for (int i = 1; i < count; i++) {
        d1 += 1.0 / i;
        d2 += sign * (1.0 / i);
        sign = -sign;
    }
    printf("d1 = %lf, d2 = %lf", d1, d2);

    return 0;
}