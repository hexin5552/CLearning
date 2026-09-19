/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
void Temperatures(double F){
    const double NUM = 273.16;
    double C = 5.0 / 9.0 * (F - 32.0);
    double K = C + NUM;
    printf("C = %.3lf, K = %.3lf, F = %.3lf", C, K, F);
}

int main(void) {
    double C, F, K;
    int b;
    printf("Please enter a double num: ");
    while (scanf("%lf", &F) == 1 && F > 0){
        //printf("\nPlease enter a double num: ");
        Temperatures(F);
        printf("\nPlease enter a double num: ");
    }

    return 0;
}