/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>

int main(void) {
    int friendNumber = 5;
    for (int i = 1; (friendNumber - i) * 2 < 150; ++i) {
        friendNumber -= i;
        friendNumber *= 2;
        printf("The %d week, Rabnud's friend are %d\n", i, friendNumber);
    }
    return 0;
}
