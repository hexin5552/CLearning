/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>

int main(void) {
    int lower, upper, sum_i = 0;
    printf("Enter lower and upper integer limits: ");
    scanf("%d %d", &lower, &upper);
    for (int i = lower; i <= upper; ++i)
        sum_i += i * i;

    while (lower != upper && lower < upper) {
        printf("The sum of the squares from %d to %d is %d\n", lower * lower, upper * upper, sum_i);
        printf("Enter next set of limits: ");
        scanf("%d %d", &lower, &upper);
        for (int i = lower; i <= upper; ++i)
            sum_i += i * i;
    }
    printf("Done");
    return 0;
}
