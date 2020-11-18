#pragma once
#include <iostream>
#include <string>
#include<vector>

using namespace std;
class MyFile
{
public:
	MyFile();
	virtual ~MyFile();
	void GetWorkList(string strWorkPath, vector<string>& vctWorkList, bool bSeachChild);
};

