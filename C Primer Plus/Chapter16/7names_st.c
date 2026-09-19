/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#include "6names_st.h"
void show_names(const names * pn) {
    printf("%s %s", pn->first, pn->last);
}
void get_names(names * pn) {
    printf("Please enter your first name: ");
    s_gets(pn->first, SLEN);
    printf("Please enter your last name: ");
    s_gets(pn->last, SLEN);
}
char * s_gets(char * pb, int n) {
    char * ret_val;
    char * find;
    ret_val = fgets(pb, n, stdin);
    if (ret_val) {
        find = strchr(pb, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n');
    }
    return ret_val;
}
// int main(void) {
//     names candidate;
//     get_names(&candidate);
//     printf("Let's welcome ");
//     show_names(&candidate);
//     printf(" to this program!\n");
//     return 0;
// }


