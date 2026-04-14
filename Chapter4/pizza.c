/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#define PI 3.14159
int main(void) {
    float area, circum, radius;

    printf("What is the radius of your pizza?\n");
    scanf("%f", &radius);
    area = PI * radius * radius;
    circum = 2.0 * PI * radius;
    printf("Your basic pizza parameters are as follows:\n");
    printf("circumference = %.3f, area = %.2f\n",circum,area);

    return 0;
}