/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
int main(void) {
    int ch, num = 0;
    while ((ch = getchar()) != EOF)
        num++;
    printf("total char: %d", num);
    return 0;
}