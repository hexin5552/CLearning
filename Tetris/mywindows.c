/**
 * @author Hexin
 * @version 1.0
 */
/*实现系统调用模块*/
#include "mywindows.h"

#include <stdbool.h>

HANDLE handle;
//1.初始化句柄
void initHandle(void) {
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    // 源文件为 UTF-8 编码，将控制台代码页设为 UTF-8，
    // 避免方块字符(■)等宽字符因 GBK 解码错位而显示变形
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    hideCursor();
}
//2、设置颜色
void setColor(int color) {
    SetConsoleTextAttribute(handle, color);
}
//3、设置光标位置
void setPos(int x, int y) {
    COORD coord = {x * 2, y};
    SetConsoleCursorPosition(handle, coord);
}
//3.1、设置光标位置(半角坐标,1字符=1列,用于ASCII装饰画)
void setPosASCII(int x, int y) {
    COORD coord = {x, y};
    SetConsoleCursorPosition(handle, coord);
}
//4、隐藏光标
void hideCursor(void) {
    CONSOLE_CURSOR_INFO info;
    info.bVisible = false;//设置光标是否可见
    info.dwSize = 1;//设置光标宽度：1-100
    SetConsoleCursorInfo(handle, &info);
}