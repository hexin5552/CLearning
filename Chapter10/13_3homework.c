/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
int maxArr(int ar[], int m);
int main(void) {
    int maxNum = maxArr((int []){2, 3, 12, 25, 102, 23}, 6);
    printf("max = %d", maxNum);
    return 0;
}
int maxArr(int ar[], int m) {
    int max = ar[0];
    //for (int i = 1; i < sizeof(ar) / sizeof(int); i++)
    for (int i = 1; i < m; i++)
        if (ar[i] > max)
            max = ar[i];
    return max;
}