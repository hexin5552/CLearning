/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#define OBJ 5
#define ITEMS 4
int main(void) {
    int available[ITEMS - 1] = {3, 4, 2};
    int lineNum = -1;
    int sortNum;
    int i, j;
    int require[ITEMS] = {0};
    int need[OBJ][ITEMS] = {
        {0, 5, 5, 1}, //p0
        {1, 2, 2, 0}, //p1
        {2, 0, 1, 1}, //p2
        {3, 2, 2, 1}, //p3
        {4, 4, 0, 2}, //p4
    };
    int allocation[OBJ][ITEMS] = {
        {0, 0, 2, 2}, //p0
        {1, 1, 3, 4}, //p1
        {2, 5, 2, 4}, //p2
        {3, 2, 0, 0}, //p3
        {4, 2, 7, 1}, //p4
    };
    int max[OBJ][ITEMS + 1] = {
        {0, 5, 7, 3, -1}, //p0 0
        {1, 3, 5, 4, -1}, //p1 2
        {2, 5, 3, 5, -1}, //p2 4
        {3, 4, 2, 1, -1}, //p3 3
        {4, 6, 7, 3, -1}, //p4 1
    };
    printf("================银行家算法模拟==================\n");
    while (1) {
        sortNum = 0;
        printf("输入格式：\"x a b c\", 模拟进程x申请资源a b c的数量\n");
        printf("请输入申请量：");
        int reVal = scanf("%d %d %d %d", require, require + 1, require + 2, require + 3);//scanf格式里不能带\n, 会导致无法正常接受输入
        while (getchar() != '\n');
        if (reVal != 4) {
            fprintf(stderr, "不合法输入: 请输入整数。\n");
            continue;
        }
        if (*require > 4 || *require < 0) {
            fprintf(stderr, "不合法输入: 进程号越界, 模拟进程号为0 - 4。\n");
            continue;
        }
        for (j = 1; j < ITEMS; j++){
            if (require[j] > need[*require][j])
                fprintf(stderr, "不合法的请求: 进程资源请求量不应大于进程资源剩余需求量。\n");
        }
        //模拟分配
        for (j = 1; j < ITEMS; j++) {
            available[j - 1] = need[*require][j] - require[j];
            allocation[*require][j] = need[*require][j] + require[j];
        }
        //todo: 寻找安全序列
        
        for (i = 0; i < OBJ; i++)
            for (j = 1; j < ITEMS; j++)
                if (allocation[i] == max[i]) {
                    lineNum = max[i][0];
                    for (i = 1; i < ITEMS; i++)
                        available[i - 1] = max[lineNum][i];
                    max[lineNum][ITEMS] = sortNum++;
                }
        if (sortNum == 5) {
            sortNum = 0;
            printf("找到安全序列, 本次资源请求通过。\n");
            printf("安全序列是：");
            for (i = 0; i < OBJ; i++)
                if (max[i][4] == sortNum++)
                    printf("P%d ", max[i][0]);
            break;
        }
        fprintf(stderr, "无法找到安全序列, 本次资源请求被阻止。\n");
        for (j = 1; j < ITEMS; j++) {
            available[j - 1] = need[*require][j] - require[j];
            allocation[*require][j] = need[*require][j] + require[j];
        }
    }

    return 0;
}