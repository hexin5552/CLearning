/**
* @author Hexin
 * @version 1.0
 */
#include <stdio.h>

double f1(void);

int main(void) {
    f1();


    return 0;
}

double f1(void) {
    double d1, d2;
    while (scanf("%lf %lf", &d1, &d2) == 2)
        printf("%lf\n", (d1 - d2) / (d1 * d2));
}