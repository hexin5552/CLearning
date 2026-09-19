/**
* @author Hexin
 * @version 1.0
 */
#include <stdio.h>

double power(double n, int p);

int main(void) {
    double x, xpow;
    int exp;

    printf("Enter a number and the positive integer power to which\nthe number will be raised. Enter q to quit.\n");

    while (scanf("%lf%d", &x, &exp) == 2) {
        xpow = power(x, exp);
        if (xpow == -1) {
            printf("%.3g to the power %d is not define.\n", x, exp);
            continue;
        }
        printf("%.3g to the power %d is %.5g\n", x, exp, xpow);
        printf("Enter next pair of numbers or q to quit.\n");
    }
    printf("Hope you enjoyed this power trip -- bye!\n");

    return 0;
}

double power(double n, int p) {
    double pow = 1;
    if (n == 0 && p == 0)
        return -1;
    if (n == 0 && p < 0)
        return -1;
    if (p == 0)
        return 1;
    int ne = p > 0 ? p : -p;
    pow = n * power(n, ne - 1);

    if (p < 0)
        pow = 1.0 / pow;
    return pow;
}
