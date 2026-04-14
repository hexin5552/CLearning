/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#include <string.h>

int main(void) {
    char words[26] ;
    char words1[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < sizeof(words); i++)
        scanf("%c", &words[i]);
    for (int i = sizeof(words) - 1; i > 0; i--)
        printf("%c", words[i]);
    for (int i = strlen(words1) - 1; i > 0; i--)
        printf("%c", words1[i]);
}
