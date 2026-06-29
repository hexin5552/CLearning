/******************************************************
 * 实验3.2：控制音乐播放（暂停/继续/结束）
 * 功能：通过命令行输入指令控制 /IOT/01.mp3 的播放状态
 ******************************************************/

#include <stdio.h>
#include <stdlib.h>

void print_usage()
{
    printf("=====================================\n");
    printf("Music Player Control Menu:\n");
    printf("  p - pause (暂停)\n");
    printf("  c - continue (继续)\n");
    printf("  s - stop (结束)\n");
    printf("  q - quit (退出程序)\n");
    printf("=====================================\n");
}

int main()
{
    char choice;
    int is_playing = 1;
    
    // 启动音乐播放（后台运行）
    system("madplay /IOT/01.mp3 &");
    printf("Music started: /IOT/01.mp3\n");
    
    print_usage();
    
    while(1) {
        printf("\nPlease input command: ");
        scanf(" %c", &choice);
        
        switch(choice) {
            case 'p':  // 暂停
                if(is_playing == 1) {
                    system("killall -19 madplay");
                    printf(">>> Music paused.\n");
                    is_playing = 0;
                } else {
                    printf("Music is already paused or stopped.\n");
                }
                break;
                
            case 'c':  // 继续
                if(is_playing == 0) {
                    system("killall -18 madplay");
                    printf(">>> Music continued.\n");
                    is_playing = 1;
                } else {
                    printf("Music is already playing.\n");
                }
                break;
                
            case 's':  // 结束
                system("killall -9 madplay");
                printf(">>> Music stopped.\n");
                is_playing = 0;
                break;
                
            case 'q':  // 退出程序
                system("killall -9 madplay");
                printf("Exit program.\n");
                return 0;
                
            default:
                printf("Invalid command! Please enter p/c/s/q.\n");
                print_usage();
                break;
        }
    }
    
    return 0;
}
