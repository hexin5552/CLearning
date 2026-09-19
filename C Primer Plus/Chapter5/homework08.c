/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#define TEN 'g'
#define TEN1 10
int main(void) {
    int n = 0;
    char n1 = 'a';

    while (n++ < TEN1)
        printf("%5d", n);
    printf("\n");

    while (n1 <= TEN){
        printf("%5c", n1);
        n1++;
}
    printf("\n");

    return 0;
}