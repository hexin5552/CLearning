/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#define MAX 20
char * s_get(char * st, int n);
int main(void) {
    char first[MAX];
    char last[MAX];
    char formal[2 * MAX + 10];
    double prize;

    puts("Enter your first name:");
    s_get(first, MAX);
    puts("Enter your last name:");
    s_get(last, MAX);
    puts("Enter your price money:");
    scanf("%lf", &prize);
    sprintf(formal, "%s, %-19s: $%6.2f\n", last, first, prize);
    puts(formal);
    return 0;
}
char * s_get(char * st, int n) {
    char * retVal;
    int i = 0;
    retVal = fgets(st, n, stdin);
    if (retVal) {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n');
    }
}