/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define COL 8
#define LINE 8
#define NUM 5
int level = 1; //当前关卡
int i, j;
int Map[NUM][COL][LINE] = {
    //第1关
    {
        {0, 0, 1, 1, 1, 0, 0, 0},
        {0, 0, 1, 3, 1, 0, 0, 0},
        {0, 0, 1, 0, 1, 1, 1, 1},
        {1, 1, 1, 4, 0, 4, 3, 1},
        {1, 3, 0, 4, 6, 1, 1, 1}, //4,4角色位置
        {1, 1, 1, 1, 4, 1, 0, 0},
        {0, 0, 0, 1, 3, 1, 0, 0},
        {0, 0, 0, 1, 1, 1, 0, 0}
    },
    //第2关
    {
        {1, 1, 1, 1, 1, 1, 1, 0},
        {1, 3, 0, 0, 0, 0, 1, 0},
        {1, 0, 0, 3, 0, 0, 1, 0},
        {1, 0, 4, 0, 4, 0, 1, 0},
        {1, 0, 0, 6, 0, 0, 1, 0},
        {1, 0, 4, 0, 4, 0, 1, 0},
        {1, 3, 0, 3, 0, 0, 1, 0},
        {1, 1, 1, 1, 1, 1, 1, 0}
    },
    //第3关
    {
        {0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 0, 1, 1, 1, 0},
        {1, 3, 0, 0, 0, 3, 1, 0},
        {1, 0, 4, 0, 4, 0, 1, 0},
        {1, 0, 0, 6, 0, 0, 1, 0},
        {1, 0, 4, 0, 4, 0, 1, 0},
        {1, 3, 0, 0, 0, 3, 1, 0},
        {1, 1, 1, 0, 1, 1, 1, 0}
    },
    //第4关
    {
        {0, 1, 1, 1, 1, 1, 0, 0},
        {0, 1, 3, 0, 0, 1, 0, 0},
        {0, 1, 0, 4, 0, 1, 0, 0},
        {0, 1, 0, 0, 3, 1, 0, 0},
        {0, 1, 3, 0, 0, 1, 0, 0},
        {0, 1, 0, 4, 0, 1, 0, 0},
        {0, 1, 0, 4, 0, 1, 0, 0},
        {0, 1, 6, 4, 3, 1, 0, 0}
    },
    //第5关
    {
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 0},
        {0, 1, 3, 0, 0, 0, 1, 0},
        {0, 1, 0, 4, 0, 3, 1, 0},
        {0, 1, 0, 4, 6, 0, 1, 0},
        {0, 1, 3, 0, 4, 0, 1, 0},
        {0, 1, 0, 4, 0, 3, 1, 0},
        {0, 1, 1, 1, 1, 1, 1, 0}
    }
};

void printMap(int Map[NUM][COL][LINE]);

void getPosition(int Map[NUM][COL][LINE]);

int getWin(void);

int main(void) {
    while (level <= NUM) {
        while (1) {
            printMap(Map); //绘制地图
            getPosition(Map); //获取坐标，角色移动
            if (getWin())
                break;
        }
        printMap(Map);
        printf("通关!!\n");
        system("cls");
        level++;
    }
    return 0;
}

void printMap(int Map[level][COL][LINE]) {
    for (i = 0; i < COL; i++) {
        for (j = 0; j < LINE; j++)
            switch (Map[level][i][j]) {
                case 0: printf("  ");
                    break;
                case 1: printf("██");
                    break;
                case 3: printf("终");
                    break;
                case 4: printf("箱");
                    break;
                case 6: printf("人");
                    break;
                case 7: printf("箱");
                    break;
                case 9: printf("人");
                    break;
            }
        printf("\n");
    }
}

void getPosition(int Map[NUM][COL][LINE]) {
    for (i = 0; i < COL; i++) {
        for (j = 0; j < LINE; j++)
            if (Map[level][i][j] == 6 || Map[level][i][j] == 9) break;
        if (Map[level][i][j] == 6 || Map[level][i][j] == 9) break;
    }
    printf("坐标：(%d,%d)\n", i, j);
    int input = getch();
    switch (input) {
        case 'w':
            //判断角色前方是空地或者是目的地，人物可移动
            if (Map[level][i - 1][j] == 0 || Map[level][i - 1][j] == 3) {
                Map[level][i - 1][j] += 6;
                Map[level][i][j] -= 6;
            }
            //判断角色前方是箱子或是箱子在目的地
            else if (Map[level][i - 1][j] == 4 || Map[level][i - 1][j] == 7)
                if (Map[level][i - 2][j] == 0 || Map[level][i - 2][j] == 3) {
                    Map[level][i - 2][j] += 4;
                    Map[level][i - 1][j] += 2; //人在目的地
                    Map[level][i][j] -= 6; //目的地
                }
            break;
        case 's':
            //判断角色前方是空地或者是目的地，人物可移动
            if (Map[level][i + 1][j] == 0 || Map[level][i + 1][j] == 3) {
                Map[level][i + 1][j] += 6;
                Map[level][i][j] -= 6;
            }
            //判断角色前方是箱子或是箱子在目的地
            else if (Map[level][i + 1][j] == 4 || Map[level][i + 1][j] == 7)
                if (Map[level][i + 2][j] == 0 || Map[level][i + 2][j] == 3) {
                    Map[level][i + 2][j] += 4;
                    Map[level][i + 1][j] += 2; //人在目的地
                    Map[level][i][j] -= 6; //目的地
                }
            break;
        case 'a':
            //判断角色前方是空地或者是目的地，人物可移动
            if (Map[level][i][j - 1] == 0 || Map[level][i][j - 1] == 3) {
                Map[level][i][j - 1] += 6;
                Map[level][i][j] -= 6;
            }
            //判断角色前方是箱子或是箱子在目的地
            else if (Map[level][i][j - 1] == 4 || Map[level][i][j - 1] == 7)
                if (Map[level][i][j - 2] == 0 || Map[level][i][j - 2] == 3) {
                    Map[level][i][j - 2] += 4;
                    Map[level][i][j - 1] += 2; //人在目的地
                    Map[level][i][j] -= 6; //目的地
                }
            break;
        case 'd':
            //判断角色前方是空地或者是目的地，人物可移动
            if (Map[level][i][j + 1] == 0 || Map[level][i][j + 1] == 3) {
                Map[level][i][j + 1] += 6;
                Map[level][i][j] -= 6;
            }
            //判断角色前方是箱子或是箱子在目的地
            else if (Map[level][i][j + 1] == 4 || Map[level][i][j + 1] == 7)
                if (Map[level][i][j + 2] == 0 || Map[level][i][j + 2] == 3) {
                    Map[level][i][j + 2] += 4;
                    Map[level][i][j + 1] += 2; //人在目的地
                    Map[level][i][j] -= 6; //目的地
                }
            break;
    }
}

int getWin(void) {
    int count = 0;
    for (i = 0; i < COL; i++)
        for (j = 0; j < LINE; j++)
            if (Map[level][i][j] == 7)
                count++;
    return count == 4 ? 4 : 0;
}
