#include "res.h"
map<int, string> Res::music; // 定义静态成员变量
Res* Res::GetRes()
{
    static Res* p=new Res;  // 静态局部变量，确保单例模式
    return p;
}

bool Res::IsMusic(const string& name)
{
    // 判断文件名是否以 ".mp3" 结尾
    int length = name.size();
    // substr --> 截取函数
    return name.substr(length - 4) == ".mp3";
}

string Res::GetNewName(string name)
{
    for (size_t i = 0; i < name.size(); ++i) {
        if (name[i] == ' ') name[i] = '_';
    }
    return name;
}

void Res::TraverseAllFile()
{
    cout << "Please enter the music library URL:";
    string urlRoot;
    cin >> urlRoot;
    filesystem::path url(urlRoot);
    if (!filesystem::exists(url)) {
        cout << "URL error..." << endl;
        exit(0);
    }
    int pos = 1;
    string oldName, newName;
    filesystem::directory_iterator begin(url);
    for (filesystem::directory_iterator end;begin != end;begin++) {
        //当它是文件时，才进行下一步的判断
        if (!filesystem::is_directory(begin->path())) {
            //判定是不是.mp3文件
            if (IsMusic(begin->path().filename().string())) {
                //把原来的音乐文件中的空格替换为下划线
                oldName=urlRoot + "/" + begin->path().filename().string();
                newName = GetNewName(oldName);
                int result=rename(oldName.c_str(), newName.c_str());
                music[pos++] = newName;
            }
        }
    }
    cout << "Music library loaded successfully." << endl;
}

Res::Res()
{
    cout << "Initialize music library........." << endl;
    TraverseAllFile();
}
