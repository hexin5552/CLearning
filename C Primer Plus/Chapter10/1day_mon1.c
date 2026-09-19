/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#define MONTHS 12
int main(void) {
    int month[MONTHS] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int index = 0;
    for (index; index < MONTHS; index++) {
        printf("Month %2d has %2d days.\n", index + 1, month[index]);
    }
    return 0;
}