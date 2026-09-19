/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
int main(void) {
    const float MIN = 0.0f;
    const float MAX = 100.0f;

    float score, total = 0.0f;
    int n = 0;
    float min = MAX;
    float max = MIN;

    printf("Enter the first score (q to quit): ");
    while (scanf("%f", &score) == 1) {
        if (score > MAX || score < MIN) {
            printf("%.1f is an invalid value. Try again: ", score);
            continue;
        }
        printf("Accepting %.1f:\n", score);
        min = (min < score) ? min : score;
        max = (max > score) ? max : score;
        total += score;
        n++;
        printf("Enter next score (q to quit): ");
    }
    if (n > 0) {
        printf("Average of %d scores is %.1f.\n", n, total / n);
        printf("Low = %.1f, high = %.1f\n", min, max);
    }else {
        printf("No valid scores were entered.\n");
    }

    return 0;
}