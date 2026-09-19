/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
void largeOf(double *, double *);
int main(void) {
    double x = 3.88, y = 12.13;
    printf("Originally, x = %.2lf, y = %.2lf\n", x, y);
    largeOf(&x, &y);
    printf("Now, x = %.2lf, y = %.2lf", x, y);
    return 0;
}

void largeOf(double  *d1, double *d2) {
    double maxVal = *d1 > *d2 ? *d1 : *d2;

    *d1 = maxVal;
    *d2 = maxVal;
}