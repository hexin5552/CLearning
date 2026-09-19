/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LEN 81
char * s_gets(char * ptr, int n);
char showmenu(void);
void eatline(void);
void show(void(*fp)(char *), char * ptr);
void toUpper(char *);
void toLower(char *);
void Transpose(char *);
void Dummy(char *);

int main(void) {
    char line[LEN];
    char copy[LEN];
    char choice;
    void (*pfun)(char *);
    puts("Enter a string (empty line to quit):");
    while (s_gets(line, LEN) != NULL && line[0] != '\0') {
        while ((choice = showmenu()) != 'n') {
            switch (choice) {
                case 'u': pfun = toUpper; break;
                case 'l': pfun = toLower; break;
                case 't': pfun = Transpose; break;
                case 'o': pfun = Dummy; break;
            }
            strcpy(copy, line);
            show(pfun, copy);
        }
        puts("Enter a string (empty line to quit):");
    }
    puts("Bye!");
    return 0;
}
char * s_gets(char * ptr, int n) {
    char * ret_val, * find;
    ret_val = fgets(ptr, n, stdin);
    if (ret_val) {
        find = strchr(ret_val, '\n');
        if (find)
            *find = '\0';
        else
            eatline();
    }
    return ret_val;
}
char showmenu(void) {
    char ans;
    puts("Enter menu choice:");
    puts("u) uppercase      l) lowercase");
    puts("t) transposed case o) original case");
    puts("n) next string");
    ans = getchar();
    ans = tolower(ans);
    eatline();
    while (strchr("ulton", ans) == NULL) {
        puts("Please enter a u, l, t, o, or n:");
        ans = tolower(getchar());
        eatline();
    }
    return ans;
}
void eatline(void){
    while (getchar() != '\n');
}
void show(void(*fp)(char *), char * ptr){
    (*fp)(ptr);
    puts(ptr);
}
void toUpper(char * str){
    while (*str) {
        *str = toupper(*str);
        str++;
    }
}
void toLower(char * str){
    while (*str) {
        *str = tolower(*str);
        str++;
    }
}
void Transpose(char * str){
    while (*str) {
        if (islower(*str))
            *str = toupper(*str);
        else if (isupper(*str))
            *str = tolower(*str);
        str++;
    }
}
void Dummy(char * str) {}
