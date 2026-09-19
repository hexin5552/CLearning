/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ARSIZE 1000
int main(void) {
    double numbers[ARSIZE];
    double value;
    FILE * iofile;
    const char * file = "6numbers.dat";
    int i;
    long pos;
    for (i = 0; i < ARSIZE; i++)
        numbers[i] = 100.0 * i + 1.0 / (i + 1);
    if ((iofile = fopen(file, "wb")) == NULL) {
        fprintf(stderr, "Could not open %s for output", file);
        exit(EXIT_FAILURE);
    }
    fwrite(numbers, sizeof(double), ARSIZE, iofile);
    fclose(iofile);
    if ((iofile = fopen(file, "rb")) == NULL) {
        fprintf(stderr, "Could not open %s for random access", file);
        exit(EXIT_FAILURE);
    }
    printf("Enter an index in the range of 1 - %d.\n", ARSIZE - 1);
    while (scanf("%d", &i) == 1 && i >= 0 && i < ARSIZE) {
        pos = (long) i * sizeof(double);
        fseek(iofile, pos, SEEK_SET);
        fread(&value, sizeof(double), 1, iofile);
        printf("The value there is %lf.\n", value);
        printf("Next index (out of range to quit):\n");
    }
    fclose(iofile);
    puts("Bye");
    return 0;
}