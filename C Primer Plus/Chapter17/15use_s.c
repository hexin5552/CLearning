/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#include "13stack.h"
int main(void) {
    Stack line;
    Item temp;
    char ch;
    InitializeStack(&line);
    puts("Testing the queue interface. Type a to add a value,");
    puts("type d to delete a value, and type q to quit.");
    while ((ch = getchar()) != 'q') {
        if (ch != 'a' && ch != 'd')
            continue;
        if (ch == 'a') {
            printf("Integer to add: ");
            scanf("%d", &temp);
            if (!StackIsFull(&line)) {
                printf("Putting %d into Stack\n", temp);
                EnStack(temp, &line);
            }else
                puts("Stack is full!");
        }else {
            if (StackIsEmpty(&line))
                puts("Nothing to delete!");
            else {
                DeStack(&temp, &line);
                printf("Removing %d from stack\n", temp);
            }
        }
        printf("%d items in stack\n", StackItemCount(&line));
        puts("Type a to add, d to delete, q to quit:");
    }
    EmptyTheStack(&line);
    puts("Bye!");
    return 0;
}