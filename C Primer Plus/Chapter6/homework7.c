/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
int main(void) {
    int i = 0;

    while (++i < 4)
        printf("Hi! ");//Hi Hi Hi
    do
        printf("Bye! ");//Bye Bye Bye Bye Bye
    while (i++ < 8);

    return 0;
}