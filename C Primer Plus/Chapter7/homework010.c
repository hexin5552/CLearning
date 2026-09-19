/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#define RATE1 0.25
#define RATE2 0.28

int main(void) {
    char ch;
    double salary = 0.0;
    double tax = 0.0;
    do {
        printf("*********************************************************************\n");
        printf("Enter the number corresponding to the desired your kind: \n");
        printf("1) Singlehood\t\t\t2) Householder\n");
        printf("3) Married\t\t\t4) Divorced\n5) quit\n");
        printf("*********************************************************************\n");

        while ((ch = getchar()) == '\n');
        /*
         * 错误使用 while (ch == '\n');：本意可能是“跳过换行符”，但实际写法变成了“如果 ch 是换行符，就无限循环”。
         * 所以得写成while ((ch = getchar()) == '\n');
         */
        switch (ch) {
            case '1':
                printf("Please enter your salary");
                scanf("%lf", &salary);
                if (salary >= 17850)
                    tax = 17850 * RATE1 + (salary - 17850) * RATE2;
                else
                    tax = salary * RATE1;
                printf("You should pay %.4lf taxs\n", tax);
                break;
            case '2':
                printf("Please enter your salary");
                scanf("%lf", &salary);
                if (salary >= 23900)
                    tax = 23900 * RATE1 + (salary - 23900) * RATE2;
                else
                    tax = salary * RATE1;
                printf("You should pay %.4lf taxs\n", tax);
                break;
            case '3':
                printf("Please enter your salary");
                scanf("%lf", &salary);
                if (salary >= 29750)
                    tax = 29750 * RATE1 + (salary - 29750) * RATE2;
                else
                    tax = salary * RATE1;
                printf("You should pay %.4lf taxs\n", tax);
                break;
            case '4':
                printf("Please enter your salary");
                scanf("%lf", &salary);
                if (salary >= 14875)
                    tax = 14875 * RATE1 + (salary - 14875) * RATE2;
                else
                    tax = salary * RATE1;
                printf("You should pay %.4lf taxs\n", tax);
                break;
            case '5':
                printf("see you\n");
                break;
            default:
                printf("Please enter the correct number!\n");
        }
    } while (ch != '5');

    return 0;
}
