/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#define S_TO_M 60
int main(void) {
    int sec, min, left;//sec未初始化，可能会导致在循环时出现未知问题

    printf("This program converts seconds to minutes and seconds.\n");
    printf("Just enter the number of seconds.\n");
    printf("Enter 0 to end the program.\n");
    while (sec > 0) {//此处输入0时，会先循环了一次才会退出，不符合小于等于0直接退出的要求
        scanf("%d", &sec);
        min = sec / S_TO_M;
        left = sec % S_TO_M;
        printf("%d sec is %d min, %d sec. \n", sec, min, left);
        printf("Next input ?\n");
    }
    printf("Bye!\n");

    return 0;
}