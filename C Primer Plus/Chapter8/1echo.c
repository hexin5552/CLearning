/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
int main(void) {
    char ch;
    while ((ch = getchar()) != '#')
        putchar(ch);
    return 0;
}