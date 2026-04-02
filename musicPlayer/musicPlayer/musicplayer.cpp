#include <iostream>
#include "musicplayer.h"  // 包含自定义头文件，需确保该文件存在且声明正确
#include "res.h"
using namespace std;  // 引入标准命名空间，简化cout等标准库调用

MusicPlayer::MusicPlayer()
{
    Res::GetRes();  // 在构造函数中调用资源管理类的静态方法，确保音乐资源被加载
    curIndex = 1;
    cmd.push_back("open ");
    cmd.push_back("play ");
    cmd.push_back("pause ");
    cmd.push_back("resume ");
    cmd.push_back("close ");
}

// 实现MusicPlayer类的Menu函数：打印功能菜单
void MusicPlayer::Menu()
{
    // 使用 ASCII 字符串以避免源文件编码造成的字符串字面量问题
    cout << "--------[NianSiHai Music Player]--------" << endl;
    cout << "\t\t0. Exit" << endl;
    cout << "\t\t1. Play" << endl;
    cout << "\t\t2. Pause" << endl;       // 保持制表符转义
    cout << "\t\t3. Resume" << endl;
    cout << "\t\t4. Next" << endl;
    cout << "\t\t5. Previous" << endl;
    cout << "\t\t6. Shuffle" << endl;
    cout << "----------------------------------------" << endl;  // 分隔线
}

// 实现MusicPlayer类的KeyDown函数：暂空实现（后续可添加按键逻辑）
void MusicPlayer::KeyDown()
{
    // 此处可编写按键事件处理逻辑，当前为空实现
    int userKey = 0;
    //显示歌单--->资源管理
    ShowMusic();
    cout << "Input your choice: " << endl;
	cin >> userKey;  // 从标准输入读取用户选择的按键
    switch (userKey)
    {
    case 0:
        exit(0);
        break;
    case 1:
        PlayMusic();
        break;
    case 2:
        PauseMusic();
        break;
    case 3:
        ResumeMusic();
        break;
    case 4:
        PreMusic();
        break;
    case 5:
        NextMusic();
        break;
    case 6:
        RandomMusic();
        break;
    }
}

void MusicPlayer::ShowMusic()
{
    cout << "Playlist" << endl;
    for (auto v : Res::music) {
        if (v.first == curIndex) {
            cout << v.first << "\t" << v.second << "\t\t" << "<--------" << endl;
        }
        else {
            cout << v.first << "\t" << v.second << endl;
        }
    }
}

void MusicPlayer::PlayMusic()
{
    string openCmd = cmd[CMD::Open] + Res::music[curIndex];
    mciSendStringA(openCmd.c_str(), NULL, 0, NULL);
    string playCmd = cmd[CMD::Play] + Res::music[curIndex];
    mciSendStringA(playCmd.c_str(), NULL, 0, NULL);
}

void MusicPlayer::PauseMusic()
{
    string pauseCmd = cmd[CMD::Pause] + Res::music[curIndex];
    mciSendStringA(pauseCmd.c_str(), NULL, 0, NULL);
}

void MusicPlayer::ResumeMusic()
{
    string resumeCmd = cmd[CMD::Resume] + Res::music[curIndex];
    mciSendStringA(resumeCmd.c_str(), NULL, 0, NULL);
}

void MusicPlayer::PreMusic()
{
    string closeCmd = cmd[CMD::Close] + Res::music[curIndex];
    mciSendStringA(closeCmd.c_str(), NULL, 0, NULL);
    curIndex==1 ? curIndex=Res::music.size() : curIndex--;
    string openCmd = cmd[CMD::Open] + Res::music[curIndex];
    mciSendStringA(openCmd.c_str(), NULL, 0, NULL);
    string playCmd = cmd[CMD::Play] + Res::music[curIndex];
    mciSendStringA(playCmd.c_str(), NULL, 0, NULL);
}

void MusicPlayer::NextMusic()
{
    string closeCmd = cmd[CMD::Close] + Res::music[curIndex];
    mciSendStringA(closeCmd.c_str(), NULL, 0, NULL);
    curIndex==Res::music.size() ? curIndex=1 : curIndex++;
    string openCmd = cmd[CMD::Open] + Res::music[curIndex];
    mciSendStringA(openCmd.c_str(), NULL, 0, NULL);
    string playCmd = cmd[CMD::Play] + Res::music[curIndex];
    mciSendStringA(playCmd.c_str(), NULL, 0, NULL);
}

void MusicPlayer::RandomMusic()
{
    string closeCmd = cmd[CMD::Close] + Res::music[curIndex];
    mciSendStringA(closeCmd.c_str(), NULL, 0, NULL);
    curIndex = rand() % Res::music.size() + 1;
    string openCmd = cmd[CMD::Open] + Res::music[curIndex];
    mciSendStringA(openCmd.c_str(), NULL, 0, NULL);
    string playCmd = cmd[CMD::Play] + Res::music[curIndex];
    mciSendStringA(playCmd.c_str(), NULL, 0, NULL);
}
