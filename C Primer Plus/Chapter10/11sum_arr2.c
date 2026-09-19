/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#define SIZE 10
int sump(int *, int *);
int main(void) {
    int marble[SIZE] = { 20, 10, 5, 39, 4, 16, 19, 26, 31, 20 };
    long answer;

    answer = sump(marble, marble + SIZE);
    printf("The total number of marbles is %ld.\n", answer);
    return 0;
}
int sump(int * start, int * end) {
    int sum = 0;

    while (start < end) {
        sum += *start;
        start++;
    }

    return sum;
}