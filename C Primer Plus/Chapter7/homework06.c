/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#include <ctype.h>
int main(void) {
    char ch, chI;
    int num;
    while ((ch = getchar()) != '#') {
        if (isspace(ch) || ch == '\n')
            continue;
        if (chI == 'e' && ch == 'i')
            num++;
        chI = ch;
    }
    printf("ei = %d in total", num);
    return 0;
}