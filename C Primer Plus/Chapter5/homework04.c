/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
int main(void) {
    int i = 1;
    float n;
    printf("Watch out! Here come a bunch of fractions!\n");
    while (i < 30) {
        n = 1 / i;
        i++;
        printf("%2.2f\n",n);
    }
    printf("That's all,folks\n");

    return 0;
}