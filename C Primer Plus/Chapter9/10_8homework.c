/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
int maxNum(int, int, int);
int main(void) {
    printf("%d", maxNum(100,21,3));
    return 0;
}
int maxNum(int x, int y, int z) {
    int temp = (x > y ? x : y);
    return temp > z ? temp : z;
}