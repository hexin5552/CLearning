#include "storage.h"
#include "tools/color.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_MAX_LEN 512

/* ---- 框架代码（不要修改） ----
 *
 * 解析一行：YYYY-MM-DD|content
 * 既检查格式，又检查日期范围合法性（防御性解析）
 * 成功返回 1，失败返回 0 */
static int parse_line(const char *line, int *y, int *m, int *d,
                      char *content_out, int outlen) {
    char buf[LINE_MAX_LEN];
    strncpy(buf, line, LINE_MAX_LEN - 1);
    buf[LINE_MAX_LEN - 1] = '\0';

    /* 剥掉末尾的 \n */
    char *nl = strchr(buf, '\n');
    if (nl)
        *nl = '\0';

    if (buf[0] == '\0')
        return 0;

    char *sep = strchr(buf, '|');
    if (sep == NULL)
        return 0;
    *sep = '\0';

    const char *date_part = buf;
    const char *content_part = sep + 1;

    if (sscanf(date_part, "%d-%d-%d", y, m, d) != 3)
        return 0;

    /* 日期范围校验：拒绝明显非法的值（防御性解析）
     * 这里不细分大小月、闰年；只挡住一眼就不对的脏数据 */
    if (*y < 1970 || *y > 9999)
        return 0;
    if (*m < 1 || *m > 12)
        return 0;
    if (*d < 1 || *d > 31)
        return 0;

    strncpy(content_out, content_part, outlen - 1);
    content_out[outlen - 1] = '\0';
    return 1;
}

/* ---- 请将下面的函数实现完整 ---- */
/*---- 1.加载所有记录 ---- */
Record *storage_load(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
        return NULL; //第一次运行没文件，正常返回NULL
    Record *head = NULL;
    char line[LINE_MAX_LEN];
    int y, m, d;
    char content[256];
    while (fgets(line, sizeof(line), fp) != NULL) {
        if (parse_line(line, &y, &m, &d, content, sizeof(content))) {
            Record *new_node = record_new(y, m, d, content);
            if (new_node != NULL)
                record_append(&head, new_node);
        } else
        //格式有问题的行，打印警告并跳过
            fprintf(stderr, YELLOW("warning: skip the incorrect line: %s"), line);
    }

    fclose(fp);
    return head;
}

/*---- 2.保存所有记录（覆盖写） ---- */
int storage_save(const char *filename, const Record *head) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
        return -1;

    const Record *cur = head;
    while (cur != NULL) {
        fprintf(fp, "%04d-%02d-%02d|%s\n", cur->year, cur->month, cur->day, cur->content);
        cur = cur->next;
    }

    fclose(fp);
    return 0;
}

/*---- 3.追加一条记录 ---- */
int storage_append_one(const char *filename, const Record *r) {
    FILE *fp = fopen(filename, "a");
    if (fp == NULL)
        return -1;

    fprintf(fp, "%04d-%02d-%02d|%s\n", r->year, r->month, r->day, r->content);
    fclose(fp);
    return 0;
}

/*---- 4.随机抽一句名言 ---- */
int storage_random_quote(const char *filename, char *buf, int bufsize) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
        return -1;
    char line[LINE_MAX_LEN];
    int total = 0;

    //第一遍：数有多少行
    while (fgets(line, sizeof(line), fp) != NULL) {
        total++;
    }

    if (total == 0) {
        fclose(fp);
        return -1;
    }
    //随机选一行
    int target = rand() % total;

    //第二遍：重新寻找，找到目标行
    rewind(fp);
    int current = 0;
    while (fgets(line, sizeof(line), fp) != NULL) {
        if (current == target)
            break;
        current++;
    }

    //剥掉末尾换行符
    char *nl = strchr(line, '\n');
    if (nl) *nl = '\0';

    //安全复制到输出缓冲区
    strncpy(buf, line, bufsize - 1);
    buf[bufsize - 1] = '\0';

    fclose(fp);
    return 0;
}
