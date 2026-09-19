/**
 *****=======================值得回顾的代码=================
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXSIZE 256
void showMenu(void);
char getChoice(void);
void processChoice(char ch);
void getStrings(char strList[10][MAXSIZE]);
void putStrings(char strList[10][MAXSIZE]);
void sortByASC(char strList[][MAXSIZE], int rowCount);
void sortByLength(char strList[][MAXSIZE], int rowCount);
void sortByFirstWord(char strList[][MAXSIZE], int rowCount);
int firstWordLength(const char *strList);

char input[10][MAXSIZE];
int main(void) {
    getStrings(input);
    do {
        showMenu();
        processChoice(getChoice());
        //choice(choice1);在 choice 函数内部，修改的是局部参数 ch，跟外面的 choice1 毫无关系。所以 while (choice1 != '5') 永远为真，因为 choice1 始终是 1，程序永远退不出去。
    }while (getChoice() != '5');
    return 0;
}
void showMenu(void) {
    puts("================Menu=================");
    puts("= 1) print original string lists");
    puts("= 2) print string with ASCII");
    puts("= 3) print strings in string length");
    puts("= 4) print string in first word length ");
    puts("= 5) quit");
    puts("=====================================");
}//菜单

char getChoice(void) {
    char ch;
    puts("Enter corresponding number to choose:");
    scanf(" %c", &ch);
    return ch;
}//获取选择

void processChoice(char ch) {
        switch (ch) {
            case '1':
                puts("You choose 1");
                putStrings(input);
                break;
            case '2':
                puts("You choose 2");
                sortByASC(input, 10);
                break;
            case '3':
                puts("You choose 3");
                sortByLength(input, 10);
                break;
            case '4':
                puts("You choose 4");
                sortByFirstWord(input, 10);
                break;
            case '5':
                puts("Looking forward to see you again ^_^");
                break;
            default:
                puts("Warning: \"incorrected intput value! check it again\"");
                break;
        }
}//选择跳转

void getStrings(char strList[10][MAXSIZE])  {
    puts("Please enter 10 strings: ");
    for (int i = 0; i < 10; i++){
        fgets(strList[i], MAXSIZE, stdin);
        strList[i][strcspn(strList[i], "\n")] = '\0';
    }
}//读取字符串

void putStrings(char strList[10][MAXSIZE]) {
    puts("Your input contents are as follows: ");
    for (int i = 0; i < 10; i++)
        printf("%s\n", strList[i]);
}//打印数组

void sortByASC(char strList[][MAXSIZE], int rowCount) {
    int i, j;
    char copy[10][MAXSIZE];
    for (i = 0; i < rowCount; i++)
        strcpy(copy[i], strList[i]);

    for (i = 0; i < rowCount - 1; i++)
        for (j = 0; j < rowCount - 1 - i; j++)
            if (strcmp(copy[j], copy[j + 1]) > 0) {
                char tmp[MAXSIZE];
                strcpy(tmp, copy[j]);
                strcpy(copy[j], copy[j + 1]);
                strcpy(copy[j + 1], tmp);
            }
    putStrings(copy);
}//以ASCII中的顺序打印字符串

void sortByLength(char strList[][MAXSIZE], int rowCount) {
    int i, j;
    char copy[10][MAXSIZE];
    for (i = 0; i < rowCount; i++)
        strcpy(copy[i], strList[i]);

    for (i = 0; i < rowCount - 1; i++)
        for (j = 0; j < rowCount - 1 - i; j++)
            if (strlen(copy[j]) > strlen(copy[j + 1])) {
                char tmp[MAXSIZE];
                strcpy(tmp, copy[j]);
                strcpy(copy[j], copy[j + 1]);
                strcpy(copy[j + 1], tmp);
            }
    putStrings(copy);
}//以长度递增顺序打印字符串

int firstWordLength(const char *strList) {
    int len = 0;
    while (*strList == ' ')
        strList++;
    while (!isspace(*strList)) {
        strList++;
        len++;
    }
    return len;
}//获取第一个单词长度

void sortByFirstWord(char strList[][MAXSIZE], int rowCount) {
    int i, j;
    char copy[10][MAXSIZE];
    for (i = 0; i < rowCount; i++)
        strcpy(copy[i], strList[i]);

    for (i = 0; i < rowCount - 1; i++)
        for (j = 0; j < rowCount - 1 - i; j++)
            if (firstWordLength(copy[j]) > firstWordLength(copy[j + 1])) {
                char tmp[MAXSIZE];
                strcpy(tmp, copy[j]);
                strcpy(copy[j], copy[j + 1]);
                strcpy(copy[j + 1], tmp);
            }
    putStrings(copy);
}//以第一个单词长度打印字符串