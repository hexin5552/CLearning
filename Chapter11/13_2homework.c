/**
* @author Hexin
 * @version 1.0
 */
#include <stdio.h>
char *s_gets(char * str, int n);
int main(void) {
    char tmp[40];
    puts("Please enter a sentence");
    s_gets(tmp, 40);
    puts(tmp);
    return 0;
}
char *s_gets(char * str, int n) {
    if (n <= 0) return NULL;
    int i = 0, ch;

    while (i < n - 1) {
        ch = getchar();
        if (ch == EOF) {
            if (i == 0) return NULL;
            break;
        }
        if (ch == '\n' || ch == ' ' || ch == '\t')
            break;
        str[i++] = (char)ch;
    }
    str[i] = '\0';
    return str;
}