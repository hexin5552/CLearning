/**
* @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#define MONTH 12
#define YEARS 5
void rainFall(float rain[YEARS][MONTH]);
void monthAve(float rain[YEARS][MONTH]);
int main(void) {
    const float rain[YEARS][MONTH] = {
        { 4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6 },
        { 8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3 },
        { 9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4 },
        { 7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2 },
        { 7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2 }
    };
    rainFall(rain);
    monthAve(rain);

    return 0;
}
void rainFall(float rain[YEARS][MONTH]){
    int year;
    int month;
    float subot;
    float total;
    printf(" YEAR      RAINFALL (inches)\n");
    for (total = 0.0,year = 0; year < YEARS; year++) {
        for (subot = 0.0, month = 0; month < MONTH; month++)
            subot += rain[year][month];
        printf("%5d %15.1f\n", 2010 + year, subot);
        total += subot;
    }
    printf("\nThe yearly average is %.1f inches.\n\n", total / YEARS);
}
void monthAve(float rain[YEARS][MONTH]) {
    int month, year;
    float subot;
    printf("MONTHLY AVERAGES:\n\n");
    printf(" Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct  Nov  Dec\n");
    for (month; month < MONTH; month++) {
        for (year = 0, subot = 0; year < YEARS; year++)
            subot += rain[year][month];
        printf("%4.1f ", subot / YEARS);
    }
    printf("\n");
}
/*
 * 原代码的错误根源在于循环控制变量未在嵌套循环中正确重置。
 * 修正方法是确保每个内层循环开始前，其循环变量都从初始值（0）开始。
 * 此外，将累加器作为局部变量而非函数参数，能提高代码可读性并避免误用。
 */