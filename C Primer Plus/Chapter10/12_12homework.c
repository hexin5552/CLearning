/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
//a
void trotsT(double[20], int);
void trotsT(int rows, double[rows], int);
//b
void clopsT(short[10][30], int, int);
void clopsT(int ROWS, int COLS, short clops[ROWS][COLS], int, int);
//c
void shotsT(long[5][10][15], int, int, int);
void shotsT(int rows, int cols, int plate, long shots[rows][cols][plate], int, int, int);
int main(void) {
    // double trots[20];
    // short clops[10][30];
    // long shots[5][10][15];
    return 0;
}
//a
void trotsT(double trots[20], int i) {
    for (i; i < 20; i++)
        trots[i] = i;
}

void trotsT(int COLS, double trots[COLS], int i) {
    for (i; i < COLS; i++)
        trots[i] = i;
}
//b
void clopsT(short clops[10][30], int i, int j) {
    for (i; i < 10; i++)
        for (j; j < 30; j++)
            clops[i][j] = j;
}
void clopsT(int ROWS, int COLS, short clops[ROWS][COLS], int i, int j) {
    for (i; i < ROWS; i++)
        for (j; j < COLS; j++)
            clops[i][j] = j;
}
//c
void shotsT(long shots[5][10][15], int i, int j , int k) {
    for (i; i < 5; i++)
        for (j; j < 10; j++)
            for (k; k < 15; k++)
                shots[i][j][k] = k;
}
void shotsT(int rows, int cols, int plate, long shots[rows][cols][plate], int i, int j, int k) {
    for (i; i < rows; i++)
        for (j; j < cols; j++)
            for (k; k < plate; k++)
                shots[i][j][k] = k;
}