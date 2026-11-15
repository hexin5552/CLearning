/**
 * @author Hexin
 * @version 1.0
 */
/*实现游戏逻辑模块*/
#include "game.h"
#include "date.h"
#include "mywindows.h"
#include <conio.h>
#include <time.h>
#include <mmsystem.h>
#include <stdio.h>
#pragma comment(lib, "winmm.lib")//播放音乐头文件
int grade = 0; //分数
int level = 1; //等级
int one = 0, two = 0, three = 0, four = 0; //消除行数统计
clock_t start_time;
BLOCK cur_block; //当前方块
BLOCK next_block; //下一个方块
//1.绘制游戏池边框
void windowPrint(int x, int y) {
    int i, j;
    for (i = 0; i < COL; i++)
        for (j = 0; j < LINE; j++)
            if (windowsShape[i][j] == 1) {
                setColor(0xc0);
                setPos(x + j, y + i);
                printf("%2s", "  ");
            }
}

//2.游戏初始化
void gameInit(void) {
    //句柄初始化
    initHandle();
    //打开音乐文件
    //确保路径存在并且需要注意转义字符
    //mciSendString("open E:\\Clion\\", NULL, 0, NULL);
    //播放音乐
    //mciSendString(TEXT("play a"), NULL, 0, NULL);
    printAnimation();
    gameModeChoose();
}

//3.打印操作说明
void printInfo(int n) {
    setColor(12);
    switch (n) {
        case 1:
            setPos(33, 9);
            printf("经典模式\n");
            setPos(31, 11);
            printf("1.方块匀速下落\n");
            setPos(31, 12);
            printf("2.方块可见\n");
            break;
        case 2:
            setPos(33, 9);
            printf("暴走模式\n");
            setPos(31, 11);
            printf("1.方块加速下落\n");
            setPos(31, 12);
            printf("2.方块可见\n");
            break;
        case 3:
            setPos(33, 9);
            printf("暴走模式\n");
            setPos(31, 11);
            printf("1.方块加速下落\n");
            setPos(31, 12);
            printf("2.方块不可见\n");
            break;
    }
    setColor(0x0a);
    setPos(33, 15);
    printf("操作规则\n");
    setPos(31, 17);
    printf("1.按 ← 或 A 左移");
    setPos(31, 18);
    printf("2.按 → 或 D 右移");
    setPos(31, 19);
    printf("3.按 ↓ 或 S 下落");
    setPos(31, 20);
    printf("4.按 ↑ 或 W 变形");
    setPos(31, 21);
    printf("5.按 ENTER 下落");
    setPos(31, 22);
    printf("6.按 SPACE 暂停");
}

//4.打印分数和等级
void printGradeLevel(int num) {
    switch (num) {
        case 0: break;
        case 1:
            grade += 10;
            one++;
            break;
        case 2:
            grade += 40;
            two++;
            break;
        case 3:
            grade += 60;
            three++;
            break;
        case 4:
            grade += 80;
            four++;
            break;
    }
    setColor(0x0e);
    setPos(5, 6);
    printf("分数: %d\n", grade);
    if (grade < 10)
        level = 1;
    else if (grade >= 10 && grade < 50)
        level = 2;
    else if (grade >= 50 && grade < 100)
        level = 3;
    else if (grade >= 100 && grade < 200)
        level = 4;
    else if (grade >= 200 && grade < 400)
        level = 5;
    else if (grade >= 400 && grade < 800)
        level = 6;
    else if (grade >= 800 && grade < 1600)
        level = 7;
    else if (grade >= 1600)
        level = 8;

    setPos(5, 7);
    switch (level) {
        case 1:
            printf("段位: 倔强青铜\n");
            break;
        case 2:
            printf("段位: 秩序白银\n");
            break;
        case 3:
            printf("段位: 荣耀黄金\n");
            break;
        case 4:
            printf("段位: 尊贵铂金\n");
            break;
        case 5:
            printf("段位: 永恒钻石\n");
            break;
        case 6:
            printf("段位: 至尊星耀\n");
            break;
        case 7:
            printf("段位: 最强王者\n");
            break;
        case 8:
            printf("段位: 荣耀王者\n");
            break;
    }

    setPos(5, 11);
    printf("消除一行 %d 次\n", one);
    setPos(5, 12);
    printf("消除二行 %d 次\n", two);
    setPos(5, 13);
    printf("消除三行 %d 次\n", three);
    setPos(5, 14);
    printf("消除四行 %d 次\n", four);

    time_t timep;
    struct tm *p;
    time(&timep);
    p = localtime(&timep);

    setColor(15);
    setPos(3, 18);
    printf("Date: %d/%d/%d\n", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday);
    setPos(3, 19);
    printf("Time: %d:%d:%d\n", p->tm_hour, p->tm_min, p->tm_sec);
    setPos(3, 22);
    printf("====鹤信支持====\n");
}

