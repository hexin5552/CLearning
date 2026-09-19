/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#define SIZE 10
int sum(int ar[], int n);

int main(void) {
    int marble[SIZE] = { 20, 10, 5, 39, 4, 16, 19, 26, 31, 20};
    long ans = sum(marble, SIZE);

    printf("The total number of marbles is %ld.\n", ans);
    printf("The size of marbles is %zd bytes.\n", sizeof (marble));
    return 0;
}

int sum(int ar[], int n) {
    int i;
    int total = 0;

    for (i = 0; i < n; i++)
        total += ar[i];
    printf("The size of ar is %zd bytes.\n", sizeof (ar));

    return total;
}