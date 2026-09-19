/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#define PR(X, ...) printf("Message " #X ": " __VA_ARGS__)
#include <math.h>
int main(void) {
    double x = 48;
    double y;
    y = sqrt(x);
    PR(1, "x = %g\n", x);
    PR(2, "x = %.2f, y = %.4f\n", x, y);
    return 0;
}