/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
int main(void) {
    char words[26];
    for (int i = 0; i < sizeof(words); i++)
        scanf("%c", &words[i]);
    for (int i = 0; i < sizeof(words); i++)
        printf("%c", words[i]);

    return 0;
}