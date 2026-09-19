/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
int put2(const char *);
void put1(const char *);
int main(void) {
    put1("If I'd as much money");
    put1(" as I could spend,\n");
    printf("I could %d characters.\n", put2("I never would cry old chairs to mend."));
    return 0;
}
void put1(const char *string) {
    while (*string)
        putchar(*string++);
}

int put2(const char *string) {
    int num = 0;
    while (*string) {
        putchar(*string++);
        num++;
    }
    putchar('\n');
    return num;
}