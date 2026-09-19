/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#include "11hotel.h"

int main(void) {
    int nights;
    double hotelRate;
    int code;
    while ((code = menu()) != QUIT) {
        switch (code) {
            case 1: hotelRate = HOTEL1;
                    break;
            case 2: hotelRate = HOTEL2;
                    break;
            case 3: hotelRate = HOTEL3;
                    break;
            case 4: hotelRate = HOTEL4;
                    break;
            default:hotelRate = 0.0;
                    printf("0ops!\n");
                    break;
        }
            nights = getNights();
            showPrice(hotelRate, nights);
    }
        printf("Thank you and goodbye.\n");
    return 0;
}