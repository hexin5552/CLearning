/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
int main(void) {
    int num1 = 10;
    int num11 = 188;
    float num2 = 232.346;
    char num3[30] = "jsiajlw";

    printf("This is a integer %2dww\n",num1);
    printf("This is integer %4Xqq\n",num11);
    printf("This is %10.3fqqq\n",num2);
    printf("This is a string %-30shaha\n",num3);

    return 0;
}