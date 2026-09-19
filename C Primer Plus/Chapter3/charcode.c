/**
 * @author Hexin
 * @version 1.0
 */
#include<stdio.h>
int main(void) {
    signed char ch;

    printf("Please enter a character. \n");
    scanf("%c", &ch);
    printf("The code for %c is %d.\n",ch,ch);
    return 0;
}