/**
* @author Hexin
 * @version 1.0
 */
#include <stdio.h>
void interChange(int, int);
int main(void) {
    int x = 5, y = 10;
    printf("Originally x = %d, y = %d.\n", x, y);
    interChange(x, y);
    printf("Now x = %d, y = %d.\n", x, y);
    return 0;
}

void interChange(int u, int v) {
    int temp;
    printf("Originally u = %d, v = %d.\n", u, v);
    temp = u;
    u = v;
    v = temp;
    printf("Now u = %d, v = %d.\n", u, v);
}