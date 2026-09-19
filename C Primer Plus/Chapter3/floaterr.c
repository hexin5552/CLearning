/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
int main(void) {
    float a,b;

    b = 2.0e20 + 1.0;
    a = b - 2.0e20;
    printf("a = %f\n", a);
    return 0;
}