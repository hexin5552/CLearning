/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>

int main(void) {
    char c1[8];
    int length = sizeof(c1) / sizeof(c1[0]);
    for (int i = 0; i < length; i++)
        scanf("%c", &c1[i]);
    for (int i = length; i >= 0; i--)
        printf("%c", c1[i]);

    return 0;
}
