/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
int main(void) {
    int rows;
    char ch;
    scanf("%c", &ch);
    rows = ch - 'A' + 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows - i - 1; j++)
            printf(" ");
        for (char c = 'A'; c <= 'A' + i; c++)
            printf("%c", c);
        for (char c = 'A' + i - 1; c >= 'A'; c--)
            printf("%c", c);
        printf("\n");
    }

    return 0;
}