/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
int maxIndex(double *ar, int num);
int main(void) {
    int indx = maxIndex((double []){1902.1, 2222.0, 8988.3, 9990.2, 199992.1}, 5);
    printf("max index = %d", indx);
    return 0;
}
int maxIndex(double *ar, int num) {
    int index = 0;
    double max = ar[0];
    for (int i = 1; i < num; i++)
        if (ar[i] > max) {
            max = ar[i];
            index = i;
        }
    return index;
}