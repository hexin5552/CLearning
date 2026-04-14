/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#define HOUR 60
int main(void) {
    int h;
    int min;
    int left_min;
    printf("Please enter minutes.\n");
    scanf("%d",&min);
    while (min > 0) {
        h = min / HOUR;
        left_min = min - h * HOUR;
        printf("%d minutes is %d hours and %d mins.\n", min, h, left_min);
        printf("Please enter minutes.\n");
        scanf("%d",&min);
    }
    printf("That's all.");

    return 0;
}