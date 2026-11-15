/**
 * @author Hexin
 * @version 1.0
 */
#ifndef CLION_13STACK_H
#define CLION_13STACK_H
#include <stdbool.h>
typedef int Item;
#define MAXSTACK 10
typedef struct node {
    Item item;
    struct node * next;
}Node;
typedef struct stack {
    Node * front;
    Node * rear;
    int items;
}Stack;
void InitializeStack(Stack * pq);
bool StackIsFull(const Stack * pq);
bool StackIsEmpty(const Stack * pq);
int StackItemCount(const Stack * pq);
bool EnStack(Item item, Stack * pq);
bool DeStack(Item * pitem, Stack * pq);
void EmptyTheStack(Stack * pq);
#endif //CLION_13STACK_H
