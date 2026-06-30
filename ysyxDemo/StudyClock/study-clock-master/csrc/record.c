#include "record.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*---- 1.创建新节点 ---- */
Record *record_new(int year, int month, int day, const char *content) {
    Record *r = (Record *) malloc(sizeof(Record));
    if (r == NULL)
        return NULL;

    //填数据
    r->year = year;
    r->month = month;
    r->day = day;

    //复制内容：yongstrncpy防止溢出，保留最后一个字符给'\0'
    strncpy(r->content, content, sizeof(r->content) - 1);
    r->content[sizeof(r->content) - 1] = '\0'; //确保结尾是'\0'

    r->next = NULL; //新节点的指针先指向空，表示后面没有车厢
    return r;
}

/*---- 2.释放整条链条 ---- */
void record_free_all(Record *head) {
    while (head != NULL) {
        Record *tmp = head; //记住当前车厢
        head = head->next; //先移动到下一节，避免丢失
        free(tmp); //释放当前车厢
    }
}

/*---- 3.头插法 ---- */
void record_prepend(Record **head, Record *r) {
    //使用二级指针，因为需要修改外面的头指针本身
    r->next = *head; //新的节点指针指向原来的第一节点
    *head = r; //头指针改为指向新节点
}

/*---- 4.尾插法 ---- */
void record_append(Record **head, Record *r) {
    //使用二级指针，因为若链表为空，则修改头指针
    Record **cur = head; //cur指向“当前要处理的指针”
    while (*cur != NULL) //若指针不为空，则说明还未到节点末尾
        cur = &((*cur)->next); //移动下一个指针
    //循环结束后，*cur就是最后一个节点的尾指针，或者head（若是空链表）
    *cur = r; //指向新节点
    r->next = NULL; //确保新节点的指向下一个节点的指针是NULL
}

/*---- 5.统计链表有多少个节点 ---- */
int record_count(const Record *head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

/*---- 6.判断记录的日期是否匹配y/m/d ---- */
int record_match_date(const Record *r, int y, int m, int d) {
    if (r == NULL) //防止为空
        return 0;
    return (r->year == y && r->month == m && r->day == d);
}
