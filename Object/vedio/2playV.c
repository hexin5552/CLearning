/******************************************************
 * 实验3.4：控制视频播放（暂停/继续/结束）
 * 功能：通过命令行输入指令控制 /IOT/01.mp4 的播放状态
 * 使用命名管道（FIFO）与mplayer进行通信
 ******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FIFO_NAME "/tmp/mplayer_control"

void print_menu()
{
    printf("=====================================\n");
    printf("Video Player Control Menu:\n");
    printf("  p - pause/resume (暂停/继续)\n");
    printf("  s - stop (结束)\n");
    printf("  q - quit (退出程序)\n");
    printf("=====================================\n");
}

int main()
{
    char choice;
    int fifo_fd;
    
    // 创建命名管道
    unlink(FIFO_NAME);
    if(mkfifo(FIFO_NAME, 0777) < 0) {
        perror("mkfifo");
        return -1;
    }
    
    // 启动mplayer，开启slave模式，固定播放 /IOT/01.mp4
    char cmd[256];
    sprintf(cmd, "mplayer -vo fbdev2 -fs -slave -input file=%s /IOT/01.mp4 &", FIFO_NAME);
    system(cmd);
    printf("Video started: /IOT/01.mp4\n");
    
    sleep(2);
    
    fifo_fd = open(FIFO_NAME, O_WRONLY);
    if(fifo_fd < 0) {
        perror("open fifo");
        return -1;
    }
    
    print_menu();
    
    while(1) {
        printf("\nPlease input command: ");
        scanf(" %c", &choice);
        
        switch(choice) {
            case 'p':
                write(fifo_fd, "pause\n", 6);
                printf(">>> Video pause/resume toggled.\n");
                break;
            case 's':
                write(fifo_fd, "quit\n", 5);
                printf(">>> Video stopped.\n");
                close(fifo_fd);
                unlink(FIFO_NAME);
                return 0;
            case 'q':
                write(fifo_fd, "quit\n", 5);
                printf("Exit program.\n");
                close(fifo_fd);
                unlink(FIFO_NAME);
                return 0;
            default:
                printf("Invalid command! Please enter p/s/q.\n");
                print_menu();
                break;
        }
    }
    
    return 0;
}