//5.游戏计时功能
void gameTime(clock_t start_time) {
    setColor(15);
    setPos(3, 3);
    printf("本次游戏已游玩 %d_s", (clock() - start_time) / CLOCKS_PER_SEC);
}

//6.打印左边框
void boardLeft(void) {
    setColor(0x09);
    setPos(0, 0);
    printf("□□□□□□□□□□□□□□□\n");
    printf("□%26s□\n", "");
    printf("□%26s□\n", "");
    printf("□%26s□\n", "");
    printf("□%26s□\n", "");
    printf("□%26s□\n", "");
    printf("□%26s□\n", "");
    printf("□%26s□\n", "");
    printf("□%26s□\n", "");
    printf("□%26s□\n", "");
    printf("□%26s□\n", "");
    printf("□%26s□\n", "");
    printf("□%26s□\n", "");
    printf("□%26s□\n", "");
    printf("□%26s□\n", "");
    printf("□%26s□\n", "");
    printf("□%26s□\n", "");
    printf("□%26s□\n", "");
    printf("□%26s□\n", "");
    printf("□%26s□\n", "");
    printf("□%26s□\n", "");
    printf("□%26s□\n", "");
    printf("□%26s□\n", "");
    printf("□%26s□\n", "");
    printf("□%26s□\n", "");
    printf("□□□□□□□□□□□□□□□\n");
}

//7.打印方块
void printBlock(int x, int y, int shape, int status, int color) {
    int i, j;
    for (i = 0; i < DATEC; i++)
        for (j = 0; j < DATEL; j++)
            if (block[shape][status][i][j] == 1) {
                setColor(color);
                setPos(x + j, y + i);
                printf("■");
            }
}

//8.删除方块
void deleteBlock(int x, int y, int shape, int status) {
    int i, j;
    for (i = 0; i < DATEC; i++)
        for (j = 0; j < DATEL; j++)
            if (block[shape][status][i][j] == 1) {
                setPos(x + j, y + i);
                printf("%2s", " ");
            }
}

//9.产生游戏第一个方块
void startBlock(void) {
    //第一个方块的形状、形态、颜色均随机，但是位置是固定的
    //初始化cur_block
    //设置一个随机数种子以产生不同的随机数，采用时间做种子
    srand((unsigned) time(NULL));
    cur_block.x = 22;
    cur_block.y = 1;
    cur_block.shape = rand() % 7; //产生0-6的随机数
    cur_block.status = rand() % 4;
    cur_block.color = rand() % 0x10;
    //如果颜色是黑色则变为白色
    if (cur_block.color == 0x00)
        cur_block.color = 0x0a;
    printBlock(cur_block.x, cur_block.y, cur_block.shape, cur_block.status, cur_block.color);
}

//10.产生下一个方块
void nextBlock(void) {
    //形状、形态、颜色随机，位置固定（右侧预览区）
    //初始化nextBlock
    next_block.x = 31;
    next_block.y = 2;
    deleteBlock(next_block.x, next_block.y, next_block.shape, next_block.status);
    next_block.shape = rand() % 7;
    next_block.status = rand() % 4;
    next_block.color = rand() % 0x10;
    if (next_block.color == 0x00)
        next_block.color = 0x0a;
    printBlock(next_block.x, next_block.y, next_block.shape, next_block.status, next_block.color);
}

