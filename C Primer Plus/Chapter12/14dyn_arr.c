/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#include <stdlib.h>
int main(void) {
    double * ptd;
    int max;
    int number;
    int i = 0;
    puts("What is the maximum number of type double entries?");
    if (scanf("%d", &max) != 1) {
        puts("Number not correctly entered -- Bye.");
        exit(EXIT_FAILURE);
    }

    ptd = (double *)malloc(max * sizeof(double));
    if (ptd == NULL) {
        puts("Memory allocation failed. Goodbye.");
        exit(EXIT_FAILURE);
    }
    puts("Enter the values (q to quit): ");
    while (i < max && scanf("%lf", ptd + i) == 1)
        ++i;
    printf("Here are your %d entries:\n", number = i);
    for (i = 0; i < number; i++) {
        printf("%7.2f", ptd[i]);
        if (i % 7 == 6)
            putchar('\n');
    }
    if (i % 7 == 0)
        putchar('\n');
    free(ptd);
    puts("Done.");
    return 0;
}