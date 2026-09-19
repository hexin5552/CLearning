/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
void visArr(int w, int aa[3][w]);
void doubleArr(int w, int aa[3][w], int bb[3][w]);
int main(void) {
    int ar[3][5] = {
        { 1, 2, 3, 4, 5 },
        { 6, 7, 8, 9, 1 },
        { 7, 8, 9, 2, 7 }
    };
    int br[3][5];
    visArr(5, ar);
    doubleArr(5, ar,br);
    printf("======================\n");
    visArr(5,br);
    return 0;
}
void visArr(int w, int aa[3][w]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < w; j++)
            printf("%d ", aa[i][j]);
        printf("\n");
    }
}
void doubleArr(int w, int aa[3][w], int bb[3][w]) {
    int *pr, *br;
    pr = &aa[0][0];
    br = &bb[0][0];
    for (int j = 0; j < w * 5; j++)
        *br++ = 2 * (*pr++);
}