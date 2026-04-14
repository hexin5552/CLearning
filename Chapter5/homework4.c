/**
 * @author Hexin
 * @version 1.0
 */

//数学逻辑不太行

#include <stdio.h>
#define CM_PER_INCH 2.54
#define CM_PER_FOOT 30.48
int main(void) {
    float height, inches;
    printf("Enter a height in centimeters:");
    scanf("%f", &height);
    while (height > 0) {
        int feet = height / CM_PER_FOOT;
        inches = (height - feet * CM_PER_FOOT) / CM_PER_INCH;
        printf("%.1f cm = %d feet, %.1f inches\n", height, feet, inches);
        printf("Enter a height in centimeters:");
        scanf("%f", &height);
    }
    printf("bye");

    return 0;
}