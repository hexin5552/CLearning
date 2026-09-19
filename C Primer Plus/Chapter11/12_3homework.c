/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#include <string.h>
int main(void) {
    char food [] = "Yummy";
    char *ptr;

    ptr = food + strlen(food);//'\0'
    while (--ptr >= food)
        puts(ptr);
    /*
     * y
     * my
     * mmy
     * ummy
     * Yummy
     */
    return 0;
}