/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
int main(void) {
    //T8
    int imate = 2;
    long shot = 53456;
    char grade = 'A';
    float log = 2.71828;
    printf("The odds against the %d were %d to 1.\n",imate,shot);
    printf("A score of %f is not an %c grade.\n",log,grade);

    //T9
    char ch = '\r';
    printf("%d",ch);
    ch = 13;
    printf("\n%d",ch);
    ch = '\015';
    printf("\n%d",ch);
    ch = '\x0d';
    printf("\n%d",ch);


    return 0;
}