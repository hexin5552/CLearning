/**
* @author Hexin
 * @version 1.0
 */
int set_mode(int mode, int preMode);

void get_info(double * cost, double * distance, int temp);

void show_info(double * cost, double * distance, int temp);


int set_mode(int mode, int preMode) {
    if (mode != 0 && mode != 1)
        printf("Invalid mode specified. Mode %d(%s) used.\n", preMode, preMode == 0 ? "metric" : "US");
    else
        preMode = mode;
    return preMode;
}

void get_info(double * cost, double * distance, int temp) {
    if (temp == 0 || temp == 1) {
        printf("Enter distance traveled in %s: ", temp == 0 ? "kilometers" : "miles");
        scanf("%lf", distance);
        printf("Enter fuel consumed in %s: ", temp == 0 ? "liters" : "gallon");
        scanf("%lf", cost);
    }
}

void show_info(double * cost, double * distance, int temp) {
    if (temp == 0 || temp == 1)
        printf("Fuel consumption is %.2lf leters per %s.\n", *distance / *cost, temp == 0 ? "100 km" : "gallon");
}
