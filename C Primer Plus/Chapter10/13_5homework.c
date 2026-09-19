/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
double max(double *ar, int num);
int main(void) {
    double sub = max((double []){2.8, 9.6, 22.1, 82.01, 55.2}, 5);
    printf("substract = %.2f", sub);
    return 0;
}
double max(double *ar, int num) {
    double max = ar[0];
    double min = ar[0];
    double sub;
    for (int i = 0; i < num; i++) {
        if (ar[i] > max)
            max = ar[i];
        else if (ar[i] < min)
            min = ar[i];
    }
    sub = max - min;
    return  sub;
}