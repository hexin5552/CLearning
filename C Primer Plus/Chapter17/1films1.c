/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#include <string.h>
#define TSIZE 45
#define FMAX 5
struct film {
    char title[TSIZE];
    int rating;
};
char * s_gets(char * st, int n);
int main(void) {
    struct film movies[FMAX];
    int i = 0;
    int j;

    puts("Enter first movie title:");
    while (i < FMAX && s_gets(movies[i].title, TSIZE) != NULL && movies[i].title[0] != '\0') {
        puts("Enter your rating <0-10>:");
        scanf("%d", &movies[i++].rating);
        while (getchar() != '\n');
        puts("Enter next movie title (empty line to stop):");
    }
    if (i == 0)
        printf("No data entered. ");
    else
        printf("Here is the movie list:\n");

    for (j = 0; j < i; j++)
        printf("Movie: %s Rating: %d\n", movies[i].title, movies[i].rating);
    printf("Bye.\n");
    return 0;
}
char * s_gets(char * st, int n) {
    char * re_val;
    char * find;
    re_val = fgets(st, n, stdin);
    if (re_val) {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n');
    }
    return re_val;
}