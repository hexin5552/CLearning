/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
int main(void) {
    float download_rate,file_site,download_time;
    printf("Please enter download_rate,file_site");
    scanf("%f %f",&download_rate,&file_site);
    download_time = download_rate / 8;
    printf("At %.2f megabits per second, a file of %.2f megabytes \n"
        "downloads in %.2f seconds\n",download_rate,file_site,download_time);
}