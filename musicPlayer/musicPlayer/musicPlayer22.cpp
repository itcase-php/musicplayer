#include "musicplayer.h"
int main()
{
	MusicPlayer* p = new MusicPlayer;
	while (1) {
		p->Menu();
		p->KeyDown();
		system("cls");	// 清屏，适用于 Windows 系统
	}
	return 0;
}