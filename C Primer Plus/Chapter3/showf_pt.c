/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
//以两种方式显示float类型的值
int main(void) {
    float aboat = 32000.0;
    double abet = 2.14e9;
    long double dip = 5.32e-5;
    float toobig = 3.4E38 * 100.0f;

    printf("%e\n",toobig);
    printf("%f can be written %e\n", aboat, aboat);
    //下一行要求编译器支持C99或其中的相关特性
    printf("And it's %a in hexadecimal, powers of 2 notation\n", aboat);
    printf("%Lf can be written %Le\n", dip, dip);
    return 0;
}
