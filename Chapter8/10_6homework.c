/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
int main(void) {
    int ch;
    // while ((ch = getchar()) != 'i') {
    //     putchar(ch);
    // }

    while ((ch = getchar()) != '\n') {//HarHar
        putchar(ch++);//Har
        putchar(++ch);//Jct
    }//HJacrt
    return 0;
}