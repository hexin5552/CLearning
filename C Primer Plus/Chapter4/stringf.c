/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#define BLURB "Authentic imitation!"
int main(void) {
    const char name[13] = "jasdxcaswqsd";
    const double cash = 112.3021;

    printf("My %.4s family just may be $%6.2f dollars richer!\n",name, cash);
    printf("[%2s]\n",BLURB);
    printf("[%24s]\n",BLURB);
    printf("[%24.5s]\n",BLURB);
    printf("[%-24.5s]\n",BLURB);

    return 0;
}