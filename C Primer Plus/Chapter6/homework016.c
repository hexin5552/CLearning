/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>

int main(void) {
    double moneyDaphne = 0.0;
    int index = 0;
    double moneyDeirdre = 0.0;
    moneyDaphne += 100 * 0.1;
    moneyDeirdre += (100 + moneyDeirdre) * 0.05;
    while (moneyDeirdre < moneyDaphne) {
        moneyDaphne += 100 * 0.1;
        moneyDeirdre += (100 + moneyDeirdre) * 0.05;
        index++;
    }

    printf("after %d years, moneyDeirdre > moneyDaphne\n", index);
    printf("moneyDeirdre = %lf, moneyDaphne = %lf", moneyDeirdre, moneyDaphne);

    return 1;
}
