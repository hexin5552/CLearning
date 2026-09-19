/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
double script(double d);
int main(void) {
    double dl = 12;
    printf("%.2f",script(dl));
}

double script(double d) {
    return d * d * d;
}