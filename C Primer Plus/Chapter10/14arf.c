/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#define SIZE 5
void showArray(const double arr[], int);
void multArray(double arr[], int, double);
int main(void) {
    double dip[SIZE] = { 20.0, 17.66, 8.2, 15.3, 22.22 };
    printf("The original dip array:\n");
    showArray(dip, SIZE);
    multArray(dip, SIZE, 2.5);
    printf("The dip array after calling multArray():\n");
    showArray(dip, SIZE);

    return 0;
}
void showArray(const double arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%8.3f ", arr[i]);
    putchar('\n');
}

void multArray(double arr[], int n, double d) {
    int i;
    for (i = 0; i < n; i++)
        arr[i] *= d;
}