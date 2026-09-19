/**
* @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#include "13_3pe12-2a.h"
extern int set_mode(int mode, int preMode);
extern void get_info(double * cost, double * distance, int temp);
extern void show_info(double * cost, double * distance, int temp);
int main(void) {
    int mode, pre_mode = 0;
    double cost;
    double distance;
    printf("Enter 0 for metric mode, 1 for US mode: ");
    scanf("%d", &mode);
    while (mode >= 0) {
        pre_mode = set_mode(mode, pre_mode);
        get_info(&cost, &distance, pre_mode);
        show_info(&cost, &distance, pre_mode);
        printf("Enter 0 for metric mode, 1 for US mode");
        printf(" (-1 to quit): ");
        scanf("%d", &mode);
    }
    printf("Done.\n");
    return 0;
}