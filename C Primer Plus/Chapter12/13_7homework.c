/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int guess;
    srand(time(NULL));
    int num = rand() % 100 + 1;
    printf("Enter a number between 1-100 to guess my number.\n");
    while (scanf("%d", &guess) == 1 && guess > 0) {
        if (guess > num)
            puts("Your number is greater than my number, try again.");
        else if (guess < num)
            puts("Your number is lesser than my number, try again.");
        else {
            puts("Good luck for you!");
            printf("my number is %d\n", num);
            break;
        }
    }
    return 0;
}
