/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
double average(double, double);
int main(void) {
    printf("%.2lf", average(1.0, 2.0));
    return 0;
}

double average(double d1, double d2) {
    d1 = 1 / d1;
    d2 = 1 / d2;
    return  1 / ((d1 + d2) / 2);

}