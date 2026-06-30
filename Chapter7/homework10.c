/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>

int main(void) {
    char ch;
    while ((ch = getchar()) != '#') {
        if (ch != '\n') {
            if (ch == 'c') {
                printf("step 1\n");
            }else if (ch == 'h') {
                printf("step 3\n");
            }else if (ch == 'b') {
                printf("step 1\n");
                break;
            }else {
                printf("step 1\n");
                printf("step 2\n");
            }
        }
    }
    printf("Done\n");
    return 0;
}