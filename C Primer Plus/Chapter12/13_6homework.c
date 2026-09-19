/**
* @author Hexin
 * @version 1.0
 */
#include <stdio.h>

int my_rand(void);

void my_srand(unsigned int seed);

static unsigned int next;

int main(void) {
    unsigned int freq[10] = {0};
    unsigned int user_seed;
    int value;
    printf("Please enter a digit as the outset of function: ");
    scanf("%u", &user_seed);
    my_srand(user_seed);
    for (int i = 0; i < 1000; i++) {
        value = my_rand() + 1;
        freq[value - 1]++;
    }

    for (int i = 0; i < 10; i++)
        printf("Number %2d : %4u times\n", i + 1, freq[i]);

    return 0;
}

void my_srand(unsigned int seed) {
    next = seed;
}

int my_rand(void) {
    next = next * 1103515245u + 12345u;
    return (unsigned int) (next / 65536000) % 65536 % 10;
}
