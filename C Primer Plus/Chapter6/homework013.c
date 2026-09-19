/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>

int main(void) {
    int arr[8];
    int i = 0;
    for (int i = 0; i < 8; i++)
        arr[i] = 1 << i;
    do {
        printf("%d ", arr[i]);
        i++;
    } while (i < 8);

    return 0;
}
