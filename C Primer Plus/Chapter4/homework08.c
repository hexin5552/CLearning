/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
int main(void) {
    int num1 = 1220;
    int num2 = 20;
    char num3 = 'y';
    float num4 = 3.13;
    char num5[10] = "dfsdwwqwsa";

    printf("%6.4ds\n",num1);
    printf("%8os\n",num2);
    printf("%2ck\n",num3);
    printf("%+4.2fs\n",num4);
    printf("%-7.5ss\n",num5);

    return 0;
}