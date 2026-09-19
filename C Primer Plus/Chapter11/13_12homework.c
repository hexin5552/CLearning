/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char *input = (char *)malloc(256 * sizeof(char));
    puts("Please input a string:");
    fgets(input,256,stdin);
    input[strcspn(input, "\n")] = '\0';
    int wordNum = 0, lowerLetterNum = 0, upperLetterNum = 0, digNum = 0, symbolNum = 0;
    int inWord = 0;
    while (*input != '\0') {
        if (islower(*input))
            lowerLetterNum++;
        if (isupper(*input))
            upperLetterNum++;
        if (isdigit(*input))
            digNum++;
        if (*input == ',' || *input == '.' || *input == '!'|| *input == '?')
            symbolNum++;
        if (!isspace(*input)) {
            if (!inWord) {
                wordNum++;
                inWord = 1;
            }
        }else
            inWord = 0;
        input++;
    }
    printf("There are %d words, %d lower, %d upper, %d digit and %d symbols.\n", wordNum, lowerLetterNum, upperLetterNum, digNum, symbolNum);
    free(input);
    return 0;
}