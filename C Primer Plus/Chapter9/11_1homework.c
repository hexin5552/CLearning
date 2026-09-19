/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>

double minNum(double, double);
int main(void) {
    printf("%.2lf", minNum(102.7,31.2));
    return 0;
}
double minNum(double x, double y) {
    return x < y ? x : y;
}