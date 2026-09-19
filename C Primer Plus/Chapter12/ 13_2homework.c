/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#include "13_2pe12-2a.h"
extern int set_mode(int mode);
extern void get_info(void);
extern void show_info(void);
double cost;
double distance;
int sub_mode = 0;
int main(void) {
    int mode;
    printf("Enter 0 for metric mode, 1 for US mode: ");
    scanf("%d", &mode);
    while (mode >= 0) {
        sub_mode = set_mode(mode);
        get_info();
        show_info();
        printf("Enter 0 for metric mode, 1 for US mode");
        printf(" (-1 to quit): ");
        scanf("%d", &mode);
    }
    printf("Done.\n");
    return 0;
}