//11.拷贝方块
void copyBlock(void) {
    //当前方块=下一个方块，并产生新的下一个方块
    cur_block = next_block;
    cur_block.x = 22;
    cur_block.y = 1;
    //在游戏区绘制新的当前方块
    printBlock(cur_block.x, cur_block.y, cur_block.shape, cur_block.status, cur_block.color);
    nextBlock();
}

//12.方块下移
//返回值用于标记方块是否到达游戏池底部
int downBlock(int n) {
    //原理：删除现在正在显示的方块，纵坐标+1，再重新打印
    if (crash(cur_block.x, cur_block.y + 1, cur_block.shape, cur_block.status) == -1) {
        //如果发生了碰撞，方块落到游戏池底部
        //保存方块，检测是否消行，刷新游戏池，产生新的方块
        save();
        lineClear();
        updateGame(n);
        copyBlock();
        //新方块出生即碰撞，说明游戏区已堆满，游戏结束
        if (crash(cur_block.x, cur_block.y, cur_block.shape, cur_block.status) == -1)
            return -2;
        return -1;
    }
    deleteBlock(cur_block.x, cur_block.y, cur_block.shape, cur_block.status);
    cur_block.y += 1;
    printBlock(cur_block.x, cur_block.y, cur_block.shape, cur_block.status, cur_block.color);
    return 0;
}

//13.方块左移
void leftBlock(void) {
    if (crash(cur_block.x - 1, cur_block.y, cur_block.shape, cur_block.status) == -1)
        return;
    deleteBlock(cur_block.x, cur_block.y, cur_block.shape, cur_block.status);
    cur_block.x -= 1;
    printBlock(cur_block.x, cur_block.y, cur_block.shape, cur_block.status, cur_block.color);
}

//14.方块右移
void rightBlock(void) {
    if (crash(cur_block.x + 1, cur_block.y, cur_block.shape, cur_block.status) == -1)
        return;
    deleteBlock(cur_block.x, cur_block.y, cur_block.shape, cur_block.status);
    cur_block.x += 1;
    printBlock(cur_block.x, cur_block.y, cur_block.shape, cur_block.status, cur_block.color);
}

//15.方块变形
void changeBlock(void) {
    //通过数组下标值+1获得下一个形态，下标值0-3
    if (crash(cur_block.x, cur_block.y, cur_block.shape, (cur_block.status + 1) % 4) == -1)
        return;
    deleteBlock(cur_block.x, cur_block.y, cur_block.shape, cur_block.status);
    cur_block.status = (cur_block.status + 1) % 4;
    printBlock(cur_block.x, cur_block.y, cur_block.shape, cur_block.status, cur_block.color);
}

//16.方块直接落底
int bottomBlock(int n) {
    while (1) {
        if (crash(cur_block.x, cur_block.y + 1, cur_block.shape, cur_block.status) == -1) {
            //如果发生碰撞，保存方块；检测消行并更新游戏池，拷贝方块
            save();
            lineClear();
            updateGame(n);
            copyBlock();
            //新方块出生即碰撞，说明游戏区已堆满，游戏结束
            if (crash(cur_block.x, cur_block.y, cur_block.shape, cur_block.status) == -1)
                return -2;
            return -1;
        }
        deleteBlock(cur_block.x, cur_block.y, cur_block.shape, cur_block.status);
        ++cur_block.y;
        printBlock(cur_block.x, cur_block.y, cur_block.shape, cur_block.status, cur_block.color);
    }
}

//17.碰撞检测
int crash(int x, int y, int shape, int status) {
    //基于下一个位置检测，参数为下一个位置或者下一个形态
    //返回 -1 表示碰撞，0 表示无碰撞
    int i, j;
    for (i = 0; i < DATEC; i++)
        for (j = 0; j < DATEL; j++)
            if (block[shape][status][i][j] == 1)
                if (windowsShape[i + y][j + x - 15] == 1)
                    return -1;
    return 0;
}

