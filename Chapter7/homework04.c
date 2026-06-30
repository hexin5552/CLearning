/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>

int main(void) {
    int reNum = 0;
    char ch;
    while (ch = getchar()) {
        if (ch == '#') {
            break;
        }else if (ch == '.') {
            ch = '!';
            reNum++;
            printf("%c \n", ch);
        }
        else if (ch == '!') {
            reNum++;
            printf("!!");
        }else
        printf("%c \n", ch);
    }

    printf("replace num = %d in total", reNum);

    return 0;
}