#ifndef RECORD_H
#define RECORD_H

#define RECORD_CONTENT_MAX 256

typedef struct record {
  int year;
  int month;
  int day;
  char content[RECORD_CONTENT_MAX];
  struct record *next;
} Record;

/* 在堆上新建一条记录；失败返回 NULL */
Record *record_new(int year, int month, int day, const char *content);

/* 释放整条链表 */
void record_free_all(Record *head);

/* 头插：把 r 接到链表头部（O(1)） */
void record_prepend(Record **head, Record *r);

/* 尾插：把 r 接到链表尾部（O(n)，保持时间顺序） */
void record_append(Record **head, Record *r);

/* 统计节点个数 */
int record_count(const Record *head);

/* 判断一条记录的日期是否等于给定 y/m/d */
int record_match_date(const Record *r, int y, int m, int d);

#endif
