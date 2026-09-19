/**
 * @author Hexin
 * @version 1.0
 */
#include <ctype.h>
#include <stdio.h>
int main(void) {
    char ch;
    int num = 0;
    while ((ch = getchar()) != '#') {
        if (isspace(ch))
            continue;
        num++;
        printf("%c-%d ", ch, ch);
        if (num % 8 == 0)
            printf("\n");
    }
    return 0;
}