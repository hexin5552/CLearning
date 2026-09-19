/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
char color = 'B';
void first(void);
void second(void);
int main(void) {
    extern char color;
    printf("color in main() is %c\n", color);//B
    first();//R
    printf("color in main() is %c\n", color);//B
    second();//G
    printf("color in main() is %c\n", color);//G
    return 0;
}
void first(void) {
    char color;
    color = 'R';
    printf("color in first() is %c\n", color);
}
void second(void) {
    color = 'G';
    printf("color in second() is %c\n", color);
}