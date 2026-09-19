/**
 * @author Hexin
 * @version 1.0
 */
//addemupPro
#include <stdio.h>
int main(void) {
    int count = 0;
    int sum = 0;
    int num;
    printf("Please enter an integer for the max day\n");
    scanf("%d", &num);
    while (count++ < num)
        sum += count;
    printf("sum = %d",sum);

    return 0;
}