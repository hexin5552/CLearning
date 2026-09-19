/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
int main(void) {
    int num = 0;
    int ch;
    while ((ch = getchar()) != EOF) {
        num++;
        if (ch != '\n' && getchar() != '\n')
            continue;
        if (ch == '\n') {
            num = 0;
            printf("\\n");
        }
        else if (ch == '\t')
            printf("\\t");
        else if (ch >= 32 && ch <= 126)
            putchar(ch);
        else if (ch < 32)
            printf("^%c", ch + 64);

        printf(" | ASCII = %d", ch);
        if (num == 10) {
            printf("\n");
            num = 0;
        }
    }
    printf("End Of File\n");
    return 0;
}