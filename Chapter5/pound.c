/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
//void pound(int n);
void pound();
int main(void) {
    int times = 5;
    char ch = '!';
    float fl = 6.0;

    pound(times);
    pound(ch);
    pound((int)fl);
    //pound(fl);

    return 0;
}
void pound(int n) {
    while (n-- > 0)
        printf("#");
    printf("\n");
}