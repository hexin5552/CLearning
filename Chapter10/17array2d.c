/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#define ROWS 3
#define COLS 4
void sumRows(int ar[][COLS]);
void sumCols(int [][COLS]);
int sum2d(int (*ar)[COLS]);
int main(void) {
    int junk[ROWS][COLS] = {
        { 2, 4, 6, 8 },
        { 3, 5, 7, 9 },
        {12, 10, 8, 6 }
    };

    sumRows(junk);
    sumCols(junk);
    printf("Sum of all elements = %d.\n", sum2d(junk));
    return 0;
}

void sumRows(int ar[][COLS]) {
    int r, c, tot;
    for (r = 0; r < ROWS; r++) {
        tot = 0;
        for (c = 0; c < COLS; c++)
            tot += ar[r][c];
        printf("row %d: sum = %d.\n", r, tot);
    }
}

void sumCols(int ar[][COLS]) {
    int r, c, tot;
    for (c = 0; c < COLS; c++) {
        tot = 0;
        for (r = 0; r < ROWS; r++)
            tot += ar[r][c];
        printf("col %d: sum = %d.\n", c, tot);
    }
}

int sum2d(int (*ar)[COLS]) {
    int r, c, tot = 0;
    for (r = 0; r < ROWS; r++)
        for (c = 0; c < COLS; c++)
            tot += ar[r][c];
    return tot;
}