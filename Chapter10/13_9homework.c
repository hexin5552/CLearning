/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
void copyArr(int n, int m, double arr[n][m], double source[n][m]);
void prArr(int n, int m, double arr[n][m], double source[n][m]);
int main(void) {
    double arr[3][5] = {
        { 1.1, 2.2, 3.3, 4.4, 5.5 },
        { 6.6, 7.7, 8.8, 9.9, 10.1 },
        { 11.1, 22.2, 33.3, 44.4, 55.5}
    };
    double br[3][5];
    copyArr(3, 5, br, arr);
    prArr(3, 5, br, arr);
    return 0;
}
void copyArr(int n, int m, double arr[n][m], double source[n][m]) {
    double *pr1;
    double *pr2;
    pr1 = &arr[0][0];
    pr2 = &source[0][0];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            *pr1++ = *pr2++;
}
void prArr(int n, int m, double arr[n][m], double source[n][m]){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%.1f ", arr[i][j]);
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%.1f ", source[i][j]);
        printf("\n");
    }
    printf("\n");
}