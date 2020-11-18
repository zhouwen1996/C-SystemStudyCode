#include "Solution.h"
#include <iostream>

using namespace std;

Solution::Solution()
{
}


Solution::~Solution()
{
}

bool Solution::isUnique(string astr)
{
	//暴力求解
	/*
	int i_flag[200] = {0};

	for (int i = 0; i < astr.size(); i++)
	{
		i_flag[astr[i]]++;
	}
	for (int i = 0; i < 200; i++)
	{
		if (i_flag[i] > 1)
		{
			return false;
		}
	}
	return true;
	*/
	//位运算；1进行移位，但是如果当一个数&之前异或的数字等于1则表示出现重复的，正常应该为0
	int i_bitFlag = 0;
	for (int i = 0; i < astr.size(); i++)
	{
		if ((1 << (astr[i] - 'a')) & i_bitFlag)//1移动(astr[i] - 'a')到表示astr[i] - 'a')为出现过标为1
		{
			return false;
		}
		else
		{
			i_bitFlag |= 1 << (astr[i] - 'a');
		}
	}
	return true;
}