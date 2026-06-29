/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>

void manu(void);

int limit(int, int);

void choice(int);

int main(void) {
    manu();
    choice(limit(4,1));
    return 0;
}
void manu(void) {
    printf("Please choose one of the following:\n");
    printf("1) copy files\t\t2) move files\n");
    printf("3) remove files\t\t4) quit\n");
    printf("Enter the number of your choice:");
}
int limit(int upper, int lower) {
    int num;
    while (1) {
        if (scanf("%d", &num) != 1) {
            printf("Unknown intake, program will exit\n");
            return 4;
        }
        if (num < lower || num > upper) {
            printf("Your choice is uncommitted.\n");
            manu();
        }else
            return num;
    }
}

void choice(int opt) {
        switch (opt) {
            case 1:
                printf("You choose copy files.\n");
                break;
            case 2:
                printf("You choose move files.\n");
                break;
            case 3:
                printf("You choose remove files.\n");
                break;
            case 4:
                printf("quit.\n");
                break;
        }
}