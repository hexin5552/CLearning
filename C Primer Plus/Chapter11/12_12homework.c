/**
 * @author Hexin
 * @version 1.0
 */
#include <string.h>
char * reString(char ** str);
int main(void) {
    return 0;
}
char * reString(char ** str) {
    char *re_str;
    re_str = strchr(*str, ' ');
    if (re_str)
        return re_str;
    else
        return NULL;
}