/******************************************************
 * 实验3.1：播放音频文件（固定路径）
 * 功能：在GE6818开发板上使用madplay播放 /IOT/01.mp3
 ******************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // 直接播放开发板 /IOT 目录下的 01.mp3
    printf("Playing audio: /IOT/01.mp3\n");
    system("madplay /IOT/01.mp3 &");
    
    printf("Audio is playing... Press any key to stop.\n");
    getchar();
    
    // 停止播放
    system("killall -9 madplay");
    printf("Audio stopped.\n");
    
    return 0;
}
