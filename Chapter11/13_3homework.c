/**
 * @author Hexin
 * @version 1.0
 */
#include <ctype.h>
#include <stdio.h>
char * r_word(char * str);
int main(void) {
    return 0;
}
/*
跳过前导空白（空格、制表符、换行符）。
读取连续的非空白字符，存入数组，直到遇到下一个空白或 EOF。
添加字符串结束符 '\0'。
返回数组起始地址，或者在无输入时返回 NULL。
 */
char * r_word(char * str) {
    int ch, i = 0;
    while ((ch = getchar()) != EOF && isspace(ch))
    if (ch == EOF) return NULL;
    while (ch != EOF && !isspace(ch)) {
        str[i++] = (char)ch;
        ch = getchar();
    }

    str[i] = '\0';
    return str;
}