/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#define WEEK 7
int main(void) {
    int days, weeks, left_days;
    printf("Please enter a number of days.\n");
    scanf("%d", &days);
    while (days > 0) {
        weeks = days / WEEK;
        left_days = days - weeks * WEEK;
        printf("%d days are %d weeks, %d days.\n", days, weeks, left_days);
        printf("Please enter a number of days.\n");
        scanf("%d", &days);
    }
    printf("That's all.\n");

    return 0;
}