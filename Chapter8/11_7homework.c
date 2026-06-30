/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#include <ctype.h>
#define RATE1 0.15
#define RATE2 0.20
#define RATE3 0.25

int main(void) {
    char ch;
    double wTime;
    double tSalary = 0.0;
    double tax = 0.0;
    double salary = 0.0;
    double Isalary = 0.0;
    do {
        salary = 0.0;
        printf("*********************************************************************\n");
        printf("Enter the number corresponding to the desired pay rate or action: \n");
        printf("a) $8.75/hr\t\t\tb) $9.33/hr\n");
        printf("c) $10.00/hr\t\t\td) $11.20/hr\nq) quit\n");
        printf("*********************************************************************\n");
        ch = getchar();
        while (getchar() != '\n');
        switch (ch) {
            case 'a':
                if (salary == 0.0)
                    salary = 8.75;
            case 'b':
                if (salary == 0.0)
                    salary = 9.33;
            case 'c':
                if (salary == 0.0)
                    salary = 10.00;
            case 'd':
                if (salary == 0.0)
                    salary = 11.20;
                printf("How many hours do you work?\n");
                while (1) {
                    if (scanf("%lf", &wTime) != 1) {
                        printf("Please enter a correct number! \n");
                        while (getchar() != '\n');
                    }else {
                        while (getchar() != '\n');
                        break;
                    }
                }
                if (wTime > 40)
                    tSalary = 40 * salary + (wTime - 40) * salary * 1.5;
                else
                    tSalary = wTime * salary;
                if (tSalary > 300 && tSalary <= 450)
                    tax = 300 * RATE1 + (tSalary - 300) * RATE2;
                else if (tSalary > 450)
                    tax = 300 * RATE1 + 150 * RATE2 + (tSalary - 450) * RATE3;
                else
                    tax = tSalary * RATE1;
                Isalary = tSalary - tax;
                printf("Your salary is %.2lf before substract tax, tax is %.2lf, salary in hand is %.2lf\n",
                       tSalary, tax, Isalary);
                break;
            case 'q':
                printf("quit\n");
                break;
            default:
                printf("Please enter the correct number\n");
        }
    } while (ch != 'q');
    return 0;
}