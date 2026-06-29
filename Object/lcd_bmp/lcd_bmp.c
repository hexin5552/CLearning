#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define WIDTH 800
#define HEIGHT 480

// 跳过bmp文件头，读取像素数据显示
int main(int argc,char *argv[])
{
    int fb_fd,bmp_fd;
    unsigned short buf[WIDTH*HEIGHT];
    unsigned char temp[3];
    int i,j;

    fb_fd = open("/dev/fb0",O_RDWR);
    bmp_fd = open("1.bmp",O_RDONLY);

    // 跳过54字节BMP表头
    lseek(bmp_fd,54,SEEK_SET);

    // 倒序读取BMP像素
    for(i=HEIGHT-1;i>=0;i--)
    {
        for(j=0;j<WIDTH;j++)
        {
            read(bmp_fd,temp,3);
            // BGR转RGB565
            buf[i*WIDTH+j] = ((temp[2]>>3)<<11)|((temp[1]>>2)<<5)|(temp[0]>>3);
        }
    }
    write(fb_fd,buf,sizeof(buf));

    close(fb_fd);
    close(bmp_fd);
    return 0;
}
