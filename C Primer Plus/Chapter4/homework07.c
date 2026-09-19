/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
int main(void) {
    unsigned long num1 = 655367900;
    int num = 810;
    float num3 = 232.346;
    char num4[8] = "jackkhuiibibigyugm";

    printf("an unsigned long %15lu\n",num1);
    printf("an 16 %#4x\n",num);
    printf("an float num %-12.2Ej\n",num3);
    printf("an float num %+10.3f\n",num3);
    printf("an string %.8s",num4);
}