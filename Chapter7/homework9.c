/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>

int main(void) {
    char ch;

    while ((ch = getchar()) != '#') {//qchb
        if (ch == '\n')
            continue;
        printf("step 1\n");
        if (ch == 'c')
            continue;
        else if (ch == 'b')
            break;
        else if (ch == 'h')
            goto laststep;
        printf("step 2\n");
        laststep : printf("step 3\n");
    }
    printf("Done\n");
    return 0;
}