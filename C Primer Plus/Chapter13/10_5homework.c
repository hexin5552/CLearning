/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *string = argv[1];
    FILE *fp;
    if (argc == 3) {
        if (fopen(argv[2], "r") == NULL) {
            fprintf(stderr, "Could not open the file, please check.\n");
            exit(EXIT_FAILURE);
        }
        if (strcmp(string, *fp) != '\0') {

        }
    }else {
        fprintf(stderr, "Usage: enter %s and I will check in the %s", string, fp);
        exit(EXIT_FAILURE);
    }
    return 0;
}
