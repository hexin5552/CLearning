/**
 * @author Hexin
 * @version 1.0
 */
#include "snake.h"
//用户按下aswd任意值所得到的坐标
int key_x = 1;
int key_y = 0;
int last_x = 0;
int sleepSecond = 400;
int last_y = 0;
//分数
int score = 0;
struct BODY body;
struct SNACK snake;
struct FOOD food;

void initSnake(void) {
    snake.size = 2;
    snake.body[0].x = WIDTH / 2; //初始化蛇头
    snake.body[0].y = HIGH / 2;

    snake.body[1].x = WIDTH / 2 - 1; //初始化一节蛇身
    snake.body[1].y = HIGH / 2;
}

void initFood(void) {
    food.x = rand() % (WIDTH - 2) + 1;
    food.y = rand() % (HIGH - 2) + 1;
}

void initUI(void) {
    //画蛇
    COORD coord = {0};
    initWall();
    for (size_t i = 0; i < snake.size; i++) {
        coord.X = snake.body[i].x;
        coord.Y = snake.body[i].y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        if (i == 0)
            putchar('@');
        else
            putchar('*');
    }
    //去除蛇尾
    coord.X = last_x;
    coord.Y = last_y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    putchar(' ');
    //画食物
    coord.X = food.x;
    coord.Y = food.y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    putchar('$');
}

void playGame(void) {
    char key = 'd';
    while (snake.body[0].x >= 1 && snake.body[0].x < WIDTH - 1 && snake.body[0].y >= 1 && snake.body[0].y < HIGH - 1) {
        initUI();
        //接受用户按键输入
        if (kbhit())
            //为真则用户有输入
            key = getch(); //不阻塞的接收用户输入
        switch (key) {
            case 'w':
                key_x = 0;
                key_y = -1;
                break;
            case 's':
                key_x = 0;
                key_y = 1;
                break;
            case 'a':
                key_x = -1;
                key_y = 0;
                break;
            case 'd':
                key_x = 1;
                key_y = 0;
                break;
        }
        //蛇撞身体
        for (size_t i = 1; i < snake.size; i++)
            if (snake.body[0].x == snake.body[i].x && snake.body[0].y == snake.body[i].y)
                return;
        if (snake.body[0].x == food.x && snake.body[0].y == food.y) {
            initFood();             //食物消失
            snake.size++;           //身体增长
            score += 1;             //加分
            sleepSecond -= 20;      //加速
        }
        last_x = snake.body[snake.size - 1].x;
        last_y = snake.body[snake.size - 1].y;
        //蛇移动
        for (size_t i = snake.size - 1; i > 0; i--) {
            snake.body[i].x = snake.body[i - 1].x;
            snake.body[i].y = snake.body[i - 1].y;
        }
        //蛇头根据用户的按照用户的设置跑
        snake.body[0].x += key_x;
        snake.body[0].y += key_y;
        Sleep(sleepSecond);
    }
    system("cls");
}

void initWall(void) {
    COORD coord = {0};
    // 上边框 y=0
    for (int x = 0; x < WIDTH; x++) {
        coord.X = x;
        coord.Y = 0;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        putchar('#');
    }
    // 下边框 y = HIGH - 1
    for (int x = 0; x < WIDTH; x++) {
        coord.X = x;
        coord.Y = HIGH - 1;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        putchar('#');
    }
    // 左边框 x=0
    for (int y = 1; y < HIGH - 1; y++) {
        coord.X = 0;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        putchar('#');
    }
    // 右边框 x = WIDTH - 1
    for (int y = 1; y < HIGH - 1; y++) {
        coord.X = WIDTH - 1;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        putchar('#');
    }
}

void showScore(void) {
    COORD coord;
    coord.X = 0;
    coord.Y = HIGH + 2;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    printf("Game Over!\n");
    printf("成绩为: %d\n", score);
}