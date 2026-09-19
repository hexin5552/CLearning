/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#include <string.h>
void fanXv(char *str);
int main(void) {
    printf("enter some words\n");
    while (1) {
        char ch[256];
        scanf("%255s", ch);
        if (strcmp(ch,"quit") == 0) break;
        fanXv(ch);
    }
    printf("Bye!\n");
    return 0;
}
void fanXv(char *str) {
    char * s1 = str;
    while (*s1 != '\0') s1++;
    s1--;
    while (s1 >= str) {
        printf("%c", *s1);
        s1--;
    }
    printf("\n");
}