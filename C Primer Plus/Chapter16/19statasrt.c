/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#include <limits.h>
_Static_assert(CHAR_BIT == 16, "16-bit char falsely assumed");
int main(void) {
    puts("char is 16 bits.");
    return 0;
}