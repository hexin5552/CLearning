/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
int main(void) {
    char ch;

    scanf("%c", &ch);//Go west, young man!
    while (ch != 'g') {
        printf("%c", ch);//Go west, youn
        scanf("%c", &ch);
    }
    return 0;
}