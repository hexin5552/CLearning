/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#define L 3.785
#define METRE 1.609
int main(void) {
    printf("Please enter your journey length and time\n");
    float inch,gallon;
    scanf("%f %f",&inch,&gallon);
    float per_gal = inch / gallon;
    printf("per_gal = %.1f\n",per_gal);
    float metre = inch * METRE;
    float l = gallon * L;
    printf("per_L = %.1f",metre / l);
}