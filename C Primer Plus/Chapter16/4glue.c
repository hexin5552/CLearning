/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#define XNAME(n) x ## n
#define PRINTZ_XN(n) printf("x" #n " = %d\n", x ## n);
int main(void) {
    int XNAME(1) = 14;
    int XNAME(2) = 20;
    int x3 = 30;
    PRINTZ_XN(1);
    PRINTZ_XN(2);
    PRINTZ_XN(3);
    return 0;
}