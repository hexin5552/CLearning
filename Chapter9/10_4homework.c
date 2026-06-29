/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
int sum(int, int);
int main(void) {
    printf("%.2lf",sum(10.0, 2.9));
    return 0;
}
int sum(int x, int y) {
    return x + y;
}