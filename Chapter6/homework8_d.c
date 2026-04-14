/**
* @author Hexin
 * @version 1.0
 */
#include <stdio.h>
int main(void) {
    char ch;

    scanf("%c", &ch);//Go west, young man!
    for (ch = '$'; ch != 'g'; scanf("%c", &ch)) {
        printf("%c", ch);//$o west, youn
    }
    return 0;
}