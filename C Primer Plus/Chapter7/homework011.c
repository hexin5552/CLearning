/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#define YJ 2.05
#define TC 1.15
#define HLB 1.09
#define FEE1 6.5
#define FEE2 14
#define FEE3 0.5

int main(void) {
    int index;
    char ch;
    double totalPound = 0.0;
    double sum = 0.0;
    double totalFee = 0.0;
    double inTotal = 0.0;
    double totalWrap = 0.0;
    double discount = 0.0;
    int digit;

    do {
        printf("*********************************************************************\n");
        printf("Enter the letter corresponding to the desired your kind: \n");
        printf("a) artichoke\t\t\tb) beet\n");
        printf("c) carrot\t\t\tq) quit\n");
        printf("*********************************************************************\n");
        while ((ch = getchar()) == '\n');
        switch (ch) {
            case 'a':
                index = 1;
                printf("You choose to buy artichoke, how many pound do you want to buy?\n");
                printf("You can check in pounds you want to buy all the way (q to quit).");
                while ((scanf("%lf", &totalPound)) == 1)
                    sum += totalPound;
                totalPound = sum;
                totalFee = totalPound * YJ;
                if (getchar() == 'q') {
                    ch = 'q';
                    break;
                }
                break;
            case 'b':
                index = 2;
                printf("You choose to buy beet, how many pound do you want to buy?\n");
                printf("You can check in pounds you want to buy all the way (q to quit).");
                while ((scanf("%lf", &totalPound)) == 1)
                    sum += totalPound;
                totalPound = sum;
                totalFee = totalPound * TC;
                if (getchar() == 'q') {
                    ch = 'q';
                    break;
                }
                break;
            case 'c':
                index = 3;
                printf("You choose to buy carrot, how many pound do you want to buy?\n");
                printf("You can check in pounds you want to buy (q to quit).");
                while ((scanf("%lf", &totalPound)) == 1)
                    sum += totalPound;
                totalPound = sum;
                totalFee = totalPound * HLB;
                if (getchar() == 'q') {
                    ch = 'q';
                    break;
/*
用户选择蔬菜（如 a），进入 case 'a'。
内层循环 while ((scanf("%lf", &totalPound)) == 1) 要求输入磅数，用户输入 q 退出循环。
关键：输入 q 后，scanf 返回0，循环结束，但字符 'q' 仍留在输入缓冲区中，而外层的 ch 变量仍然是 'a'（未改变）。
跳出 switch，循环条件判断 while (ch != 'q') → 'a' != 'q' 为真，继续下一次循环。
再次打印菜单，然后 while ((ch = getchar()) == '\n'); 读取到缓冲区中的 'q'，此时 ch = 'q'，进入 case 'q'，
然后循环条件判断退出。因此多打印了一次菜单，感觉需要多循环一次才退出。
修正方案：
在内层循环检测到非数字输入（即用户输入 q 或其它字母）时，立即将 ch 设置为 'q' 并跳出外层循环*/
                }
                break;
            case 'q':
                break;
            default:
                printf("Please enter a correct digit.\n");
        }
    } while (ch != 'q');

    if (totalPound <= 5 && totalPound > 0)
        totalWrap = FEE1;
    else if (totalPound > 5 && totalPound <= 20)
        totalWrap = FEE2;
    else
        totalWrap = FEE2 + (totalPound - 20) * FEE3;

    digit = (int) totalFee / 100;
    discount = 5 * digit;

    inTotal = totalFee + totalWrap - discount;

    if (index == 1)
        printf("You choose buy artichoke, it's sold at $%.2lf, you booked %.2lf pounds, "
               "you bought vegetable fees are $%.2lf\ngive you $%.2lf in discount, "
               "package fee is $%.2lf, all the fees are $%.2lf in total.", YJ, totalPound, totalFee, discount, totalWrap,
               inTotal);
    else if (index == 2)
        printf("You choose buy beet, it's sold at $%.2lf, you booked %.2lf pounds, "
               "you bought vegetable fees are $%.2lf\ngive you $%.2lf in discount, "
               "package fee is $%.2lf, all the fees are $%.2lf in total.", TC, totalPound, totalFee, discount, totalWrap,
               inTotal);
    else if (index == 3)
        printf("You choose buy carrot, it's sold at $%.2lf, you booked %.2lf pounds, "
               "you bought vegetable fees are $%.2lf\ngive you $%.2lf in discount, "
               "package fee is $%.2lf, all the fees are $%.2lf in total.", HLB, totalPound, totalFee, discount, totalWrap,
               inTotal);
    else
        printf("You don't buy any thing.\n");
    return 0;
}
