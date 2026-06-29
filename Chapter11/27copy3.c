/**
* @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#include <string.h>
#define LIM 5
#define SIZE 40
#define TARSIZE 7
char * s_get(char * st, int i);
int main(void) {
    char qword[LIM][TARSIZE];
    char temp[SIZE];
    int i = 0;
    printf("Enter %d words beginning with q:\n", LIM);
    while (i < LIM && s_get(temp, SIZE)) {
        if (temp[0] != 'q')
            printf("%s doesn't begin with q!\n", temp);
        else {
            strncpy(qword[i], temp, TARSIZE - 1);
            qword[i][TARSIZE - 1] = '\0';
            i++;
        }
    }
    puts("Here are the words accepted:");
    for (i = 0; i< LIM; i++)
        puts(qword[i]);
    return 0;
}
char * s_get(char * st, int i) {
    char * ret_val;
    int num = 0;
    ret_val = fgets(st, i, stdin);
    if (ret_val) {
        while (st[num] != '\n' && st[num] != '\0')
            num++;
        if (st[num] == '\n')
            st[num] = '\0';
        else
            while (getchar() != '\n');
    }
    return ret_val;
}