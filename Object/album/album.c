#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define WIDTH    800
#define HEIGHT   480

// 延时
void delay(void)
{
    int i, j;
    for (i = 0; i < 1000; i++)
        for (j = 0; j < 10000; j++);
}

// 显示 BMP 图片（RGBA32 全屏版）
void show_bmp(const char *filename)
{
    int lcd_fd, bmp_fd;
    unsigned int lcd_buf[WIDTH * HEIGHT];  // 32位 RGBA
    unsigned char bgr[3];
    int x, y;

    lcd_fd = open("/dev/fb0", O_WRONLY);
    bmp_fd = open(filename, O_RDONLY);

    if (lcd_fd < 0 || bmp_fd < 0) return;

    // 跳过 BMP 头 54字节
    lseek(bmp_fd, 54, SEEK_SET);

    // 全屏逐行读取 + 正确上下方向
    for (y = HEIGHT - 1; y >= 0; y--)
    {
        for (x = 0; x < WIDTH; x++)
        {
            read(bmp_fd, bgr, 3);

            // BGR → RGBA 32位颜色（正确格式）
            unsigned char B = bgr[0];
            unsigned char G = bgr[1];
            unsigned char R = bgr[2];

            // RGBA: A=0xFF(不透明) R G B
            lcd_buf[y * WIDTH + x] = (0xFF << 24) | (R << 16) | (G << 8) | B;
        }
    }

    // 一次性写满全屏
    write(lcd_fd, lcd_buf, sizeof(lcd_buf));
    close(bmp_fd);
    close(lcd_fd);
}

// 数码相册主程序
int main(void)
{
    while (1)
    {
        show_bmp("1.bmp");
        delay();

        show_bmp("2.bmp");
        delay();

        show_bmp("3.bmp");
        delay();

        show_bmp("4.bmp");
        delay();
    }
    return 0;
}
