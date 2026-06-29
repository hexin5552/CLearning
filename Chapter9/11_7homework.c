/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>

int wordsNum(char);

int main(void) {
    int ch;
    while ((ch = getchar()) != EOF) {
        int s = wordsNum(ch);
        if (s != -1)
            printf("%c is %d in the alphabet.\n", ch, s);
        else
            printf("%c is not a letter.\n", ch);
    }

    return 0;
}

int wordsNum(char s) {
    if (s >= 'a' && s <= 'z')
        return s - 'a' + 1;
    else if (s >= 'A' && s <= 'Z')
        return s - 'A' + 1;
    else
        return -1;
}
