/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#include <ctype.h>
int main(void) {
    char ch;

    while ((ch = getchar()) != '\n') {
        if (isalpha(ch))
            putchar(ch + 1);
        else
            putchar(ch);
    }
    putchar(ch);

    return 0;
}