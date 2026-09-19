/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#include <string.h>

int main(void) {
    char name[30];
    int namelenghth = strlen(name);
    printf("Please enter your name");
    scanf("%s",name);
    printf("OK,\"%20s\"\n",name);
    printf("OK,\"%-20s\"\n",name);
    printf("Please enter your name's length\n");
    printf("OK,\"%*s\"",namelenghth + 3,name);
}
