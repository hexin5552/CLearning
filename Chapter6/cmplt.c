/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#include <math.h>
int main(void) {
    const double ANSWER = 3.14150;
    double response;

    printf("What is the value of the pi?\n");
    scanf("%lf",&response);
    while (fabs(response - ANSWER) > 0.0001){
        printf("Try again!\n");
        scanf("%lf", &response);
    }
    printf("Close enough!\n");

    return 0;
}