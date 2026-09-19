/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
void changNum(double *, double *, double *);
int main(void) {
    double a = 10.9, b = 23.7, c = 17.8;
    printf("Originally, a = %.2lf, b = %.2lf, c = %.2lf\n", a, b, c);
    changNum(&a, &b, &c);
    printf("Now, a = %.2lf, b = %.2lf, c = %.2lf\n", a, b, c);
    return 0;
}
void changNum(double * num1, double *num2, double *num3) {
    double temp;
    if (*num1 > *num2) {
        temp = *num1;
        *num1 = *num2;
        *num2 = temp;
    }
    if (*num1 > *num2) {
        temp = *num1;
        *num1 = *num3;
        *num3 = temp;
    }
    if (*num2 > *num3) {
        temp = *num2;
        *num2 = *num3;
        *num3 = temp;
    }
}
