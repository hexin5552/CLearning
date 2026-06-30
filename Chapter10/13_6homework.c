/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
void arrange(double *ar, int n);
int main(void) {
    arrange((double []){2.1, 99.2, 12.9, 85.4}, 4);
    return 0;
}
void arrange(double*ar, int n) {
    double temp;
    for (int i = 0; i < n; i++)
        if (ar[i] < ar[i + 1]) {
            temp = ar[i];
            ar[i] = ar[i + 1];
            ar[i + 1] = temp;

        }
    for (int i = 0; i < n; i++)
        printf("%.2f ", ar[i]);
}