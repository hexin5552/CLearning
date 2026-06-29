/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#include <stdbool.h>
int is_within(char *str, char ch);
int main(void) {
    char *tmp = "qsi19edaoi";
    char ch = 0;
    printf("Please enter a digit to find wherever it\n");
    while (1) {
        ch = getchar();
        while (getchar() != '\n');
        if (ch == '0') break;
        int b = is_within(tmp, ch);
        if (b >= 0)
            printf("Yes, I find it! its position is temp[%d]\n", b);
        else
            puts("Sorry, I don't find it ^_^");
    }
    printf("Bye");
    return 0;
}
int is_within(char *str, char ch) {
    int index = 0;
    while (*str != '\0') {
        if (*str == ch)
            return index;
        str++;
        index++;
    }
    return -1;
}