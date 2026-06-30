#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

// 延时函数（单位：毫秒，大概1秒=1000）
void delay_ms(unsigned int ms)
{
    usleep(ms * 1000);
}

int main(void)
{
    int fd_lcd;
    int lcd_buf[800 * 480];
    int i;
    int color;

    // 打开LCD设备
    fd_lcd = open("/dev/fb0", O_WRONLY);
    if (fd_lcd < 0) {
        perror("open lcd failed");
        return -1;
    }

    while (1)  // 死循环：自动切换颜色
    {
        // ================== 红色 ==================
        color = 0x00FF0000;
        for (i = 0; i < 800*480; i++) lcd_buf[i] = color;
        write(fd_lcd, lcd_buf, sizeof(lcd_buf));
        delay_ms(500);  // 亮 0.5 秒

        // ================== 绿色 ==================
        color = 0x0000FF00;
        for (i = 0; i < 800*480; i++) lcd_buf[i] = color;
        write(fd_lcd, lcd_buf, sizeof(lcd_buf));
        delay_ms(500);

        // ================== 蓝色 ==================
        color = 0x000000FF;
        for (i = 0; i < 800*480; i++) lcd_buf[i] = color;
        write(fd_lcd, lcd_buf, sizeof(lcd_buf));
        delay_ms(500);

        // ================== 白色 ==================
        color = 0x00FFFFFF;
        for (i = 0; i < 800*480; i++) lcd_buf[i] = color;
        write(fd_lcd, lcd_buf, sizeof(lcd_buf));
        delay_ms(500);

        // ================== 黑色 ==================
        color = 0x00000000;
        for (i = 0; i < 800*480; i++) lcd_buf[i] = color;
        write(fd_lcd, lcd_buf, sizeof(lcd_buf));
        delay_ms(500);
    }

    close(fd_lcd);
    return 0;
}
