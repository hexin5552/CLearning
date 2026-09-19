/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
int main(void) {
    int years = 0;
    long prize = 100;

    while (prize > 0) {
        prize += 100 * 0.08;
        prize -= 10;
        years++;
    }
    printf("after %d years, Lucky account will be zero", years);
}