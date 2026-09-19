/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#include <ctype.h>
int main(void) {
    int ch;
    int numCaps = 0;
    int numLows = 0;
    while ((ch = getchar()) != EOF) {
        if (islower(ch))
            numLows++;
        else if (isupper(ch))
            numCaps++;
    }
    printf("Lower = %d, Upper = %d\n", numLows, numCaps);
    return 0;
}