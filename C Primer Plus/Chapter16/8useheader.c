/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#include "7names_st.c"
int main(void) {
    names candidate;
    get_names(&candidate);
    printf("Let's welcome ");
    show_names(&candidate);
    printf(" to this program!\n");
    return 0;
}