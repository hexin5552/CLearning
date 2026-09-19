/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>

void toBinary(unsigned long);
int main(void) {
    unsigned long n;
    printf("Enter an integer (q to quit):\n");
    while (scanf("%lu", &n) == 1) {
        printf("Binary equivalent: ");
        toBinary(n);
        putchar('\n');
        printf("Enter an integer (q to quit):\n");
    }
    printf("Done");
    return 0;
}

void toBinary(unsigned long n) {
    int r;
    r = n % 2;
    if (n >= 2)
        toBinary(n / 2);
    putchar(r == 0 ? '0' : '1');
}
