#include <stdio.h>
/**
 * @author Hexin
 * @version 1.0
 */
int main(void) {
    float rootbeer[10], thing[10][5], *pf, value = 2.2;
    int i = 3;
    rootbeer[2] = value;//✅ 有效。rootbeer[2] 是 float 元素，value 是 float，赋值合法。
    scanf("%f", &rootbeer);//❌ 无效（未定义行为，类型不匹配）。
    //&rootbeer 类型是 float (*)[10]（指向有10个 float 的数组的指针），而 %f 要求 float*。
    //虽然地址值相同，但类型错误，编译器应报警告，严格来说不合法。
    rootbeer = value;//❌ 无效。数组名 rootbeer 是地址常量，不可作为左值被赋值。
    scanf("%f", rootbeer);//✅ 有效。rootbeer 退化为指向首元素的指针（float*），与 %f 匹配。
    pf = value;//  ❌ 无效。pf 是指针，value 是 float，不能直接赋值。
    pf = rootbeer;//✅ 有效。rootbeer 退化为 float*，pf 也是 float*，合法。
    int dis[800][600];
    return 0;
}