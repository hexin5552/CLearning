/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
int main(void) {
    int i;
    char ch;

    for (i = 0, ch = 'A'; i < 4; i++, ch += 2 * i)
        printf("%c", ch);//A C G M

    return 0;
}