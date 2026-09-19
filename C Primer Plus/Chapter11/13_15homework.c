/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 256
int myAtoi(char *str);
int main(void) {
    char *str = (char *)malloc(MAXSIZE * sizeof(char));
    while (*str != '\n') {
        puts("Enter a number between 0 and 32767 (inclusive): ");
        fgets(str, MAXSIZE, stdin);
        int res = myAtoi(str);
        printf("The result is %d\n", res);
    }
    free(str);
    return 0;
}
int myAtoi(char *str) {
    int sign = 1;
    int result = 0;
    while (*str == ' ') str++;//跳过开头空格
    if (*str == '-') {
        sign = -1;
        str++;
    }else if (*str == '+')
        str++;

    while (*str != '\0') {
        if (*str >= '0' && *str <= '9') {
            result = result * 10 + (*str - '0');
            str++;
        }else{
            result = result * 10 + 0;//遇到非数字部分则返回已处理部分
            str++;
        }
    }
    return result * sign;
}