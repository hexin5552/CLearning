/**
 * @author Hexin
 * @version 1.0
 */
// 未完成，当前的水平还不足以实现这个问题后续再回来继续完成
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//将整个文件内容读入内存后一次性处理，适合小文件，可以一次性处理全部内容（包括换行符）。
void printMesg(char * progName);
int main(int argc, char *argv[]) {
    char mode = 'p';
    if (argc > 1 && argv[1][0] == '-') {
        if (strcmp(argv[1], "-p") == 0) mode = 'p';
        else if (strcmp(argv[1], "-u") == 0) mode = 'u';
        else if (strcmp(argv[1], "-l") == 0) mode = 'l';
        else {
            fprintf(stderr, "Error: Unknown option.\n");
            printMesg(argv[0]);
            return 1;
        }
    }

    char * content = NULL;
    char buffer[1024];
    size_t total = 0;
    size_t nread;
    while ((nread = fread(buffer, 1, sizeof(buffer), stdin)) > 0) {
        char *newContent = realloc(content, total + nread + 1);
        if (!newContent) {
            perror("realloc");
            free(content);
            return 1;
        }
        content = newContent;
        memcpy(content + total, buffer, nread);
        total += nread;
    }
    if (content)
        content[total] = '\0';
    else {
        content = strdup("");
        if (!content) return 1;
    }

    if (mode == 'p')
        fputs(content, stdout);
    else if (mode == 'u')
        for (size_t i = 0; i < total; i++)
            putchar(toupper(content[i]));
    else if (mode == 'l')
        for (size_t i = 0; i < total; i++)
            putchar(tolower(content[i]));

    free(content);
    return 0;
}
void printMesg(char * progName) {
    fprintf(stderr, "Usage: %s [-p | -u | -l] < input.txt\n", progName);
    fprintf(stderr, "  -p  print as-is (default)\n");
    fprintf(stderr, "  -u  convert to uppercase\n");
    fprintf(stderr, "  -l  convert to lowercase\n");
    fprintf(stderr, "Reads entire stdin until EOF.\n");
}


//逐行读取并立即处理（流式处理），读取一行处理一行，适合大文件，内存占用小。

// void print_usage(const char *prog_name) {
//     fprintf(stderr, "Usage: %s [-p | -u | -l] < input.txt\n", prog_name);
//     fprintf(stderr, "  -p  print as-is (default)\n");
//     fprintf(stderr, "  -u  convert to uppercase\n");
//     fprintf(stderr, "  -l  convert to lowercase\n");
//     fprintf(stderr, "Reads from stdin until EOF.\n");
// }
//
// int main(int argc, char *argv[]) {
//     // 解析选项（与之前相同）
//     char mode = 'p';
//     int arg_index = 1;
//
//     if (argc > 1 && argv[1][0] == '-') {
//         if (strcmp(argv[1], "-p") == 0) mode = 'p';
//         else if (strcmp(argv[1], "-u") == 0) mode = 'u';
//         else if (strcmp(argv[1], "-l") == 0) mode = 'l';
//         else {
//             fprintf(stderr, "Error: Unknown option '%s'\n", argv[1]);
//             print_usage(argv[0]);
//             return 1;
//         }
//         arg_index = 2;
//     }
//     // 如果有额外的参数（非选项），忽略它们，只从stdin读取
//
//     // 逐行读取 stdin 直到 EOF
//     char line[1024];
//     while (fgets(line, sizeof(line), stdin) != NULL) {
//         // 去掉行尾的换行符（根据需求可保留）
//         // line[strcspn(line, "\n")] = '\0';
//
//         // 根据模式转换并输出
//         if (mode == 'p') {
//             fputs(line, stdout);
//         } else if (mode == 'u') {
//             for (int i = 0; line[i] != '\0'; i++) {
//                 putchar(toupper(line[i]));
//             }
//         } else if (mode == 'l') {
//             for (int i = 0; line[i] != '\0'; i++) {
//                 putchar(tolower(line[i]));
//             }
//         }
//     }
//
//     return 0;
// }