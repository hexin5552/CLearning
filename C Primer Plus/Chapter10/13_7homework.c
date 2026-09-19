/**
 * @author Hexin
 * @version 1.0
 */
// 与13.2同属一个类别，后续复习时对比着复习。
//考察一维指针，二维指针与数组
#include <stdio.h>
#define MONTH 12
#define YEARS 5
void copyArr(int n, int m, double ar[n][m], double sou[n][m]);
void copyPtr(int n, int m, double (*ar)[m], double (*sou)[m]);
void copyPtrs(double *ar, double *sou, double *end);
void prArr(int n, int m, double ar[n][m]);
int main(void) {
    double rain[YEARS][MONTH] = {
        { 4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6 },
        { 8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3 },
        { 9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4 },
        { 7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2 },
        { 7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2 }
    };
    double ai[YEARS][MONTH];
    double bi[YEARS][MONTH];
    double ci[YEARS][MONTH];
    copyArr(YEARS, MONTH, ai, rain);
    prArr(YEARS, MONTH, ai);
    copyPtr(YEARS, MONTH, bi, rain);
    prArr(YEARS, MONTH, bi);
    copyPtrs(&ci[0][0], &rain[0][0], &rain[0][0] + YEARS * MONTH);
    prArr(YEARS, MONTH, ci);
    return 0;
}
void copyArr(int n, int m, double ar[n][m], double sou[n][m]) {
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
        ar[i][j] = sou[i][j];
}
void copyPtr(int n, int m, double (*ar)[m], double (*sou)[m]) {
    double *pt = &ar[0][0];
    double *pr = &sou[0][0];
    for (int i = 0; i < n * m; i++)
            *pt++ = *pr++;
}
void copyPtrs(double *ar, double *sou, double *end) {
    while (sou < end) {
        *ar++ = *sou++;
    }
}
void prArr(int n, int m, double ar[n][m]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%.1f ", ar[i][j]);
        printf("\n");
    }
    printf("\n");
}