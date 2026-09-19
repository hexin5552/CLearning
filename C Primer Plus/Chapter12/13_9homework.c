/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEMP_SIZE 256

int main(void) {
    int user_input;
    printf("How many words do you wish to enter? ");
    scanf("%d", &user_input);
    while (getchar() != '\n'); //添加一个getchar()消耗缓冲区残余空格

    /* char ** user_arr = (char **)malloc(user_input * sizeof(char));
     * user_arr 是指向 char* 的指针，即需要存储 user_input 个字符串指针。
     * 应分配 user_input * sizeof(char *) 字节，而非 sizeof(char)（通常为1）。
     */
    char **user_arr = (char **) malloc(user_input * sizeof(char *));

    /* char * temp = (char *)malloc(user_input * sizeof(char));
     * temp 只分配了 user_input 个字节，但用户输入的每个单词可能很长（甚至超过该长度）。
     * 应该为每个单词动态分配合适大小的缓冲区
     */
    char *temp = (char *) malloc(TEMP_SIZE * sizeof(char));

    printf("Enter %d words now: ", user_input);

    /* scanf("%c", temp);
     * 前面的 scanf("%d", &user_input) 会在输入缓冲区留下换行符 \n。
     * %c 会直接读取这个换行符，导致 temp 中存储的是 '\n'，而不是用户期望的单词。
     * 更严重的是，循环只执行一次，无法读取多个单词。
     * **user_arr = *temp;
     * user_arr 刚分配，其元素（user_arr[0]）未初始化，指向随机地址。
     * **user_arr 试图对随机地址解引用，属于非法访问。
     * 正确的做法是：先让 user_arr[i] 指向一块有效内存，再用 strcpy 或 scanf 将字符串存入。
     */
    for (int i = 0; i < user_input; i++) {
        scanf("%255s", temp);
        // strdup 会 malloc 一份 temp 的副本，并自动添加 '\0'
        user_arr[i] = strdup(temp);
    }
    printf("Here are you words: \n");
    for (int i = 0; i < user_input; i++)
        printf("%s\n", user_arr[i]);

    for (int i = 0; i < user_input; i++)
        free(user_arr[i]);
    free(user_arr);
    free(temp);
    return 0;
}
