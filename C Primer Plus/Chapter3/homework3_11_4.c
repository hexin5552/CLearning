/**
 * @author Hexin
 * @version 1.0
 */
#include<stdio.h>
int main(void) {
    float a;
    printf("Enter a floating point number: ");
    scanf("%f", &a);
    printf("fixed-point notation: %f\n", a);
    printf("exponential notation: %e\n", a);
    printf("p notation: %a\n", a);
}