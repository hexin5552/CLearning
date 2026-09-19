/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#include <stdbool.h>
long getLong(void);
bool badLimits(long begin, long end, long low, long high);
double sumSquares(long a, long b);
int main(void) {
    const long MAX = 10000000L;
    const long MIN = -10000000L;
    long start, stop;
    double answer;

    printf("This program computes the sum of the squares of integers in a range.\n"
           "The lower bound should not be less than -10000000 and\nthe upper bound should not be more than +10000000.\n"
           "Enter the limits (enter 0 for both limits to quit):\n"
           "lower limit: ");
    start = getLong();
    printf("upper limit: ");
    stop = getLong();
    while (start != 0 || stop != 0) {
        if (badLimits(start, stop, MIN, MAX))
            printf("Please try again.\n");
        else {
            answer = sumSquares(start, stop);
            printf("The sum of the squares of the integers from %ld to %ld is %g\n", start, stop, answer);
        }
        printf("Enter the limits (enter 0 for both limits to quit):\n");
        printf("lower limit: ");
        start = getLong();
        printf("upper limit: ");
        stop = getLong();
    }
    printf("Done.\n");
    return 0;
}
long getLong(void) {
    long input;
    char ch;

    while (scanf("%ld", &input) != 1) {
        while ((ch = getchar()) != '\n')
            putchar(ch);
            printf(" is not an integer.\nPlease enter an integer value,such as 25, -178 or 3: ");
    }

    return input;
}
bool badLimits(long begin, long end, long low, long high) {
    bool notGood = false;

    if (begin > end) {
        printf("%ld is not smaller than %ld", begin, end);
        notGood = true;
    }
    if (begin < low || end < low) {
        notGood = true;
        printf("Values must be %ld or greater", low);
    }
    if (begin > high || end > high) {
        notGood = true;
        printf("Values must be %ld or less", high);
    }

    return notGood;
}
double sumSquares(long a, long b) {
    double total = 0;
    long i;

    for (i = a; i <= b; i++)
        total += (double) i * (double) i;

    return total;
}