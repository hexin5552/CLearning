/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
int main(void) {
    char ch;
    int reNum = 0;
    while (ch = getchar()) {
        if (ch == '#')
            break;
        switch (ch) {
            case '.':
                printf("!");
                reNum++;
                break;
            case '!':
                printf("!!");
                reNum++;
        }
    }
    printf("replace number = %d in total", reNum);
    return 0;
}