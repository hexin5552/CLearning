/**
 * @author Hexin
 * @version 1.0
 */
#ifndef CLION_SNAKE_H
#define CLION_SNAKE_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#define WIDTH 60    //长度
#define HIGH 20     //高度
//身体对象
struct BODY {
    int x;
    int y;
};

//蛇对象
struct SNACK {
    struct BODY body[WIDTH * HIGH];
    int size;
};

//食物对象
struct FOOD {
    int x;
    int y;
};

// 外部声明，告诉编译器变量在别的c文件
extern int key_x, key_y;
extern int score;
extern int sleepSecond;
extern struct BODY body;
extern struct SNACK snake;
extern struct FOOD food;
extern int last_x;
extern int last_y;
void initSnake(void);
void initFood(void);
void initUI(void);
void playGame(void);
void initWall(void);
void showScore(void);
#endif //CLION_SNAKE_H
