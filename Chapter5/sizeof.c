/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
int main(void) {
    int n = 0;
    size_t intsize = sizeof(int);

    printf("n = %d, b has %zd bytes; all ints have %zd bytes.\n",n ,sizeof n, intsize);

    return 0;
}