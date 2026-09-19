/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
int main (void) {
    int x = 100;
    long int estine;
    long johns;
    short int erns;
    short ribs;
    unsigned int s_count;
    unsigned players;
    unsigned long headcount;
    unsigned short yesvotes;
    long long ago;
    printf("dec = %d; octal = %o; hex = %x\n", x,x,x);//%o 以八进制形式输出,%x以十六进制形式输出
    printf("dec = %d; octal = %#o; hex = %#x\n", x,x,x);//若需要显示0和0x前缀，在转换前加#
    return 0;
}