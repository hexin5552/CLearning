/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>

int main(void) {
    int i, oddNum = 0, enenNum = 0, oddAve = 0, evenAve = 0;
    scanf("%d", &i);
    while (i != 0) {
        scanf("%d", &i);
        if (i % 2 == 0) {
            enenNum++;
            evenAve += i;
        }
        else{
            oddAve += i;
            oddNum++;
        }
    }
    printf("oddNum = %d, enenNum = %d, oddAve = %d, evenAve = %d",
        oddNum, enenNum, oddAve / oddNum, evenAve / enenNum);
    return 0;
}