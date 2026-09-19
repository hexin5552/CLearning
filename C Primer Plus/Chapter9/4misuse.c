/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
int imax();
/*不检查参数类型
不检查参数个数
传啥都收，错了也不拦你*/
int main(void) {
    printf("The maximum of %d and %d is %d.\n", 3, 5, imax(3));//老式 C 语法（无原型函数），编译器不检查参数个数！
    printf("The maximum of %d and %d is %d.\n", 3, 5, imax(3.0, 5.0));
    return 0;
}
int imax(n, m)
int n, m;
{
    return (n > m ? n : m);
}