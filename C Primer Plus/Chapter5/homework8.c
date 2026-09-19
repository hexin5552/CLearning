/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
int main(void) {
    printf("This program computes moduli.\n");
    int first_num;
    int second_num;
    printf("Enter an integer to serve as the second operand: ");
    scanf("%d", &second_num);
    printf("Now enter the first operand: ");
    scanf("%d", &first_num);
    int ans = first_num % second_num;
    printf("%d %% %d is %d\n", first_num, second_num, ans);
    while (first_num > 0){
        printf("Enter the first operand: ");
        scanf("%d", &first_num);
        ans = first_num % second_num;
        printf("%d %% %d is %d\n", first_num, second_num, ans);
    }
    printf("Done\n");

    return 0;
}