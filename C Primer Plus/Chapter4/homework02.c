/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#include <string.h>
#define Q "\"His Hamlet was funny without being vuglar.\""
int main(void) {
    printf("He sold the painting for $%.2f.\n",2.345e2);//234.50
    printf("%c%c%c\n",'H', 105,'\41');//Hi！
    printf("\"%s\"\nhas %d characters.\n",Q,strlen(Q));//Q 42
    printf("Is %2.2e the same as %2.2f?\n",1201.0,1201.0);//f
}
