/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
int main(int argv, char **argc) {
    if (argv < 2) {
        printf("Parameter must more than 2 words\n");
        return 0;
    }

    for (int i = argv - 1; i >= 1; i--) {
        printf("%s", argc[i]);
        if (i > 1)
            putchar(' ');

    }
    putchar('\n');
    return 0;
}