#include <stdio.h>
/**
 * @author Hexin
 * @version 1.0
 */
int main(void) {
    int guess = 1;
    char response;

    printf("Pick an integer from 1 to 100. I will try to guess ");
    printf("it.\nRespond with a y if my guess is right and with");
    printf("\nan n if my guess is wrong.\n");
    printf("Uh...is your number is %d?", guess);
    while ((response = getchar()) != 'y') {
        if (response == 'n')
            printf("Well, then is it %d?\n", ++guess);
        else
            printf("Sorry, I understand only for y or n.\n");
        while (getchar() != '\n')
            continue;
    }
    printf("I knew I could do it!\n");
    return 0;
}