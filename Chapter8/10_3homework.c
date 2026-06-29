#include <stdio.h>

int main(void) {
    int ch;
    int total = 0;
    while ((ch = getchar()) != EOF) {
        total++;
    }
    printf("\nTotal characters: %d\n", total);
    // 等待回车，防止窗口闪退
    printf("Press Enter to exit...");
    getchar();
    getchar();

    return 0;
}