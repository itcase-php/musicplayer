#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <map>
#include <filesystem>
#include <vector>
#include <cstdio>
#if defined(__has_include)
#if __has_include(<graphics.h>)
#include <graphics.h>
#else
// 未找到 graphics.h —— 安装 EasyX/WinBGIm 或将头文件目录加入项目 include 路径
#define NO_GRAPHICS_H
#endif
#else
#include <graphics.h> // 如果编译器不支持 __has_include，这里仍尝试包含
#endif

#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
using namespace std;