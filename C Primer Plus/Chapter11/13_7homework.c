/**
* @author Hexin
 * @version 1.0
 */
#include <stdio.h>
char * mystrncpy(char *str1, const char *str2, size_t n);
int main(void) {
    char s1[] = "Hello world";
    char * s2 = "USTC";
    char * s3 = mystrncpy(s1, s2, 4);
    s3[4] = '\0';
    puts(s3);
    return 0;
}
char * mystrncpy(char *str1, const char *str2, size_t n) {
    size_t i = 0;
    for (; i < n && str2[i] != '\0'; i++)
        str1[i] = str2[i];

    for (; i < n; i++)
        str1[i] = '\0';
    return str1;
}