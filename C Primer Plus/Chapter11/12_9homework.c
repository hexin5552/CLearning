/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
char *s_gets(char * str, int n);
int main(void) {
    return 0;
}
char *s_gets(char * str, int n) {
    char * ret_val;
    ret_val = fgets(str, n, stdin);
    if (ret_val) {
        while (*str != '\n' && *str != '\0')
            str++;
        if (*str == '\n')
            *str = '\0';
        else
            while (getchar() != '\n');
    }
    return ret_val;

}