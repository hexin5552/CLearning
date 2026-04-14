/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
int main(void) {
    int x = 0;
    while (++x < 3)
        printf("%4d\n",x);//1, 2

    x = 100;
    while (x++ < 103)
        printf("%4d\n",x);//101 102 103
        printf("%4d\n",x);//104

    char ch = 's';
    while (ch < 'w') {
        printf("%c",ch);//s t u v
        ch++;
    }
    printf("%c\n",ch);//w
}