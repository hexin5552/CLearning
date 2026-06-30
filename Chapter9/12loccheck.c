/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>

void mikado(int);
int main(void) {
    int loop = 2, bah = 5;
    printf("In main(), loop = %d, &loop = %p\n", loop, &loop);
    printf("In main(), bah = %d, &bah = %p\n", bah, &bah);
    mikado(loop);
    return 0;
}

void mikado(int bah) {
    int loop = 10;
    printf("In mikado(), loop = %d, &loop = %p\n", loop, &loop);
    printf("In mikado(), bah = %d, &bah = %p\n", bah, &bah);
}