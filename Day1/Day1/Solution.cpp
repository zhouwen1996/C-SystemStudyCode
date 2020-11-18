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
//两数之和，nums存储数字，target表示需要加之后的结果，返回这两个数的下标
vector<int> Solution::twoSum(vector<int>& nums, int target){
	//存储返回结果
	vector<int> vec_Ret;
	//将nums的下标和值存储到map中
	map<int, int> mp_Index2Vual;
	for (int i = 0; i < nums.size(); i++)
	{
		mp_Index2Vual[nums[i]] = i;
	}
	//遍历vector
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

