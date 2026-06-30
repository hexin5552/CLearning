/**
 * @author Hexin
 * @version 1.0
 */
#include<stdio.h>
int main(void) {
    double height_inch;
    double height_cm;
    printf("Enter your height: ");
    scanf("%lf", &height_inch);
    height_cm = height_inch * 2.54;
    printf("Your height is %lf cm", height_cm);
}