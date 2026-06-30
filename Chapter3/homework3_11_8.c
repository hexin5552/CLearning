/**
 * @author Hexin
 * @version 1.0
 */
#include<stdio.h>
int main(void) {
    double amount_;
    printf("Enter your amount: ");
    scanf("%lf", &amount_);
    double pintuo = amount_ / 2;
    printf("pintuo = %lf\n", pintuo);
    double angsi = amount_ * 8;
    printf("angsi = %lf\n", angsi);
    double tangshao = amount_ / 16;
    printf("tangshao = %lf\n", tangshao);
    double chashao = amount_ / 48;
    printf("chashao = %lf", chashao);
}