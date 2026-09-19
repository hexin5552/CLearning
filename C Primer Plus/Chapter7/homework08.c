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
        printf("1) $8.75/hr\t\t\t2) $9.33/hr\n");
        printf("3) $10.00/hr\t\t\t4) $11.20/hr\n5) quit\n");
        printf("*********************************************************************\n");
        ch = getchar();
        /*不可取方案
         *if (isspace(ch))
         *  continue;
continue 只是跳过本次循环的剩余代码，并不会重新等待用户输入。
残留的换行符 \n 仍然被读入 ch，导致一次无效循环（只打印菜单，不做任何处理）。
更糟的是，如果用户输入了多个空白字符（例如 "1 \n"），每个空格或换行都会触发一次无效循环，菜单会反复闪烁。*/
        while (getchar() != '\n');
        switch (ch) {
            case '1':
                if (salary == 0.0)
                    salary = 8.75;
            case '2':
                if (salary == 0.0)
                    salary = 9.33;
            case '3':
                if (salary == 0.0)
                    salary = 10.00;
            case '4':
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
                    continue;
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
                while (getchar() != '\n');
                break;
            case '5':
                printf("quit\n");
                break;
            default:
                printf("Please enter the correct number\n");
        }
    } while (ch != '5'); //5必须用''包裹，否则就是整数5而不是字符5，如果是整数5，则会把char对照ascall码转换成整数比较，这会使得循环一直成立
    return 0;
}