#include "musicplayer.h"
int main()
{
	srand((unsigned int)time(nullptr));	// 设置随机数种子
	MusicPlayer* p = new MusicPlayer;
	while (1) {
		p->Menu();
		p->KeyDown();
		system("cls");	// 清屏，适用于 Windows 系统
	}
	return 0;
}