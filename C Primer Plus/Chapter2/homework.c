/**
 * @author Hexin
 * @version 1.0
 */
/*
 1、c语言基本模块
#include <stdio.h>
int main(void) {
    return 0;
}*/
#include <stdio.h>
void jolly();
void deny();
void br();
void ic();
int main(void) {
    int s = 5;
    s = 56;
    printf("There are %d weeks in a year\n",s);

    int a,b;
    a = 5;
    b = 2;
    b = a;
    a = b;
    printf("%d %d\n",b,a);

    printf("Gustav Mahler\n");
    printf("Gustav\nMahler\n");
    printf("Gustav ");
    printf("Mahler\n");

    int ages = 20;
    int days = ages * 365;
    printf("%d years old have %d days\n",ages,days);

    jolly();
    jolly();
    jolly();
    deny();
    br();
    ic();
    ic();
    return 0;
}
void jolly() {
    printf("For he's a jolly good fellow\n");
}
void deny() {
    printf("Which nobody can deny\n");
}
void br() {
    printf("Brazil,Russia,");
}
void ic() {
    printf("India,China\n");
}
