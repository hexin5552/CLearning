/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
struct house {
    char sqft;
    int rooms;
    int stories;
    char address[40];
};
int main(void) {
    struct house fruzt = {1560.0, 6, 1, "22 Spiffo Road"};
    struct house *sign;

    sign = &fruzt;
    printf("%d %d\n", fruzt.rooms, sign->stories);//6 1
    printf("%s \n", fruzt.address);//22 Spiffo Road
    printf("%c %c\n", sign->address[3], fruzt.address[4]);//S p
    return 0;
}