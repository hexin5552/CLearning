/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#include <ctype.h>

int main(void) {
    char ch;
    int numSpace = 0, numLine = 0, numOther = 0;

    while ((ch = getchar()) != '#') {
        if (isblank(ch))
            numSpace++;
        else if (isspace(ch))
            numLine++;
        else
            numOther++;
    }
    printf("In totally, there are %d space, %d new lines, %d other characters\n", numSpace, numLine, numOther);
    return 0;
}
