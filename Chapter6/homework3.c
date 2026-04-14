/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>

int main(void) {
    int x;
    while (scanf("%d", &x) == 1) {
        x = 6;
        printf("while is running, x = %d\n", x);
    }
    x = 5;
    printf("while is not running, x = %d\n", x);
}