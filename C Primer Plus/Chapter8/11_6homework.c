/**
* @author Hexin
 * @version 1.0
 */
#include <stdio.h>

char getFirst(void);
int main(void) {
    int choice;
    printf("Enter a sentence, I will return the first letter for you.\n");
    choice = getFirst();
    printf("The first letter is \'%c\'", choice);
    return 0;
}

char getFirst(void) {
    int ch;
    while ((ch = getchar()) == ' ' || ch == '\t' || ch == '\n')
        continue;
    while (getchar() != '\n')
    return ch;
}