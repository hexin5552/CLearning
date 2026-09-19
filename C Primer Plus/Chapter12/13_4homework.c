/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
int use_times(void);
int times = 0;
int main(void) {
    for (int i = 1; i < 100; i++)
        use_times();
    printf("use_times totally use %d times", use_times());
    return 0;
}
int use_times(void) {
    extern int times;
    times++;
    return times;
}