//18.方块保存
void save(void) {
    //根据方块在界面上的坐标，把坐标对应到游戏池下标对应位置
    //方块为1的保存到Windowsshape数组
    int i, j;
    for (i = 0; i < DATEC; i++)
        for (j = 0; j < DATEL; j++)
            if (block[cur_block.shape][cur_block.status][i][j] == 1)
                windowsShape[i + cur_block.y][j + cur_block.x - 15] = 1;
}

//19.刷新游戏池
void updateGame(int n) {
    int i, j;
    for (i = 23; i > 0; i--)
        for (j = 1; j < 15; j++)
            switch (n) {
                case 1:
                    if (windowsShape[i][j] == 1) {
                        setColor(0x0e);
                        setPos(15 + j, i);
                        printf("■");
                    } else {
                        setColor(0x00);
                        setPos(15 + j, i);
                        printf("%2s", " ");
                    }
                    break;
                case 2:
                    if (windowsShape[i][j] == 1) {
                        setColor(0x0e);
                        setPos(15 + j, i);
                        printf("%2s", " ");
                    } else {
                        setColor(0x00);
                        setPos(15 + j, i);
                        printf("%2s", " ");
                    }
                    break;
            }
}

//20.游戏暂停
void pauseGame(void) {
    while (1) {
        if (getch() == 32) break;
    }
}

//21.消行检测
void lineClear(void) {
    //遍历数组判断是否有满行，即所有制相加为14
    int i, j;
    int num = 0;
    int total;
    for (i = 23; i > 0; i--) {
        total = 0;
        for (j = 1; j < 15; j++)
            total += windowsShape[i][j];
        if (total == 14) {
            lineDown(i);
            i += 1;
            num += 1;
        }
    }
    printGradeLevel(num);
}

//22.消行下移
void lineDown(int line) {
    //从第line行开始， i = i-1
    int i, j;
    for (i = line; i > 1; i--) //i大于1保证边界不被下移
        for (j = 1; j < 15; j++)
            windowsShape[i][j] = windowsShape[i - 1][j];
    //顶部第一行清空，避免把顶部边框的1复制进来
    for (j = 1; j < 15; j++)
        windowsShape[1][j] = 0;
}

//23.游戏结束动画
void printEnd(void) {
    int i, j;
    for (i = 23; i > 0; i--)
        for (j = 1; j < 15; j++) {
            setColor(0x2e);
            setPos(j + 15, i);
            printf("☆");
            Sleep(5);
        }
}

//24.游戏重新开始提示
void restartInfo(void) {
    setColor(0x0f);
    setPos(20, 8);
    printf("====游戏结束!====\n");
    setPos(20, 10);
    printf("===按Y重新开始===\n");
    setPos(20, 11);
    printf("======按N结束游戏\n");

    switch (getchar()) {
        case 'y':
        case 'Y':
            restartGame();
            break;
        case 'n':
        case 'N':
            mciSendString(TEXT("stop a"), NULL, 0, NULL);
            endGame();
            break;
        default:
            restartInfo();
    }
}

//25.重新开始游戏
void restartGame(void) {
    level = 1;
    grade = 0;
    one = 0;
    two = 0;
    three = 0;
    four = 0;

    int i, j;
    for (i = 1; i < 24; i++)
        for (j = 1; j < 15; j++)
            windowsShape[i][j] = 0;
    system("cls");
    gameInit();
}

