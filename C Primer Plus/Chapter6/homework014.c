/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
int main(void) {
    double arr1[8], arr2[8];
    double sum = 0.0;
    int length = sizeof(arr1) / sizeof(arr1[0]);
    for (int i = 0; i < length; i++) {
        printf("Please enter the %d numbers", i);
        scanf("%ld", &arr1[i]);
        sum += arr1[i];
        arr2[i] = sum;
    }
    for (int i = 0; i < length; i++)
        printf("%-5ld", arr1[i]);
    printf("\n");
    for (int i = 0; i < length; i++)
        printf("%-5ld", arr2[i]);

}