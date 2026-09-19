/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#define RATE1 0.15
#define RATE2 0.20
#define RATE3 0.25
#define SALARY 10.00
int main(void) {
    double wTime = 0.0;
    double tSalary = 0.0;
    double tax = 0.0;
    double salary = 0.0;
    printf("Please enter how many times do you work a week: ");
    scanf("%lf", &wTime);
    if (wTime > 40)
        tSalary = 40 * SALARY + (wTime - 40) * SALARY * 1.5;
    else
        tSalary = wTime * SALARY;

    if (tSalary > 300 && tSalary <= 450)
        tax = 300 * RATE1 + (tSalary - 300) * RATE2;
    else if (tSalary > 450)
        tax = 300 * RATE1 + 150 * RATE2 + (tSalary - 450) * RATE3;
    else
        tax = tSalary * RATE1;

    salary = tSalary - tax;
    printf("Your salary is %.2lf before substract tax, tax is %.2lf, salary in hand is %.2lf", tSalary, tax, salary);
    return 0;
}