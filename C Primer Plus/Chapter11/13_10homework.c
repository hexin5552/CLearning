/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#include <stddef.h>
#include <string.h>
void deleteSpace(char *str);
int main(void) {
    char sq[256];
    while (1) {
        printf("Enter a whole sentence\n");
        fgets(sq, sizeof(sq), stdin);
        if (strcmp(sq, "quit\n") == 0) break;
        printf("original strings: %s\n", sq);
        deleteSpace(sq);
        printf("delete space: %s\n", sq);
    }
    return 0;
}
void deleteSpace(char *str) {
    if (str == NULL) return;
    char *spr = str;
    char *dsr = str;
    while (*spr != '\0') {
        if (*spr != ' ') {
            *dsr = *spr;
            dsr++;
        }
        spr++;
    }
    *dsr = '\0';
}