/**
* @author Hexin
 * @version 1.0
 */
#include <stdio.h>
int main(void) {
    char ch;

    do
    {
        scanf("%c", &ch);//Go west, young man!
        printf("%c", ch);//Go west, young
    }
    while (ch != 'g');
    return 0;
}