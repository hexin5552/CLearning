/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#define SIZE 8
int main(void) {
    const int WIDTH = 4;
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < SIZE; j++)
            printf("$");
        printf("\n");
    }
    return 0;
}