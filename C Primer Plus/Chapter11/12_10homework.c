/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#include <string.h>
size_t __cdecl re_len(const char * str);
int main(void) {
    strlen();
    return 0;
}
size_t __cdecl re_len(const char * str) {
    const char * p = str;
    while (*p)
        p++;
    return p - str ;
}