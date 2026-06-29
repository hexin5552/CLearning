/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
void prArr(int ar[], int n);
void addArr(int n, int *ar, int *br, int *cr);
int main(void) {
    int ar1[4] = { 1, 2, 3, 4};
    int ar2[4] = { 1, 2, 3, 4};
    int ar3[4];
    addArr(4, ar1, ar2, ar3);
    prArr(ar3, 4);
    return 0;
}
void addArr(int n, int *ar, int *br, int *cr) {
    int *aar = ar;
    int *bbr = br;
    int *ccr = cr;
    for (int i = 0; i < n; i++)
        (*ccr++) = (*aar++) + (*bbr++);
}
void prArr(int ar[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", ar[i]);
    printf("\n");
}