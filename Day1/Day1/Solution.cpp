#pragma once
#include "Solution.h"
#include <vector>
#include <map>

Solution::Solution()
{

}
Solution::~Solution()
{

}
//����֮�ͣ�nums�洢���֣�target��ʾ��Ҫ��֮��Ľ�������������������±�
vector<int> Solution::twoSum(vector<int>& nums, int target){
	//�洢���ؽ��
	vector<int> vec_Ret;
	//��nums���±��ֵ�洢��map��
	map<int, int> mp_Index2Vual;
	for (int i = 0; i < nums.size(); i++)
	{
		mp_Index2Vual[nums[i]] = i;
	}
	//����vector
	int i_Res;
	for (int i = 0; i < nums.size(); i++)
	{
		i_Res = target - nums[i];
		if (mp_Index2Vual.find(i_Res) != mp_Index2Vual.end())
		{
			vec_Ret.push_back(i);
			vec_Ret.push_back(mp_Index2Vual[i_Res]);
			break;
		}
	}
	return vec_Ret;
}

