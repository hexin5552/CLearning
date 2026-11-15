/**
 * @author Hexin
 * @version 1.0
 */
#include "13stack.h"
#include <stdlib.h>
#include <stdio.h>
static void CopyToNode(Item item, Node * pn);
static void CopyToItem(Node * pn, Item * pi);
void InitializeStack(Stack * pq) {
    pq->front =pq->rear = NULL;
    pq->items = 0;
}
bool StackIsFull(const Stack * pq) {
    return pq->items == MAXSTACK;
}
bool StackIsEmpty(const Stack * pq) {
    return pq->items == 0;
}
int StackItemCount(const Stack * pq) {
    return pq->items;
}
bool EnStack(Item item, Stack * pq) {
        Node *pnew;
        if (StackIsFull(pq))
            return false;
        pnew = (Node *)malloc(sizeof(Node));
        if (pnew == NULL) {
            fprintf(stderr, "Unable to allocate memory!\n");
            exit(1);
        }
        CopyToNode(item, pnew);
        pnew->next = pq->front;
        pq->front = pnew;
        if (pq->rear == NULL)
            pq->rear = pnew;
        pq->items++;
        return true;
}
bool DeStack(Item * pitem, Stack * pq) {
        Node *pt;
        if (StackIsEmpty(pq))
            return false;
        CopyToItem(pq->front, pitem);
        pt = pq->front;
        pq->front = pq->front->next;
        free(pt);
        pq->items--;
        if (pq->items == 0)
            pq->rear = pq->front = NULL;
        return true;
}
void EmptyTheStack(Stack * pq) {
    Item dummy;
    while (!StackIsEmpty(pq))
        DeStack(&dummy, pq);
}
static void CopyToNode(Item item, Node * pn) {
    pn->item = item;
}
static void CopyToItem(Node * pn, Item * pi) {
    *pi = pn->item;
}