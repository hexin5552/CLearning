/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#include <string.h>

const char *string_in(const char * str1, const char * str2);
int main(void) {
    char string[] = "Hello my name is JayChou";
    char ch[256];
    //不能是char * ch，因为未分配地址，也未指向任何位置，无法读入数据，是未初始化的野指针
    puts("Enter some words to find weather in sentence or not");

    while (1) {
        scanf("%255s", ch);
        if (strcmp(ch, "quit") == 0) break;
        const char * res = string_in(string, ch);
        if (res != NULL)
            printf("I find it, its position is %p", res);
        else
            puts("Sorry, I don't find it, please check it again");
    }
    return 0;
}
const char *string_in(const char * str1, const char * str2) {
    if (*str2 == '\0') return NULL;
    while(*str1 != '\0') {
        const char *p, *l;
        p = str1;
        l = str2;
        while (*p == *l && *p != '\0' && *l != '\0') {
            p++;
            l++;
        }
        if (*l == '\0') return str1;
        str1++;
    }
    return NULL;
}