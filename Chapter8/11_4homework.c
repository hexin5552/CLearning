/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int ch;
    int numLetters = 0;
    int numWords = 0;
    bool isWord = false;
    while ((ch = getchar()) != EOF) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            numLetters++;
            isWord = true;
        } else if ((ch == ' ' || ch == '\n' || ch == '\t')) {
            //else if ((ch == ' ' || ch == '\n' || ch == '\t') && isWord)判断条件太苛刻
            if (isWord) {
                isWord = false;
                numWords++;
            }
        } else {
            if (isWord) {
                numWords++;
                isWord = false;
            }
        }
    }
    if (isWord) {
        numWords++;
        isWord = false;
    }
    double average =0.0;
    if (numWords > 0)
       average = (double) numLetters / numWords;
    printf("In this text, words numbers are %d, letters numbers are %d\n", numWords, numLetters);
    printf("%.2f letters in each words.", average);
    return 0;
}
