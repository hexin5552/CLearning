/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
int main(void) {
    const int FREZZING = 0;
    float temperature;
    int cold_days = 0, all_days = 0;

    printf("Enter the list of daily low temperature.\n");
    printf("Use Celsius, and enter q to quit.\n");
    while (scanf("%f", &temperature) == 1) {
        all_days++;
        if (temperature < FREZZING)
            cold_days++;
    }
    if (all_days != 0)
        printf("%d days total: %.1f%% were below freezing.\n", all_days, 100.0 * (float) cold_days / all_days);
    else
        printf("No data enrered!\n");

    return 0;
}