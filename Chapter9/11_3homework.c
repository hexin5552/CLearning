/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
void f1(char, int, int);
int main(void) {
    f1('!', 2, 3);
    return 0;
}
void f1(char ch, int i, int y) {
    for (int a = 0; a < y; a++){
        for (int s = 0; s < i; s++)
            printf("%c", ch);
    printf("\n");
}
}