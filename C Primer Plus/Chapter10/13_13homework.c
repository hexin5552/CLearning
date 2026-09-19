/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
//a
void Input(double in[3][5]);
//b
void arrAve(double in[][5]);
//c
double allAve(double in[3][5]);
//d
double maxNum(double in[3][5]);
//e
void outPut(double in[3][5]);
int main(void) {
    double input[3][5];
    Input(input);
    for (int i = 0; i < 3; i++)
        arrAve(input + i);
    double result = allAve(input);
    printf("all groups average is %.2lf\n", result);
    printf("the max number is %.2lf\n", maxNum(input));
    outPut(input);
    return 0;
}
//a
void Input(double in[3][5]) {
    int j, i;
    printf("Please enter 3 groups, and every group includes 5 float numbers\n");
    for (i = 0; i < 3; i++)
        for (j = 0; j < 5; j++)
            scanf("%lf", &in[i][j]);
               //getchar(input[i][j]);
}
//b
void arrAve(double in[][5]) {
    float subot;
    int j;
    for (subot = 0.0, j = 0; j < 5; j++)
        subot += (*in)[j];
    printf("the group's average is %.2f\n", subot / j);
}
//c
double allAve(double in[3][5]) {
    double subot = 0.0;
    int i, j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 5; j++)
            subot += in[i][j];
    return subot / 15;
}
//d
double maxNum(double in[3][5]) {
    int i, j;
    double max = 0.0;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 5; j++)
            if (in[i][j] > in[i][j - 1])
                max = in[i][j];
   return max;
}
//e
void outPut(double in[3][5]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++)
            printf("%.2lf ", in[i][j]);
        printf("\n");
    }
}