/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#include <time.h>

int my_rand(void);

void my_srand(unsigned int seed);

static unsigned int next;

int main(void) {
    unsigned int result[101];
    my_srand(time(NULL));
    for (int i = 0; i <= 100; i++)
        result[i] = my_rand() + 1;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100 - i; j++) {
            if (result[j] < result[j + 1]) {
                unsigned int temp = result[j];
                result[j] = result[j + 1];
                result[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < 100; i++)
        printf("%u ", result[i]);
    return 0;
}

void my_srand(unsigned int seed) {
    next = seed;
}

int my_rand(void) {
    next = next * 1103515245u + 12345u;
    return (unsigned int) (next / 65536000) % 65536 % 10;
}
