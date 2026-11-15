#ifndef GAME_H_INCLUDE
#define GAME_H_INCLUDE
/*游戏逻辑模块*/
#include <time.h>
//方块结构体
typedef struct {
    int x, y;
    int shape;
    int status;
    int color;
}BLOCK;
//1.绘制游戏池边框
void windowPrint(int x, int y);
//2.游戏初始化
void gameInit(void);
//3.打印操作说明
void printInfo(int n);
//4.打印分数和等级
void printGradeLevel(int num);
//5.游戏计时功能
void gameTime(clock_t start_time);
//6.打印左边框
void boardLeft(void);
//7.打印方块
 void printBlock(int x, int y, int shape, int status, int color);
 //8.删除方块
 void deleteBlock(int x, int y, int shape, int status);
 //9.产生游戏第一个方块
 void startBlock(void);
 //10.产生下一个方块
 void nextBlock(void);
 //11.拷贝方块
 void copyBlock(void);
 //12.方块下移
 //返回值用于标记方块是否到达游戏池底部
 int downBlock(int n);
 //13.方块左移
 void leftBlock(void);
 //14.方块右移
 void rightBlock(void);
 //15.方块变形
 void changeBlock(void);
 //16.方块直接落底
 int bottomBlock(int n);
 //17.方块检测
 int crash(int x, int y, int shape, int status);
 //18.方块保存
 void save(void);
 //19.刷新游戏池
 void updateGame(int n);
 //20.游戏暂停
 void pauseGame(void);
 //21.消行检测
 void lineClear(void);
 //22.消行下移
 void lineDown(int line);
 //23.游戏结束动画
 void printEnd(void);
 //24.游戏重新开始提示
 void restartInfo(void);
 //25.重新开始游戏
 void restartGame(void);
 //26.游戏结束界面
 void endGame(void);
 //27.打印开始图案
 void printStart(int x, int y);
 //28.清除开始动画
 void deleteStart(int x, int y);
 //29.动画效果控制：定时，边界
 void printAnimation(void);
 //30.游戏模式选择
 void gameMode(float time, int n);
 //31.选择游戏模式界面
 void gameModeChoose(void);
 #endif