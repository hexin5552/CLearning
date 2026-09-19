/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#include <stdlib.h>
#include "12diceroll.h"
int roll_count = 0;
static int rollem(int sides) {
    int roll;
    roll = rand() % sides + 1;
    ++roll_count;
    return roll;
}

int roll_n_dice(int dice, int sides) {
    int d;
    int total = 0;
    if (sides < 2) {
        printf("Need at lease 2 sides.\n");
        return -2;
    }
    if (dice < 1) {
        printf("Need at lease 1 dice.\n");
        return -1;
    }

    for (d = 0; d < dice; d++)
        total += rollem(sides);
    return total;
}