//26.游戏结束界面
void endGame(void) {
    system("cls");
    setPos(21, 8);
    setColor(12);
    printf("Game    Over!");

    setPos(21, 10);
    printf("分数: %d", grade);

    setPos(21, 12);
    switch (level) {
        case 1:
            printf("段位: 倔强青铜\n");
            break;
        case 2:
            printf("段位: 秩序白银\n");
            break;
        case 3:
            printf("段位: 荣耀黄金\n");
            break;
        case 4:
            printf("段位: 尊贵铂金\n");
            break;
        case 5:
            printf("段位: 永恒钻石\n");
            break;
        case 6:
            printf("段位: 至尊星耀\n");
            break;
        case 7:
            printf("段位: 最强王者\n");
            break;
        case 8:
            printf("段位: 荣耀王者\n");
            break;
    }

    setPos(21, 14);
    printf("消除1行: %d次\n", one);
    setPos(21, 16);
    printf("消除2行: %d次\n", two);
    setPos(21, 18);
    printf("消除3行: %d次\n", three);
    setPos(21, 20);
    printf("消除4行: %d次\n", four);
    setPos(21, 22);
    printf("本次游戏共运行 %d s", (clock() - start_time) / CLOCKS_PER_SEC);

    int i;
    setPosASCII(23, 2);
    setColor(6);
    printf("\\\\\\|///");
    setPosASCII(22, 3);
    printf("\\\\");

    setPosASCII(24, 3);
    setColor(15);
    printf(".-.-");

    setPosASCII(27, 3);
    setColor(6);
    printf("//");

    setPosASCII(22, 3);
    setColor(14);
    printf("(");

    setPosASCII(24, 4);
    setColor(15);
    printf(".@.@");

    setPosASCII(27, 4);
    setColor(14);
    printf(")");

    setPosASCII(8, 5);
    setColor(11);
    printf("+--------------------------------------\n");

    setPosASCII(17, 5);
    setColor(14);
    printf("o00o");

    setPosASCII(19, 5);
    setColor(11);
    printf("------------");

    setPosASCII(24, 5);
    setColor(14);
    printf("(_)");

    setPosASCII(26, 5);
    setColor(11);
    printf("-------------");

    setPosASCII(31, 5);
    setColor(14);
    printf("o00o");

    setPosASCII(33, 5);
    setColor(11);
    printf("-------------------+");

    for (i = 6; i <= 24; i++) {
        setPosASCII(8, i);
        printf("|");
        setPosASCII(41, i);
        printf("|");
    }

    setPosASCII(8, 25);
    printf("+-----------------------------");

    setPosASCII(23, 25);
    setColor(14);
    printf("☆ ☆ ☆");

    setPosASCII(28, 25);
    setColor(11);
    printf("----------------------------+\n\n");

    _getch(); //任意键退出
    exit(0);
}

//27.打印开始图案
void printStart(int x, int y) {
    int color = rand() % 0x10;
    if (color == 0x00)
        color = 0x0f;

    setColor(color);
    setPos(x, y);
    printf("■■■■■ ■■■■■ ■■■■■ ■■■■ ■■■  ■■■■");
    setPos(x, y + 1);
    printf("  ■   ■     ■  ■ ■  ■  ■");
    setPos(x, y + 2);
    printf("  ■  ■■■■   ■  ■■■■  ■   ■■■");
    setPos(x, y + 3);
    printf("  ■  ■       ■  ■ ■   ■   ■");
    setPos(x, y + 4);
    printf("  ■  ■■■■■  ■  ■  ■  ■■■  ■■■■");
    setPos(25, 15);
    printf("按Enter键开始游戏!\n");
}

//28.清除开始动画
void deleteStart(int x, int y) {
    int i, j;
    for (i = y; i < y + 5; i++)
        for (j = x; j < x + 35; j++) {
            setPos(j, i);
            printf("%2s", " ");
        }
}

//29.动画效果控制：定时，边界
void printAnimation(void) {
    clock_t time_1, time_2;
    time_1 = clock();
    int x = 5;
    printStart(x, 5);
    while (1) {
        time_2 = clock();
        if (time_2 - time_1 > 200) {
            //时间间隔200ms
            time_1 = time_2;
            deleteStart(x, 5);
            printStart(++x, 5);
            if (x == 22) {
                deleteStart(x, 5);
                x = 5;
            }
        }
        if (kbhit()) {
            if (getch() == 13)
                break;
            setPos(22, 17);
            int color = rand() % 0x10;
            if (color == 0x00)
                color = 0x0f;
            printf("输入有误!请按Enter键开始游戏!");
            _getch();
            system("cls");
        }
    }
    system("cls");
}

