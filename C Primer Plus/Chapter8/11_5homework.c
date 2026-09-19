#include <stdio.h>
/**
 * @author Hexin
 * @version 1.0
 */
int main(void) {
    char response;
    int lowRange = 0;
    int upRange = 1000;
    int guess;

    printf("Pick an integer from %d to %d. I will try to guess ", lowRange, upRange);
    printf("it.\nRespond with a y if my guess is right and with");
    printf("\nan 'l' if my guess is less than digit, an 'm' if my guess is more than digit.\n");
    while (1) {
        guess = (upRange + lowRange) / 2;
        printf("I guess the digit is %d?\n", guess);
        while ((response = getchar()) == '\n');
        if (response == 'l') {
            lowRange = guess + 1;
        }else if (response == 'm') {
            upRange = guess - 1;
        } else if (response == 'y'){
            break;
        }else {
            printf("Sorry, I only can know y/l/m.\n");
        }

    }
    printf("I knew I could do it!\n");
    return 0;
}
