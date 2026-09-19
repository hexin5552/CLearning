/**
* @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define ANSWER "Grant"
#define SIZE 40
char * sGets(char * st, int n);
int main(void) {
    char try[SIZE];
    puts("Who is burried in Grant's tomb?");
    sGets(try, SIZE);
    while (strcmp(try, ANSWER)) {
        puts("No, that's wrong. Try again.");
        sGets(try, SIZE);
    }
    puts("You are right.");
    return 0;
}
char * sGets(char * st, int n) {
    int i = 0;
    char * retVal = fgets(st, n, stdin);

    if (retVal) {
        while (st[i] != '\0' && st[i] != '\n')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n');

        st[0] = toupper(st[0]);
    }
    return retVal;
}