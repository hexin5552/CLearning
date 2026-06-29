/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#include <string.h>
#define ANSWER "Grant"
#define SIZE 40
char * s_gets(char * st, int n);
int strCom(const char * st, const char * pt);
int main(void) {
    char try[SIZE];
    puts("Who is buried in Grant's tomb?");
    s_gets(try, SIZE);
    //所以需要定义一个函数来进行字符串的值的比较
    while (strCom(try, ANSWER)) {
        puts("No, that's wrong. Try again.");
        s_gets(try, SIZE);
    }
    //try和answer都是指针，进行比较的是2个指针的地址，而2个指针存储位置不相同，所以无论输入什么都是不对的
    // while (try != ANSWER) {
    //     puts("No, that's wrong. Try again.");
    //     s_gets(try, SIZE);
    // }

    puts("That's right");

    return 0;
}
char * s_gets(char * st, int n) {
    char * ret_val;
    int i = 0;
    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n');
    }
    return ret_val;
}
int strCom(const char * st, const char * pt) {
    int i = 0;
    while (st[i] != '\0' && pt[i] != '\0') {
        if (st[i] != pt[i])
            return 0;
        i++;
    }
    return (st[i] == '\0' && pt[i] == '\0');
}