/******************************************************
 * 实验3.3：播放视频文件（固定路径）
 * 功能：在GE6818开发板上使用mplayer播放 /IOT/01.mp4
 ******************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // 直接播放开发板 /IOT 目录下的 01.mp4
    printf("Playing video: /IOT/01.mp4\n");
    printf("Video is playing on LCD... Press any key to stop.\n");
    system("mplayer -vo fbdev2 -fs /IOT/01.mp4 &");
    
    getchar();
    
    // 停止播放
    system("killall -9 mplayer");
    printf("Video stopped.\n");
    
    return 0;
}
