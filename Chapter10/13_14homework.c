/**
 * @author Hexin
 * @version 1.0
*/
#include <stdio.h>
//a
void Input(int n, int m, double in[n][m]);
//b
void arrAve(int m, double in[][m]);
//c
double allAve(int n, int m, double in[n][m]);
//d
double maxNum(int n, int m, double in[n][m]);
//e
void outPut(int n, int m, double in[n][m]);
int main(void) {
    double input[3][5];
    Input(3, 5, input);
     for (int i = 0; i < 3; i++)
         arrAve(5, input + i);
     double result = allAve(3, 5, input);
     printf("all groups average is %.2lf\n", result);
     printf("the max number is %.2lf\n", maxNum(3, 5, input));
     outPut(3, 5, input);
    return 0;
}
//a
void Input(int n, int m, double in[n][m]) {
    int j, i;
    printf("Please enter %d groups, and every group includes %d float numbers\n", n, m);
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%lf", &in[i][j]);
}
//b
void arrAve(int m, double in[][m]){
    double subot;
    int j;
    for (subot = 0.0, j = 0; j < m; j++)
        subot += (*in)[j];
    printf("the group's average is %.2f\n", subot / j);
}
//c
double allAve(int n, int m, double in[n][m]) {
    double subot = 0.0;
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            subot += in[i][j];
    return subot / (n * m);
}
//d
double maxNum(int n, int m, double in[n][m]){
    int i, j;
    double max = 0.0;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            if (in[i][j] > max)
                max = in[i][j];
    return max;
}
//e
void outPut(int n, int m, double in[n][m]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%.2lf ", in[i][j]);
        printf("\n");
    }
}
