#ifndef STORAGE_H
#define STORAGE_H

#include "record.h"

/*
 * 文件格式（每行一条记录，字段用 '|' 分隔）：
 *   YYYY-MM-DD|content
 */

#define STORAGE_FILE "data/records.txt"
#define QUOTES_FILE "data/quotes.txt"

/* 从文件加载所有记录组成链表；文件不存在或为空时返回 NULL */
Record *storage_load(const char *filename);

/* 把整条链表写回文件（覆盖）；成功返回 0，失败 -1 */
int storage_save(const char *filename, const Record *head);

/* 把一条记录追加到文件末尾；成功 0，失败 -1 */
int storage_append_one(const char *filename, const Record *r);

/* 从文件中随机挑一行复制到 buf；成功 0，失败 -1 */
int storage_random_quote(const char *filename, char *buf, int bufsize);

#endif
