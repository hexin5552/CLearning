/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#define TWO 2 //可以加注释
#define OW "Consistency is the last refuge of the unimagins\
tive. -Oscar Wilde"//反斜杠延续定义
#define FOUR TWO * TWO
#define PX printf("X is %d.\n", x);
#define PMT "X is %d.\n"
int main(void) {
    int x = TWO;
    PX;
    x = FOUR;
    printf(PMT, x);
    printf("%s\n", OW);
    printf("TWO: PW\n");
    return 0;
}