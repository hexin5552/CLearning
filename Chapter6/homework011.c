/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
int main(void) {
    int arr[8] = {0};
    for (int i = arr[0]; i < sizeof(arr) / sizeof(arr[0]); i++)
        scanf("%d", &arr[i]);
    for (int i = sizeof(arr) / sizeof(arr[0]) - 1; i >= 0; i--)
        printf("%d ", arr[i]);

    return 0;
}
/*
arr[0] 初始化为 0，因此 sizeof(arr) / 0 是除零操作，会导致程序崩溃或未定义行为。
作者本意可能是计算数组元素个数，正确写法应为 sizeof(arr) / sizeof(arr[0])。

即使修复除零错误，假设得到元素个数 n = 8，则 i 从 8 开始。
数组 arr 有效下标是 0 ~ 7，访问 arr[8] 是越界，行为未定义。
另外循环会输出 arr[8]（非法）、arr[7] ... arr[0]，且没有分隔符或换行。
 */