/**
 * @author Hexin
 * @version 1.0
 */
int main(void) {
    int digt[6] = { 1, 2, 4, 8, 16, 32 };
    digt[2];
    int dig2[100];
    int *p1;
    p1 = &dig2[99];
    *p1 = -1;
    //or
    dig2[99] = -1;
    //or
    int dig2[100] = { [99] = -1};
    dig2[5] = dig2[10] = dig2[11] = dig2[12] = dig2[13] = 101;
    //int dig2[100] = { [5] = [10] = [11] = [12] = [13] = 101};错误写法，不能这样赋值
    return 0;
}