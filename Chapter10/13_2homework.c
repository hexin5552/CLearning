/**
 * @author Hexin
 * @version 1.0
 */
//与13.7 13.8同源题
#include <stdio.h>
void copyArr(double ar[], double sou[], int n);

void copyPtr(double ar[], double sou[], int n);

void copyPtrs(double ar[], double sou[], double *end);

void prArr(double ar[], int n);
int main(void) {
    double source[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    double target1[5];
    copyArr(target1, source, 5);
    prArr(target1, 5);
    double target2[5];
    copyPtr(target2, source, 5);
    prArr(target2, 5);
    double target3[5];
    copyPtrs(target3, source, source + 5);
    prArr(target3, 5);

    return 0;
}
void copyArr(double ar[], double sou[], int n) {
    int i;
    for (i = 0; i < n; i++)
        ar[i] = sou[i];

}
void copyPtr(double ar[], double sou[], int n) {
    double *p = sou;   // 指向源数组
    double *q = ar;    // 指向目标数组
    for (int i = 0; i < n; i++) {
        *q = *p;       // 复制值
        p++;
        q++;
    }
}
void copyPtrs(double ar[], double sou[], double *end) {
    while (sou < end) {
        *ar = *sou;
        sou++;
        ar++;
    }
}
void prArr(double ar[], int n) {
    for (int i = 0; i < n; i++)
        printf("%.1f ", ar[i]);
    printf("\n");
}
/*
数组与指针的本质关系
1. 数组名是常量指针
在表达式中，数组名会被转换为指向其首元素的指针（类型为 T*）。

例：double source[5]; 中 source 等价于 &source[0]，类型为 double*。

例外：sizeof(source) 返回整个数组的字节数（5 * sizeof(double)），此时不转换为指针。

2. 通过指针访问数组元素
下标访问 arr[i] 等价于 *(arr + i)。

指针加法：ptr + i 移动 i * sizeof(T) 字节。

函数参数中的数组“退化”
当数组作为函数参数时，自动退化为指针：

void func(double ar[]);   // 编译器视作 void func(double *ar)
void func(double ar[5]);  // 同上，长度5被忽略
因此，在函数内部无法通过 sizeof(ar)/sizeof(ar[0]) 获得数组长度（sizeof(ar) 是指针大小）。必须显式传递长度参数。

写法	实际参数类型	能否在函数内求数组长度
void f(int arr[])	int*	❌ 不能
void f(int arr[10])	int*	❌ 不能
void f(int *arr)	int*	❌ 不能

三种数组复制方式的实现
1. 下标法 —— copyArr
void copyArr(double ar[], double sou[], int n) {
    for (int i = 0; i < n; i++)
        ar[i] = sou[i];
}
最直观，适合初学者。

内部仍使用指针运算，但语法上屏蔽了指针细节。

2. 指针法（指针 + 递增）—— copyPtr
void copyPtr(double ar[], double sou[], int n) {
    double *p = sou;
    double *q = ar;
    for (int i = 0; i < n; i++) {
        *q = *p;
        p++; q++;
    }
}
显式使用指针变量，展示指针算术。

可以合并为 *q++ = *p++。

3. 尾指针法 —— copyPtrs
void copyPtrs(double ar[], double sou[], double *end) {
    while (sou < end) {
        *ar = *sou;
        ar++; sou++;
    }
}
用结束指针（指向最后一个元素之后）控制循环。

调用时需计算尾指针：copyPtrs(target, source, source + n)。
推荐模式

void processArray(double arr[], int n)  // 或者 double *arr
在调用侧获取数组长度

double arr[10];
processArray(arr, sizeof(arr)/sizeof(arr[0]));   // 在作用域内可这样求
动态数组（指针指向堆内存）

double *arr = malloc(10 * sizeof(double));
processArray(arr, 10);   // 长度只能由变量保存
free(arr);

多维数组与指针
二维数组 int a[3][4]：a 退化为 int (*)[4]（指向长度为4的数组的指针）。

作为参数时需指定第二维长度：void f(int a[][4], int rows)。

一维指针数组与数组指针不要混淆：int *p[5]（指针数组） vs int (*p)[5]（数组指针）。

 */