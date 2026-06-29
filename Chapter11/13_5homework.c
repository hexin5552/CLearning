#include <stdio.h>
#include <string.h>
/**
 * @author Hexin
 * @version 1.0
 */
const char * search(const char *str, char c);
int main(void) {
    char test[40];
    int i = 0;
    for (; i < 39; i++)
        scanf("%c", &test[i]);
    test[40] = '\0';
    char *index = search(test, 'q');
    if (index != NULL)
        printf("the position is test[%d]", index);
    else printf("Error!");
    return 0;
}
const char * search(const char *str, char c) {
    if (str == NULL) return NULL;
    const char * ptr = str;
    while (*ptr != '\0') {
        if (*ptr == c)
            return ptr;
        ptr++;
    }
    return NULL;
}