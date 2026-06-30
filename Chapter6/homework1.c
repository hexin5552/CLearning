/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
int main(void) {
    int quack = 2;

    quack += 5;//7
    printf("%d\n", quack);
    quack *= 10;//70
    printf("%d\n", quack);
    quack -= 6;//64
    printf("%d\n", quack);
    quack /= 8;//8
    printf("%d\n", quack);
    quack %= 3;//2
    printf("%d\n", quack);
}