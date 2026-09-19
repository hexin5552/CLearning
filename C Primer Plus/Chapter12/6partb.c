/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
extern int count;
static int total;
void accumulate(int k);
void accumulate(int k) {
    static int subtotal;

    if (k <= 0) {
        printf("loop cycle: %d\n", count);
        printf("subtotal: %d, total: %d\n", subtotal, total);
        subtotal = 0;
    }else {
        subtotal += k;
        total += k;
    }
}