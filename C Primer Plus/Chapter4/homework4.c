/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>

int main(void) {
    float height;
    char name[] = " ";
    printf("Please enter your height and name\n");
    scanf("%f %s",&height,name);
    printf("%s, you are %.3f metres tall",name,height / 100);
}