#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    int fd_lcd;
    int lcd_buf[800*480];
    int i;

    // 填充红色
    for(i=0; i<800*480; i++)
    {
        lcd_buf[i] = 0x00FF0000;
    }

    // 打开 LCD
    fd_lcd = open("/dev/fb0", O_WRONLY);
    if(fd_lcd < 0)
    {
        perror("open lcd failed");
        return -1;
    }

    // 写入显存
    write(fd_lcd, lcd_buf, sizeof(lcd_buf));

    close(fd_lcd);
    return 0;
}