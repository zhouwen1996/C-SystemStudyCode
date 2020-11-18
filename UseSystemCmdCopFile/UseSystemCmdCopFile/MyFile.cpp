#include "MyFile.h"
#include <io.h>
#include <windows.h>


MyFile::MyFile()
{
}


MyFile::~MyFile()
{
}
void MyFile::GetWorkList(string strWorkPath, vector<string>& vctWorkList, bool bSeachChild)
{
	WIN32_FIND_DATAA FileData;
	HANDLE FileHandle = FindFirstFileA((strWorkPath + "*.*").c_str(), &FileData);
	if(FileHandle == INVALID_HANDLE_VALUE)
	{
		return ;
	}
	do
	{
		if (strcmp(FileData.cFileName, ".") == 0 || strcmp(FileData.cFileName, "..") == 0)
		{
			continue;
		}
		else if ((FileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == FILE_ATTRIBUTE_DIRECTORY)
		{
			if (bSeachChild)
			{
				GetWorkList(strWorkPath + FileData.cFileName + "\\", vctWorkList, bSeachChild);
			}
		}
		else
		{
			vctWorkList.push_back(strWorkPath + FileData.cFileName);
		}
	} while (FindNextFileA(FileHandle, &FileData) != 0);
	FindClose(FileHandle);
	return;
}