/**
 * @author Hexin
 * @version 1.0
 */
#include <stdlib.h>
int countGoodTriplets(int* arr, int arrSize, int a, int b, int c);
int main(void) {

    return 0;
}
int countGoodTriplets(int* arr, int arrSize, int a, int b, int c) {
    int total = 0;
    int *slow;
    int *fast;
    int *toofast;
    for(slow = arr; slow < arr + arrSize; slow++)
        for(fast = slow + 1; fast < arr + arrSize; fast++)
            for(toofast = fast + 1; toofast < arr + arrSize; toofast++)
                if(abs(*slow - *fast) <= a && abs(*fast - *toofast) <= b && abs(*slow - *toofast) <= c)
                    total++;

    return total;
}