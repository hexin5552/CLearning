/**
 * @author Hexin
 * @version 1.0
 */
#include<stdio.h>
int main(void) {
    long age;
    printf("Enter your age: ");
    scanf("%ld", &age);
    long time = age * 3.156e7;
    printf("Your age's time is %lds",time);
}