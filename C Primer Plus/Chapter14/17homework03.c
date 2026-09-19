//未做课后习题,从这题之后,全部没做
/**
 * @author Hexin
 * @version 1.0
 */
#define LEN 40
struct month {
    char monNam[LEN];
    char monNamS[LEN];
    int days;
    int dayNum;
};
int reMonDays(struct month * ptr, int count);
int main(void) {
    struct month year[12] = {
        {"January", "Jan", 31, 1},
        {"Feberuary", "Feb", 28, 2},
        {"March", "Mar", 31, 3},
        {"April", "Apr", 30, 4},
        {"May", "May", 31, 5},
      //  {......}
    };
    return 0;
}
int reMonDays(struct month * ptr, int count) {
    int tot;
    for (int i = 1; i <= count; i++)
        tot += ptr[i].days;
    return tot;
}