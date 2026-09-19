/**
 * @author Hexin
 * @version 1.0
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <base (double)> <exponent (int)>\n", argv[0]);//stderr是c语言专门处理错误的流，
        //与stdout一样，在屏幕上输出错误信息
        return 1;
    }//错误处理
    int i1 = atoi(argv[2]);
    double d1 = atof(argv[1]);

    double res = pow(d1, i1);
    printf("%g\n", res);
    return 0;

}
