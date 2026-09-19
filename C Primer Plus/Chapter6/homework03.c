/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
int main(void) {
    char ch = 'F';
    for (int i = 1; i <= 6; i++) {
        for (int j = 0, ch = 'F'; j < i; j++)
            printf("%c", ch--);
        printf("\n");
    }

    return 0;
}