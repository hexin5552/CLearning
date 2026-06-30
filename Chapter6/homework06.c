/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
int main(void) {
    int MAX, MIN;
    scanf("%d %d", &MIN, &MAX);
    for (int i = MIN; i <= MAX; ++i) {
        printf("%5d %5d %5d\n", i, i * i, i * i * i);
    }

    return 0;
}