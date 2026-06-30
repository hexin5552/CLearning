/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
int main(void) {
    char ch = '$';
    for (int i = 1; i <= 5; i++) {
        for (int j = 0; j < i; j++)
            printf("%c", ch);
        printf("\n");
    }

    return 0;
}