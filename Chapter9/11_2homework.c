/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>

void chline(char, int, int);
int main(void) {
    chline('w',4,4);
    return 0;
}

void chline(char ch, int line, int column) {
    for (int m = 0; m < line; m++) {
        for (int z = 0; z < column; z++)
            printf("%c", ch);
        printf("\n");
    }
}