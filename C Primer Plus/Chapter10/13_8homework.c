/**
 * @author Hexin
 * @version 1.0
 */
void copyArr(double ar[], double sou[], int n);

void copyPtr(double ar[], double sou[], int n);

void copyPtrs(double ar[], double sou[], double *end);

void prArr(double ar[], int n);
#include <stdio.h>
int main(void) {
    double source[] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7 };
    double ar[3];
    double br[3];
    double cr[3];
    copyArr(ar, &source[2], 3);
    prArr(ar, 3);
    copyPtr(br, &source[2], 3);
    prArr(br, 3);
    copyPtrs(cr, &source[2], source + 5);
    prArr(cr, 3);
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