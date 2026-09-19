/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#define BOOK "War and Peace"
int main (void) {
    float cost = 12.99;
    float percent = 80.0;
    printf("This copy of %s sells for $%.2f.",BOOK,cost);
    printf("\nThat is %2.0f%% of list.",percent);
    return 0;
}
