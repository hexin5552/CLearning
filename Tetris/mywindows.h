#ifndef CLION_MYWINDOWS_H
#define CLION_MYWINDOWS_H
/*系统调用模块*/
#include <windows.h>
//函数声明
//1、初始化句柄
void initHandle(void);
//2、设置颜色
void setColor(int color);
//3、设置光标位置
void setPos(int x, int y);
//3.1、设置光标位置(半角坐标,1字符=1列,用于ASCII装饰画)
void setPosASCII(int x, int y);
//4、隐藏光标
void hideCursor(void);

#endif //CLION_MYWINDOWS_H
