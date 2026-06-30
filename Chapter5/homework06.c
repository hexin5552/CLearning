/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#define FORMAT "%s C is cool!\n"
int main(void) {
    int num = 10;

    printf("FORMAT FORMAT\n");
    printf("%s%s\n", FORMAT, FORMAT);
    printf("%d\n", ++num);//11
    printf("%d\n", num++);//11
    printf("%d\n", num--);//12
    printf("%d\n", num);//11

    return 0;
}