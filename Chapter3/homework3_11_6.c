/**
 * @author Hexin
 * @version 1.0
 */
#include<stdio.h>
int main(void) {
    double kuatuo_amount;
    printf("Enter your amount: ");
    scanf("%lf", &kuatuo_amount);
    double water_amount = kuatuo_amount * 6.022e23;
    double molecule_amount = water_amount / 3.0e-23;
    printf("water amount is %e", molecule_amount);
}