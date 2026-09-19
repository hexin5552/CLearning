/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
int main(void) {
    int ultra = 0, super = 0;

    while (super < 5) {
        // super++;
        // ++ultra;
        super += 1;
        ultra += 1;
        printf("super = %d, ultra = %d \n", super, ultra);
    }

    return 0;
}