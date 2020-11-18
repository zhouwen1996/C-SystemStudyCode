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
	//�������
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
	//λ���㣻1������λ�����������һ����&֮ǰ�������ֵ���1���ʾ�����ظ��ģ�����Ӧ��Ϊ0
	int i_bitFlag = 0;
	for (int i = 0; i < astr.size(); i++)
	{
		if ((1 << (astr[i] - 'a')) & i_bitFlag)//1�ƶ�(astr[i] - 'a')����ʾastr[i] - 'a')Ϊ���ֹ���Ϊ1
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