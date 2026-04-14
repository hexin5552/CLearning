/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
int main(void) {
    float nu;
    printf("Please enter a float number");
    scanf("%f",&nu);
    printf("The input is %.1f or %.1e\n",nu,nu);
    printf("The input is %+.3f or %.3E",nu,nu);
}