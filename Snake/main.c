/**
 * @author Hexin
 * @version 1.0
 */
#include "snake.h"
int main(void) {
    //去除光标
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = sizeof(cci);
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
    srand(time(NULL));
    initFood();
    initSnake();
    initUI();
    playGame();
    showScore();
    return 0;
}