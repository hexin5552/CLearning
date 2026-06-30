#include <stdio.h>
#include <string.h>
/**
 * @author Hexin
 * @version 1.0
 */
char * s_gets(char * str, int n);
int main(void) {
    return 0;
}
char * s_gets(char * str, int n) {
    char * ret_val;
    ret_val = fgets(str, n, stdin);
    if (ret_val) {
        char * n1 = strchr(str, '\n');
        if (n1)
            *n1 = '\0';
        else
            while (getchar() != '\n');
    }
    return ret_val;
}