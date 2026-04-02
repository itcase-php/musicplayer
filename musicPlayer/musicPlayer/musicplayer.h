#pragma once
#include "common.h"

class MusicPlayer
{
public:
    enum CMD {Open,Play,Pause,Resume,Close};
    MusicPlayer();    // 声明构造函数，必须与 cpp 中的定义匹配
    void Menu();      // 做界面
    void KeyDown();   // 按键交互

    void ShowMusic();
    void PlayMusic();
    void PauseMusic();
    void ResumeMusic();
    void PreMusic();
    void NextMusic();

private:
    int curIndex;       // 当前播放的音乐下标
    vector<string> cmd; // 转存为字符串,方便后续调用系统命令行播放音乐
};