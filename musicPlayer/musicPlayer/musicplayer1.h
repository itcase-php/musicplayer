#pragma once
#include "common.h"

class MusicPlayer
{
public:
    MusicPlayer();   // 构造函数
    void Menu();     // 做界面
    void KeyDown();  // 按键交互

    void ShowMusic();// 显示歌单
    void PlayMusic();// 播放音乐
    void PauseMusic();// 暂停音乐
    void ResumeMusic();// 继续播放
    void PreMusic();// 播放上一首
    void NextMusic();// 播放下一首

private:
};
