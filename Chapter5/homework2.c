/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
int main(void) {
    int Int;
    int Int_max;
    printf("Please enter a Integer num.");
    scanf("%d", &Int);
    Int_max = Int + 10;
    while (Int <= Int_max) {
        printf("%d\t",Int);
        Int++;
    }
    printf("That's all.\n");

    return 0;
}