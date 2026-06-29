/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
int main(void) {
    int ref[] = { 8, 4, 0, 2 };
    int *ptr;
    int index;
    for (index = 0, ptr = ref; index < sizeof(ref) / sizeof(ref[0]); index++, ptr++)
        printf("%d %d\n", ref[index], *ptr);
    /*0 8
     *1 4
     *2 0
     *3 2*/
    //正确答案↓
    /*8 8
     *4 4
     *0 0
     *2 2*/
//共有4个元素，，ref的地址是&ref[0]，ref+1是指向下一个元素，++ref是当前指向的这个数的值+1（×）
    //++ref是非法的，数组名不能自增
    return 0;
}