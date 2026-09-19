/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
void critic(int * units);
int main(void) {
    int units = 0;
    printf("How many pounds to a firkin of butter?\n");
    scanf("%d", &units);
    critic(&units);
    printf("You must have looked it up!\n");
    return 0;
}
void critic(int * units) {
    while (*units != 56) {
        printf("No luck, my friend. Try again.\n");
        scanf("%d", units);
        //scanf("%d", &units);错误，因为当前函数中传递的是主函数的units的地址，如果再取地址的话就是地址的地址类型了，scanf读取的值就是未定义的情况，是未定义行为
        //当前&units是int ** 类型
    }
}