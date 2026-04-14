/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
int main(void) {
    int n;

    printf("Please enter three integers:\n");
    scanf("%*d %*d %d", &n);
    printf("the last integers was %d\n",n);

    return 0;
}