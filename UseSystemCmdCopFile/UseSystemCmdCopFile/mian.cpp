#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include "MyFile.h"
using namespace std;

int main()
{
	vector<string> vct_strFilePath;
	MyFile myFile;
	//��ȡ��ǰ·��
	char ch_temp[120];
	GetCurrentDirectoryA(120, ch_temp);
	string str_CurrentPath = ch_temp;
	//cout << str_CurrentPath;
	//�������·����Ŀ¼
	string str_OldPath = str_CurrentPath.substr(0, str_CurrentPath.find("CPulsCode"));
	myFile.GetWorkList(str_OldPath + "Old\\", vct_strFilePath, true);
	

	//ʹ��system�ӿڵ��ýű������ļ�
	for (size_t i = 0; i < vct_strFilePath.size(); i++)
	{
		cout << vct_strFilePath[i] << endl;
		string str_temp = "copy " + vct_strFilePath[i] + " E:\\new\\";
		system(str_temp.c_str());
	}

	system("pause");
	return 0;
}
