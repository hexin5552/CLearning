/**
 * @author Hexin
 * @version 1.0
 */
int set_mode(int mode);

void get_info(void);

void show_info(void);

extern double cost;
extern double distance;
extern int sub_mode;
extern double cost;
extern double distance;

int set_mode(int mode) {
    if (mode != 0 && mode != 1)
        printf("Invalid mode specified. Mode %d(%s) used.\n", sub_mode, sub_mode == 0 ? "metric" : "US");
    else
        sub_mode = mode;
    return sub_mode;
}

void get_info(void) {
    if (sub_mode == 0 || sub_mode == 1) {
        printf("Enter distance traveled in %s: ", sub_mode == 0 ? "kilometers" : "miles");
        scanf("%lf", &distance);
        printf("Enter fuel consumed in %s: ", sub_mode == 0 ? "liters" : "gallons");
        scanf("%lf", &cost);
    }
}

void show_info(void) {
    if (sub_mode == 0 || sub_mode == 1)
        printf("Fuel consumption is %.2lf leters per %s.\n", distance / cost, sub_mode == 0 ? "100 km" : "gallon");
}
