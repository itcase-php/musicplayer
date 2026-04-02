#pragma once
#include "common.h"
class Res
{
public:
	static Res* GetRes();		//提供共有接口访问数据
	static bool IsMusic(const string& name);	// 判断是否是音乐文件
	static string GetNewName(string name);		// 把原来的音乐文件中的空格替换为下划线
	static void TraverseAllFile();				// 遍历用户提供的文件，获取音乐资源
	static map<int, string>music;				// C++STL ---> 封装好的数据结构体
private:
    Res(); // 单例模式的关键点
};