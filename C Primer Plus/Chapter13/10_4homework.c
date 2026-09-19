/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int count = 5;
    double total = 0.0, result[count];
    FILE *fp;
    char *filename;
    if (argc > 2) {
        /*perror("I can't do it.\n");
         *perror 用于输出系统调用失败后的错误信息（会根据 errno 自动拼接错误描述）。
         *此处没有发生系统错误，且传入的字符串末尾带了 \n，导致输出混乱（例如会显示 I can't do it.\n: Success）。
         *正确的做法是用 fprintf 输出自定义错误信息：*/
        fprintf(stderr, "Usage: %s [filename].\n", argv[0]);
        exit(EXIT_FAILURE);
    } else if (argc == 2) {
        printf("It's file input mode.\n");
        filename = argv[1];
        if ((fp = fopen(filename, "r")) == NULL) {
            fprintf(stderr, "Couldn't open the %s file\n", filename);
            exit(EXIT_FAILURE);
        }
        for (int i = 0; i < count; i++) {
            if (fscanf(fp, "%lf", &result[i]) != 1) {
                fprintf(stderr, "Input text is not enough!\n");
                exit(EXIT_FAILURE);
            }
            /*fread(result, sizeof(double), count, fp);
            * fread 每次读取 5 个 double（count 个），但循环执行 5 次，总共试图读取 25 个 double，
            * 而 result 数组只有 5 个元素，循环写入时 result[i] 虽然不会越界（因为 i 只有 0~4），
            * 但 fread 本身会越界写入 result[0]~result[4] 并覆盖，且后续每次 fread 都会覆盖前一次，
            * 导致最终只保留最后一次读取的 5 个数字。更严重的是：文件以 文本模式（"r"）打开，
            * 却用 fread 读取 二进制 double，这会导致数据解析错误（例如文本 "1.2" 会被当作二进制浮点数字节读取，
            * 产生垃圾值）。如果文件数据不足 25 个 double，fread 返回实际读取个数，但程序未检查，未初始化的元素会被用于累加，
            * 造成随机结果。
             */
            total += result[i];
        }
        fprintf(stdout, "The average is %5.2lf ", total / count);
        fclose(fp);
    } else {
        printf("It's standard input mode.\n");
        printf("Please enter 5 double digits: ");
        for (int i = 0; i < count; i++) {
            /*scanf("%lf", result);
             * result 是数组名，在表达式中退化为指针，指向第一个元素 &result[0]，
             * 因此每次循环都只向 result[0] 写入值，而 result[1]~result[4] 保持未初始化。
             * 累加 total += result[i] 时，i>0 的元素是垃圾值，导致平均值完全错误。
             */
            if (scanf("%lf", &result[i]) != 1) {
                fprintf(stderr, "Input text is not enough!\n");
                exit(EXIT_FAILURE);
            }
            total += result[i];
        }
        printf("The average is %.2lf ", total / count);
    }
    return 0;
}
