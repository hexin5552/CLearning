/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>

int main(void) {
    double d1, d2;
    while (scanf("%lf %lf", &d1, &d2) == 2)
        printf("%lf", (d1 - d2) / (d1 * d2));

    return 0;
}
