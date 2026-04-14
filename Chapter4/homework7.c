/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#include <float.h>

int main(void) {
    double num = 1.0 / 3.0;
    float num1 = 1.0 / 3.0;

    printf("%.6f %.6f\n",num,num1);
    printf("%.12f %.12f\n",num,num1);
    printf("%.16f %.16f\n",num,num1);
    printf("%f %f\n",FLT_DIG,DBL_DIG);
}