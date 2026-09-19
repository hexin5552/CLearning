/**
 * @author Hexin
 * @version 1.0
 */
#include <ctype.h>
char* toLowerCase(char* s);
int main(void) {
    return 0;
}
char* toLowerCase(char* s) {
    for(int i = 0; s[i] != '\0'; i++)
        s[i] = tolower(s[i]);
    return s;
}