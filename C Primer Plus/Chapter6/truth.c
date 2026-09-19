/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
int main(void) {
    int  n =3;

    while (n)
        printf("%2d is true\n", n--);
    printf("%2d is flase\n", n);

    n = -3;
    while (n)
        printf("%2d is true\n", n++);
    printf("%2d is flase\n", n);

    return 0;
}