//30.游戏模式选择
void gameMode(float time, int n) {
    //开始时间
    clock_t startTime;
    startTime = clock();
    //定时器
    clock_t time1, time2;
    time1 = clock();
    while (1) {
        //检测按键是否按下
        if (kbhit()) {
            switch (getch()) {
                //方块变形
                case 'W':
                case 'w':
                case 72:
                    changeBlock();
                    break;
                case 'a':
                case 'A':
                case 75:
                    leftBlock();
                    break;
                case 'd':
                case 'D':
                case 77:
                    rightBlock();
                    break;
                case 's':
                case 'S':
                case 80:
                    if (downBlock(n) == -2)
                        return;
                    break;
                case 32:
                    pauseGame();
                    break;
                case 13:
                    if (bottomBlock(n) == -2)
                        return;
                    break;
            }
        }
        time2 = clock();
        //每time秒下落1次,速度不能太快
        //clock获得的时间转为秒需要除以参数CLOCKS_PER_SEC
        if (time2 - time1 > time * CLOCKS_PER_SEC) {
            //游戏计时
            gameTime(startTime);
            if (downBlock(n) == -2)
                return;
            time1 = time2;
        }
    }
}

//31.选择游戏模式界面
void gameModeChoose(void) {
    system("cls");
    int i;
    setPosASCII(23, 2);
    setColor(6);
    printf("\\\\\\|///");
    setPosASCII(22, 3);
    printf("\\\\");
    setPosASCII(24, 3);
    setColor(15);
    printf(".-.-");
    setPosASCII(27, 3);
    setColor(6);
    printf("//");
    setPosASCII(22, 4);
    setColor(14);
    printf("(");
    setPosASCII(24, 4);
    setColor(15);
    printf(".@.@");
    setPosASCII(27, 4);
    setColor(14);
    printf(")");
    setPosASCII(8, 5);
    setColor(11);
    printf("+---------------------------");
    setPosASCII(17, 5);
    setColor(14);
    printf("o00o");
    setPosASCII(19, 5);
    setColor(11);
    printf("-------------");
    setPosASCII(24, 5);
    setColor(14);
    printf("(_)");
    setPosASCII(26, 5);
    setColor(11);
    printf("-------------");
    setPosASCII(31, 5);
    setColor(14);
    printf("o00o");
    setPosASCII(33, 5);
    setColor(11);
    printf("---------------+");
    for (i = 6; i <= COL - 1; i++) {
        setPosASCII(8, i);
        printf("|");
        setPosASCII(41, i);
        printf("|");
    }
    setPosASCII(8, 25);
    printf("+------------------------");
    setPosASCII(23, 25);
    setColor(14);
    printf("☆ ☆ ☆");
    setPosASCII(28, 25);
    setColor(11);
    printf("---------------------------+\n\n");
    setPos(20, 9);
    setColor(11);
    printf("俄罗斯方块模式选择");
    setColor(12);
    setPos(12, 15);
    printf("1.普通模式");
    setPos(22, 15);
    printf("2.暴走模式");
    setPos(32, 15);
    printf("3.地狱模式");
    setPos(21, 22);
    setColor(3);
    printf("请选择 1 2 3:");
    setColor(14);
    int n;
    scanf("%d", &n);
    switch (n) {
        case 1:
            system("cls");
            windowPrint(15, 0);
            printInfo(n);
            boardLeft();
            printGradeLevel(0);
            startBlock();
            nextBlock();
            gameMode(0.65, 1);
            printEnd();
            restartInfo();
            break;
        case 2:
            system("cls");
            windowPrint(15, 0);
            printInfo(n);
            boardLeft();
            printGradeLevel(0);
            startBlock();
            nextBlock();
            gameMode(0.15, 1);
            printEnd();
            restartInfo();
            break;
        case 3:
            system("cls");
            windowPrint(15, 0);
            printInfo(n);
            boardLeft();
            printGradeLevel(0);
            startBlock();
            nextBlock();
            gameMode(0.15, 2);
            printEnd();
            restartInfo();
            break;
        default:
            setColor(12);
            setPos(21, 23);
            printf("请输入1-3之间的数!");
            _getch();
            system("cls");
            gameModeChoose();
    }
}
