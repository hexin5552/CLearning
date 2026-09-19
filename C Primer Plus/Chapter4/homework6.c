/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#include <string.h>

int main(void) {
    char name[20];
    char namee[21];

    printf("Please enter your name and namee\n");
    scanf("%s %s",name,namee);
    int name_lenght = strlen(name);
    int namee_lenght = strlen(namee);
    printf("%s %s\n",name,namee);
    printf("%*d %*d\n",name_lenght,name_lenght,namee_lenght,namee_lenght);

    printf("%s %s\n",name,namee);
    printf("%-*d %-*d",name_lenght,name_lenght,namee_lenght,namee_lenght);
}
