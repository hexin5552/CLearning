/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>

char getChoice(void);

char getFirst(void);

int getInt(void);

void count(void);

int main(void) {
    int choice;

    while ((choice = getChoice()) != 'q') {
        switch (choice) {
            case 'a':
                printf("Buy low, sell high.\n");
                break;
            case 'b':
                putchar('\a');
                break;
            case 'c':
                count();
                break;
            default: printf("Program error!\n");
                break;
        }
    }
    return 0;
}

void count(void) {
    int n, i;

    printf("Count how far? Enter an integer:\n");
    n = getInt();
    for (i = 1; i <= n; i++)
        printf("%d\n", i);
    while (getchar() != '\n')
        continue; //读取缓冲区的数，如果不是换行就一直读，直到读到换行
}

char getChoice(void) {
    int ch;

    printf("Enter the letter of your choice:\n");
    printf("a. advice\t\t\tb. bell\n");
    printf("c. count\t\t\tq. quit\n");
    ch = getFirst();
    while ((ch < 'a' || ch > 'c') && ch != 'q') {
        printf("Please respond with a, b, c, or q.\n");
        ch = getFirst();
    }

    return ch;
}

char getFirst(void) {
    int ch;
    ch = getchar();
    while (getchar() != '\n')
        continue;

    return ch;
}

int getInt(void) {
    int input;
    char ch;

    while (scanf("%d", &input) != 1) {
        while ((ch = getchar()) != '\n')
            putchar(ch);
        printf(" is not an integer.\nPlease enter an integer value, such as 25, -178, or 3: ");
    }

    return input;
}
