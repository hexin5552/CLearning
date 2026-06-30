/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
int main(void) {
    for (double value = 36; value > 0; value /= 2)
        //printf("%3d", value);//int 36 18 9 4 2 1
        printf("%3.2f\n", value);//double 36 18 9 4.5 2.25
}