#include "Solution.h"
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <stack>
#include <set>

using namespace std;

Solution::Solution()
{
}


Solution::~Solution()
{
}
/*
力扣第91题 解码方法
by zhouwen 2020.8.19
*/
int Solution::numDecodings(string s)
{
	int i_a1 = 1;
	int i_a2 = 0;
	int i_a3 = 0;
	int i_temp = 0;
	int i_len = s.size();
	int i_cnt = 0;
	int i_IsFlag = 0;
	for (int i = 0; i < i_len; i++)
	{
		if (s[i] == '0')
		{
			i_cnt++;
		}
		else
		{
			i_IsFlag = 1;
			break;
		}
	}
	if (i_cnt == i_len)
	{
		return 0;
	}
	if (i_IsFlag == 1 && i_cnt != 0)
	{
		return 0;
	}
	if (i_len == 0)
	{
		return 0;
	}
	else if (i_len == 1)
	{
		if (s[0] == '0')
		{
			return 0;
		}
		return 1;
	}
	else if (i_len == 2)
	{
		i_temp = (s[0] - '0') * 10 + (s[1] - '0');
		if (i_temp <= 26 && s[1] != '0')
		{
			return 2;
		}
		else
		{
			return 1;
		}
	}
	i_temp = (s[0] - '0') * 10 + (s[1] - '0');
	if (i_temp <= 26 && s[1] != '0')
	{
		i_a2 = 2;
	}
	else
	{
		i_a2 = 1;
	}
	int i_Ret = 0;
	//动态方程为；if(s[i-1] - '0') * 10 + (s[i] - '0')小于等于26则OPT[i] = opt[i-1]+opt[i-2];反之等于opt[i-1]
	for (int i = 2; i < i_len; i++)
	{
		if (s[i-1] == 0)//重新开始
		{
			i_Ret += i_a2;//那么01的处理方式要拿进来
		}
		i_temp = (s[i-1] - '0') * 10 + (s[i] - '0');
		if (i_temp <= 26 && s[i] != 0)
		{
			i_a3 = i_a1 + i_a2;
		}
		else if (i_temp <= 26 && s[i] == 0)
		{
			i_a3 = i_a1;
		}
		else
		{
			i_a3 = i_a2;
		}
		i_a2 = i_a3;
		i_a1 = i_a2;
	}
	return i_a2;
}


/*
力扣第62题 不同路径 
by zhouwen 2020.8.19
*/
int Solution::uniquePaths(int m, int n)
{
	int opt[110][110] = { 0 };

	for (int i = 1; i <= m; i++)
	{
		opt[i][n] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		opt[m][i] = 1;
	}
	//动态方程就是等于正下面加正右边的方法和
	for (int i = n-1; i > 0; i--)//反着来
	{
		for (int j = m - 1; j > 0; j--)
		{
			opt[j][i] = opt[j + 1][i] + opt[j][i + 1];
		}
	}
	return opt[1][1];
}


/*
力扣第198题 打家劫舍
by zhouwen 2020.8.13
*/
int Solution::rob(vector<int>& nums)
{
	int dp[105] = {0};
	if (nums.size() == 0)
	{
		return 0;
	}
	if (nums.size() < 2)
	{
		return nums[0];
	}
	if (nums.size() < 3)
	{
		return max(nums[0], nums[1]);
	}
	dp[0] = nums[0];
	dp[1] = max(nums[0], nums[1]);
	int i_len = nums.size();
	for (int i = 2; i < i_len; i++)
	{
		dp[i] = max(nums[i]+dp[i-2], dp[i-1]);
	}
	return dp[i_len-1];
}

/*
力扣第121题 买卖股票的最佳时期
by zhouwen 2020.8.13
*/
int Solution::maxProfit(vector<int>& prices)
{
	vector<int> dp;
	int i_max = 0;
	dp.push_back(0);

	if (prices.size() < 2)
	{
		return 0;
	}
	if (prices[1] - prices[0] < 0)
	{
		dp.push_back(0);
	}
	else
	{
		dp.push_back(prices[1] - prices[0]);
		i_max = dp[1];
	}
	int i_len = prices.size();
	for (int i = 2; i < i_len; i++)
	{
		if (prices[i] >= prices[i-1])
		{
			dp.push_back(dp[i - 1] + (prices[i] - prices[i - 1]));
		}
		else if ((prices[i] < prices[i - 1]) && ((prices[i] - prices[i - 1] + dp[i - 1]) > 0))
		{
			dp.push_back((prices[i] - prices[i - 1] + dp[i - 1]));
		}
		else
		{
			dp.push_back(0);
		}
		if (dp[i] > i_max)
		{
			i_max = dp[i];
		}
	}
	return i_max;
}


/*
力扣第70题 爬楼梯
by zhouwen 2020.8.13
*/
int Solution::climbStairs(int n)
{
	int i_temp1, i_temp2, i_temp3;//滚动数组形式，因为只与前两个有关，并且不知道n的大小不好定义数组
	if (n == 1)
	{
		return 1;
	}
	else if (n == 2)
	{
		return 2;
	}
	i_temp1 = 1;
	i_temp2 = 2;
	for (int i = 3; i <= n; i++)
	{
		i_temp3 = i_temp1 + i_temp2;
		i_temp1 = i_temp2;
		i_temp2 = i_temp3;
	}
	return i_temp3;
}

/*
力扣第53题 最大子序列和
by zhouwen 2020.8.10
*/
int Solution::maxSubArray(vector<int>& nums)
{
	int i_len = nums.size();
	if (i_len < 1)
	{
		return 0;
	}
	vector<int> dp = nums;
	dp[0] = nums[0];
	for (int i = 1; i < i_len; i++)
	{
		if (dp[i - 1] >= 0)
		{
			dp[i] = dp[i - 1] + nums[i];
		}
		else
		{
			dp[i] = nums[i];
		}
	}
	int i_max = dp[0];
	for (int i = 0; i < i_len; i++)
	{
		i_max = max(i_max, dp[i]);
	}


	return i_max;
}

/*
力扣第414题 第三大的数  不使用维持三个变量的方法，用vector数组来记录第三大的数，第n大也一样
by zhouwen 2020.8.10
*/
int Solution::thirdMax(vector<int>& nums)
{
	vector<int> vc_iBigThird;
	if (nums.size() != 0)
	{
		vc_iBigThird.push_back(nums[0]);
	}
	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[i] > vc_iBigThird[0])
		{
			int i_isExit = count(vc_iBigThird.begin(), vc_iBigThird.end(), nums[i]);
			if (i_isExit == 0)
			{
				vc_iBigThird.push_back(nums[i]);
				sort(vc_iBigThird.begin(), vc_iBigThird.end());
			}
		}
		if (vc_iBigThird.size() < 3)
		{
			int i_isExit = count(vc_iBigThird.begin(), vc_iBigThird.end(), nums[i]);
			if (i_isExit == 0)
			{
				vc_iBigThird.push_back(nums[i]);
				sort(vc_iBigThird.begin(), vc_iBigThird.end());
			}
		}
		if (vc_iBigThird.size() > 3)
		{
			vc_iBigThird.erase(vc_iBigThird.begin());
		}
	}
	if (vc_iBigThird.size() < 3)
	{
		return vc_iBigThird[vc_iBigThird.size() - 1];
	}
	return vc_iBigThird[0];
}

/*
力扣第495题 提莫攻击 相加就两种情况，一个加duration或者加差值
by zhouwen 2020.8.10
*/

int Solution::findPoisonedDuration(vector<int>& timeSeries, int duration)
{
	int i_ret = 0;
	int i_end = 0;
	if (timeSeries.size() != 0)
	{
		i_ret = duration;
		i_end = timeSeries[0] + duration;
	}
	for (int i = 1; i < timeSeries.size(); i++)
	{
		if (i_end < timeSeries[i])//相加就两种情况，一个加duration或者加差值
		{
			i_ret += duration;
		}
		else
		{
			i_ret += (duration - (i_end - timeSeries[i]));
		}
		i_end = timeSeries[i] + duration;
	}
	return i_ret;
}

int Solution::findPoisonedDuration1(vector<int>& timeSeries, int duration)
{
	int i_ret = 0;
	char ch_flag[10000010] = { '0' };
	for (int i = 0; i < timeSeries.size(); i++)
	{
		for (int j = timeSeries[i]; j < timeSeries[i] + duration; j++)
		{
			ch_flag[j] = '1';
		}
	}
	for (int i = 0; i < 10000010; i++)
	{
		if (ch_flag[i] == '1')
		{
			i_ret++;
		}
	}
	return i_ret;
}

/*
力扣第485题 最大连续1的个数
by zhouwen 2020.8.10
*/
int Solution::findMaxConsecutiveOnes(vector<int>& nums)
{
	int i_size = 0;
	int i_cout = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == 1)
		{
			i_cout++;
		}
		else
		{
			if (i_cout > i_size)
			{
				i_size = i_cout;
			}
			i_cout = 0;
		}
	}
	if (i_cout > i_size)//最后面也需要补上的
	{
		i_size = i_cout;
	}
	return i_size;
}

/*
力扣第17题 电话号码的字母组合  递归求解
by zhouwen 2020.8.10
*/
map<char, string> g_mpjilu;
vector<string> g_vcstrRet;
void diguiString(string str_zuhe, string str_src);
vector<string> Solution::letterCombinations(string digits)
{
	vector<string> vc_strRet;
	string str_zuhe = "";
	g_mpjilu['2'] = "abc";
	g_mpjilu['3'] = "def";
	g_mpjilu['4'] = "ghi";
	g_mpjilu['5'] = "jkl";
	g_mpjilu['6'] = "mno";
	g_mpjilu['7'] = "pqrs";
	g_mpjilu['8'] = "tuv";
	g_mpjilu['9'] = "wxyz";
	if (digits == "")
	{
		return vc_strRet;
	}

	diguiString(str_zuhe, digits);

	return g_vcstrRet;
}
//递归求解
void diguiString(string str_zuhe, string str_src)
{
	if (str_src.size() == 0)
	{
		g_vcstrRet.push_back(str_zuhe);
		return;
	}
	else
	{
		//str_src中取出一位
		char ch_temp = str_src[0];
		string str_temp = g_mpjilu[ch_temp];
		str_src = str_src.substr(1, str_src.size()-1);
		for (int i = 0; i < str_temp.size(); i++)
		{
			diguiString(str_zuhe + str_temp[i], str_src);
		}
	}
	return ;
}

/*
力扣第8题 字符串转换整数 atoi函数实现 
by zhouwen 2020.8.6
*/
int Solution::myAtoi(string str)
{
	long long l_ret = 0;
	string str_temp = "";

	//输出0的特殊情况
	//1、全是空格
	//2、第一个字符非空格并且不是数字和-负号、字符串为空
	if (str == "")
	{
		return 0;
	}

	//剔除前置空格
	int  i_flag = 0;
	int i = 0;
	for (i = 0; i < str.size() && i_flag == 0; i++)
	{
		if (str[i] == ' ')
		{
			str_temp += str[i];
		}
		else
		{
			i_flag = 1;//表示遇到非空格字符了
			if ((str[i] != '+') && (str[i] != '-') && !(str[i] >= '0' && str[i] <= '9'))//表示非空的第一个字符不是有效的
			{
				return 0;
			}
		}
	}
	if (i_flag == 0)//表示全是空格
	{
		return 0;
	}

	//处理负数
	int  i_fushuflag = 0;
	int i_startPos = i - 1;
	
	if (str[i-1] == '-')
	{
		i_fushuflag = 1;
		i_startPos = i;
	}
	else if (str[i - 1] == '+')
	{
		i_startPos = i;
	}
	//处理数字
	for (int i = i_startPos; i < str.size(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			l_ret = l_ret * 10 + (str[i] - 48);
			if (l_ret > INT_MAX && i_fushuflag == 0)//如果超出32位int类型则输出int的最大或最小值即可
			{
				return INT_MAX;
			}
			else if (i_fushuflag == 1 && l_ret > 2147483648)
			{
				return INT_MIN;
			}
		}
		else
		{
			break;
		}
	}
	if (i_fushuflag == 1)
	{
		l_ret = -l_ret;
	}
	return l_ret;
}

/*
	力扣hopt100中的第4题 寻找两个正序数组的中位数
	by zhouwen 2020.8.5
*/
double Solution::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	vector<int> vc_iNunRet;
	double f_ret = 0.0;

	int i_numSize1 = nums1.size();
	int i_numSize2 = nums2.size();
	//先考虑特殊情况
	if (i_numSize1 == 0)
	{
		if (i_numSize2%2 == 0)
		{
			f_ret = (nums2[i_numSize2 / 2] + nums2[i_numSize2 / 2 - 1]) / 2.0;
		}
		else
		{
			f_ret = nums2[i_numSize2 / 2];
		}
		return f_ret;
	}
	else if (i_numSize2 == 0)
	{
		if (i_numSize1 % 2 == 0)
		{
			f_ret = (nums1[i_numSize1 / 2] + nums1[i_numSize1 / 2 - 1]) / 2.0;
		}
		else
		{
			f_ret = nums1[i_numSize1 / 2];
		}
		return f_ret;
	}

	if (nums1[i_numSize1 - 1] < nums2[0])
	{
		for (int i = 0; i < i_numSize1; i++)
		{
			vc_iNunRet.push_back(nums1[i]);
		}
		for (int i = 0; i < i_numSize2; i++)
		{
			vc_iNunRet.push_back(nums2[i]);
		}
	}
	else if (nums2[i_numSize2 - 1] < nums1[0])
	{
		for (int i = 0; i < i_numSize2; i++)
		{
			vc_iNunRet.push_back(nums2[i]);
		}
		for (int i = 0; i < i_numSize1; i++)
		{
			vc_iNunRet.push_back(nums1[i]);
		}
	}
	else
	{
		int i_post1 = 0;
		int i_post2 = 0;
		while (i_post1 != i_numSize1 && i_post2 != i_numSize2)
		{
			if (nums1[i_post1] < nums2[i_post2])
			{
				vc_iNunRet.push_back(nums1[i_post1]);
				i_post1++;
			}
			else
			{
				vc_iNunRet.push_back(nums2[i_post2]);
				i_post2++;
			}
		}
		if (i_post1 == i_numSize1)
		{
			for (int i = i_post2; i < i_numSize2; i++)
			{
				vc_iNunRet.push_back(nums2[i]);
			}
		}
		else if (i_post2 == i_numSize2)
		{
			for (int i = i_post1; i < i_numSize1; i++)
			{
				vc_iNunRet.push_back(nums1[i]);
			}
		}
	}
	//计算结果；
	int i_retSize = vc_iNunRet.size();
	if (i_retSize % 2 == 0)
	{
		f_ret = (vc_iNunRet[i_retSize / 2] + vc_iNunRet[i_retSize / 2 - 1]) / 2.0;
	}
	else
	{
		f_ret = vc_iNunRet[i_retSize / 2];
	}
	return f_ret;
}

/*
力扣第19题 删除链表的倒数第n个元素
by zhouwen 2020.8.4
*/
ListNode* Solution::removeNthFromEnd(ListNode* head, int n)
{
	int i_nTemp = n;
	int i_cnt = 1;
	int i_flag = 0;
	ListNode* lt_post = head;
	ListNode* lt_postN = head;
	if (head == NULL)
	{
		return head;
	}
	while (lt_post->next != NULL)//设置这几处顺序花费了时间 或者选用 lt_pos != NULL
	{
		if (i_flag == 1)//设置这几处的先后顺序花费了时间
		{
			lt_postN = lt_postN->next;
		}
		if (i_cnt == n)
		{
			lt_postN = head;
			i_flag = 1;
		}
		lt_post = lt_post->next;

		i_cnt++;
	}
	if (i_cnt == n)
	{
		head = head->next;
	}
	else
	{
		lt_postN->next = lt_postN->next->next;
	}
	
	return head;
}


/*
力扣第23题 合并K个排序序列
by zhouwen 2020.8.3
*/
ListNode* Solution::mergeKLists(vector<ListNode*>& lists)
{
	ListNode* ln_Ret = NULL;
	ListNode* ln_Rettemp = NULL;
	ListNode* ln_temp = NULL;
	vector<ListNode*> vc_lnTemp = lists;
	int i_cnt = vc_lnTemp.size();
	int i_jilu = 0;
	if (i_cnt == 0)
	{
		return ln_Ret;
	}
	if (i_cnt == 1)
	{
		return lists[0];
	}
	for (int i = 0; i < vc_lnTemp.size(); i++)//处理特殊情况
	{
		if (vc_lnTemp[i] == NULL)
		{
			i_cnt--;
		}
	}
	int i_min = 0;
	int i_flagMin = 1; 
	while (i_cnt != 0)
	{
		for (int i = 0; i < vc_lnTemp.size(); i++)
		{
			if (vc_lnTemp[i] != NULL)
			{
				if (i_flagMin == 1)//每次一列对min赋初值
				{
					i_min = vc_lnTemp[i]->val;
					i_flagMin = 0;
				}
				int i_1 = vc_lnTemp[i]->val;

				if (i_1 <= i_min)//找到这一列最小值，用指针记录内存地址
				{
					ln_temp = vc_lnTemp[i];
					i_jilu = i;
					i_min = ln_temp->val;
				}
				
			}
		}
		i_flagMin = 1;
		vc_lnTemp[i_jilu] = vc_lnTemp[i_jilu]->next;//这一行的第一列存在最小值并后续记录则当前行往后移动一个单位
		if (vc_lnTemp[i_jilu] == NULL)
		{
			i_cnt--;
		}
		if (ln_Rettemp == NULL)//利用那个指针记录的位置，将最小值记录下来  
		{
			ln_Rettemp = ln_temp;
			ln_Ret = ln_Rettemp;
		}
		else
		{
			ln_Rettemp->next = ln_temp;
			ln_Rettemp = ln_Rettemp->next;
		}
		ln_temp->next = NULL;
	}
	
	return ln_Ret;
}

/*
力扣第15题 三数之和
by zhouwen 2020.8.2
*/
vector<vector<int>> Solution::threeSum(vector<int>& nums)
{
	vector<vector<int>> vc_vcNumRet;
	vector<int> vc_numTemp = nums;
	vector<int> vc_numRet;
	if (nums.size() < 3)
	{
		return vc_vcNumRet;
	}
	sort(vc_numTemp.begin(), vc_numTemp.end());
	int i_left = 0;
	int i_right = 0;
	for (int i = 0; i < vc_numTemp.size()-2; i++)
	{
		i_left = i + 1;
		i_right = vc_numTemp.size() - 1;
		if (i - 1 >= 0 && vc_numTemp[i] == vc_numTemp[i-1])
		{
			continue;
		}
		while (i_left < i_right)
		{
			if ((vc_numTemp[i] + vc_numTemp[i_left] + vc_numTemp[i_right]) == 0)
			{
				if ((i_right + 1) < vc_numTemp.size() && vc_numTemp[i_left] == vc_numTemp[i_left - 1] && vc_numTemp[i_right] == vc_numTemp[i_right+1])
				{
					i_left++;
					i_right--;
					continue;
				}
				vc_numRet.push_back(vc_numTemp[i]);
				vc_numRet.push_back(vc_numTemp[i_left]);
				vc_numRet.push_back(vc_numTemp[i_right]);
				vc_vcNumRet.push_back(vc_numRet);
				vc_numRet.clear();
				i_left++;
				i_right--;
			}
			else if ((vc_numTemp[i] + vc_numTemp[i_left] + vc_numTemp[i_right]) < 0)
			{
				i_left++;
			}
			else
			{
				i_right--;
			}
		}
	}
	return vc_vcNumRet;
}

/*
	力扣第11题 盛最多水的容器；双向移动的思路
	by zhouwen 2020.7.31
*/
int Solution::maxArea(vector<int>& height)
{
	int i_cout = height.size();
	int i_left = 0;
	int i_right = i_cout - 1;
	int i_captianMax = 0;
	int i_captiantemp = 0;
	while (i_left < i_right)
	{
		i_captiantemp = (i_right - i_left)*(height[i_left] > height[i_right] ? height[i_right] : height[i_left]);
		if (height[i_left] < height[i_right])
		{
			i_left++;
		}
		else
		{
			i_right--;
		}
		if (i_captiantemp > i_captianMax)
		{
			i_captianMax = i_captiantemp;
		}
	}
	return i_captianMax;
}

/*
力扣第6题 Z字形变换
by zhouwen 2020.7.30
*/
string Solution::convert(string s, int numRows)
{
	string str_ret = "";
	vector<string> vec_strRet;
	for (int i = 0; i < numRows; i++)
	{
		vec_strRet.push_back("");
	}
	int i_sLen = s.size();
	int i_flag = -1;
	int i_index = 0;
	if (numRows == 1 || s.size() <= 1)
	{
		return s;
	}
	for (int i = 0; i < i_sLen; i++)
	{
		if (i_index == 0 || i_index == (numRows-1))
		{
			i_flag = -i_flag;
		}
		vec_strRet[i_index] += s[i];
		i_index = i_index + i_flag;
	}
	for (int i = 0; i < numRows; i++)
	{
		str_ret += vec_strRet[i];
	}
	return str_ret;
}


/*
	力扣第5题 最长回文子串；双向移动的思路
	by zhouwen 2020.7.29

	注意：
		处理字符串连续子串问题，使用前后移动(滑动窗口)思路来解决挺好的
*/
string Solution::longestPalindrome(string s)
{
	int i_pos = 0;//回文子串中间元素在s中的位置
	int i_startPos = 0;//回文子串最开始在s中的位置
	int i_endPos = 0;//回文子串最后在s中的位置
	
	int i_sLen = s.size();
	string str_PalindromeRet = "";
	int i_PalindromeStrSize = 0;
	string str_temp = "";

	for (int i = 0; i < i_sLen - i_PalindromeStrSize / 2; i++)//减去- i_PalindromeStrSize / 2 当剩余长度都小于最大回文子串的一般的时候就没必要再找了
	{
		str_temp = s[i];
		i_pos = i;
		i_startPos = i_pos - 1;
		i_endPos = i_pos + 1;

		//需要这样处理，先查找是否有相同元素的在此基础上再去看是否有不同元素但是前后组成回文串的
		//处理相同元素的回文串如aa，aaaa
		while (i_endPos < i_sLen)//做保护
		{
			if (s[i_pos] == s[i_endPos])//处理相同元素的回文串bb
			{
				str_temp = str_temp + s[i_endPos];
				i_endPos++;
				i++;
			}
			else
			{
				break;
			}
		}
		//处理前后才相同的回文串aba
		while (!(i_startPos < 0 || i_endPos >= i_sLen))//做保护
		{
			if (s[i_startPos] == s[i_endPos])
			{
				str_temp = s[i_startPos] + str_temp + s[i_endPos];
				i_startPos--;
				i_endPos++;
			}
			else
			{
				break;
			}
		}

		if (i_PalindromeStrSize < str_temp.size())
		{
			str_PalindromeRet = str_temp;
			i_PalindromeStrSize = str_PalindromeRet.size();
		}
	}
	return str_PalindromeRet;
}

/*
	力扣第3题 无重复字符的最长子串；双向移动的思路
	by zhouwen 2020.7.28

	注意：
		处理字符串连续子串问题，使用前后移动(滑动窗口)思路来解决挺好的
*/
int Solution::lengthOfLongestSubstring(string s)
{
	set<char> set_chRet;
	int i_max = 0;
	int i_startPos = 0;
	int i_endPos = 1;

	for (int i = 0; i < s.size(); i++)
	{
		set_chRet.insert(s[i]);

		if (i_endPos == i)
		{
			i_endPos = i + 1;
		}
		for (; i_endPos < s.size(); i_endPos++)//滑动窗口解决取连续的问题，如子串
		{
			char ch_temp = s[i_endPos];
			if (set_chRet.count(s[i_endPos]) == 0)
			{
				set_chRet.insert(s[i_endPos]);
			}
			else
			{
				break;
			}
		}
		if (set_chRet.size() > i_max)
		{
			i_max = set_chRet.size();
			i_startPos = i;
		}

		set_chRet.erase(s[i]);//说明第一个元素遇到重复的，则剔除出去看看后面有没有更长的
	}
	string str_ret = s.substr(i_startPos, i_max);

	return i_max;
}
/*
力扣第2题 两数相加，链表同时进行
by zhouwen 2020.7.27
*/
ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2)
{
	if (l1 == NULL)
	{
		return l2;
	}
	if (l2 == NULL)
	{
		return l1;
	}
	ListNode *p_LNRet = NULL;
	ListNode *p_LNRetTempt = NULL; 
	//ListNode *p_LNRetTempt = p_LNRet;//需要测试是否有作用,没有作用的，需要指向有效地址
	
	int i_ret = 0;//记录两个列表单节点和的个位
	int i_jinwei = 0;//记录两个列表单节点和的十位

	for (int i = 0; !(l1 == NULL || l2 == NULL); i++)
	{
		i_ret = (l1->val + l2->val + i_jinwei + 10)%10;
		i_jinwei = (l1->val + l2->val + i_jinwei) / 10;
		ListNode *LnodeTemp =  new ListNode(i_ret);
		if (i == 0)
		{
			p_LNRet = LnodeTemp;
			p_LNRetTempt = p_LNRet;
		}
		else
		{
			p_LNRet->next = LnodeTemp;
			p_LNRet = p_LNRet->next;
		}
		l1 = l1->next;
		l2 = l2->next;
	}
	while (l1 != NULL)
	{
		i_ret = (l1->val + i_jinwei + 10) % 10;
		i_jinwei = (l1->val + i_jinwei) / 10;
		ListNode *LnodeTemp = new ListNode(i_ret);
		p_LNRet->next = LnodeTemp;
		p_LNRet = p_LNRet->next;
		l1 = l1->next;
	}
	while (l2 != NULL)
	{
		i_ret = (l2->val + i_jinwei + 10) % 10;
		i_jinwei = (l2->val + i_jinwei) / 10;
		ListNode *LnodeTemp = new ListNode(i_ret);
		p_LNRet->next = LnodeTemp;
		p_LNRet = p_LNRet->next;
		l2 = l2->next;
	}
	if (i_jinwei != 0)
	{
		ListNode *LnodeTemp = new ListNode(i_jinwei);
		p_LNRet->next = LnodeTemp;
	}

	return p_LNRetTempt;
}

/*
力扣第20题 有效括号；直接使用栈的方法
by zhouwen 2020.7.26
*/
bool Solution::isValid(string s)
{
	stack<char> sta_kuohao;
	if (s == "")
	{
		return true;
	}
	if ((s.size() < 2) || (s[0] == ')' || s[0] == '}' || s[0] == ']'))
	{
		return false;
	}
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
		{
			sta_kuohao.push(s[i]);
		}
		else
		{
			char ch_temp;
			if (sta_kuohao.empty())
			{
				ch_temp = ' ';
			}
			else
			{
				ch_temp = sta_kuohao.top();//要先判断栈是否为空
			}
			if (s[i] == ')' && ch_temp == '(')
			{
				sta_kuohao.pop();
			}
			else if (s[i] == ']' && ch_temp == '[')
			{
				sta_kuohao.pop();
			}
			else if (s[i] == '}' && ch_temp == '{')
			{
				sta_kuohao.pop();
			}
			else
			{
				return false;
			}
		}
	}
	return sta_kuohao.empty();
}

/*
力扣第14题 最长公共前缀 暴力求解
by zhouwen 2020.7.26
*/
string Solution::longestCommonPrefix(vector<string>& strs)
{
	string str_qianzhui = "";
	if (strs.size() < 1)
	{
		return str_qianzhui;
	}
	string str_res = strs[0];
	for (int i = 1; i < strs.size(); i++)
	{
		for (int j = 0; j < strs[i].size() && j < str_res.size(); j++)
		{
			if (str_res[j] == strs[i][j])
			{
				str_qianzhui += strs[i][j];
			}
			else
			{
				break;
			}
		}
		str_res = str_qianzhui;
		str_qianzhui = "";
	}
	return str_res;
}


bool is_spc1jianfa(string str_src, string &str_res, int &i_ret);
int Calue_romanToInt(string str_res);
int getValue(char ch_src);
/*
	力扣第13题 罗马数字转整数
	by zhouwen 2020.7.26

	注意；个人觉得递归的思路还行，虽然没有找规律简便
*/
int Solution::romanToInt(string s)//合理找规律处理
{
	while (s.find("\"") != -1)
	{
		s.erase(s.find("\""), 1);
	}
	int i_ret = 0;
	int i_pre = getValue(s[0]);
	int i_now;
	for (int  i = 1; i < s.size()+1; i++)
	{
		i_now = getValue(s[i]);
		if (i_pre < i_now)
		{
			i_ret -= i_pre;
		}
		else
		{
			i_ret += i_pre;
		}
		i_pre = i_now;
	}
	return i_ret;
}

int getValue(char ch_src)
{
	switch (ch_src)
	{
		case 'I':return 1;
		case 'V':return 5;
		case 'X':return 10;
		case 'L':return 50;
		case 'C':return 100;
		case 'D':return 500;
		case 'M':return 1000;
		default:
			return 0;
	}

}

int Solution::romanToInt1(string s)//使用递归的方法解决罗马数字的特殊情况
{
	while (s.find("\"") != -1)
	{
		s.erase(s.find("\""), 1);
	}
	string str_res;
	int i_ret = 0;
	//如果有减法或者叠加的情况
	if (is_spc1jianfa(s, str_res, i_ret))//先把特殊情况处理了，然后特殊情况两边的都是一个新串组合的
	{
		string str_temp1 = s.substr(0, s.find(str_res));
		int i = s.find(str_res) + strlen(str_res.c_str());
		int j = s.size();
		string str_temp2 = s.substr(s.find(str_res) + strlen(str_res.c_str()), strlen(s.c_str()) - (s.find(str_res) + strlen(str_res.c_str())));
		return romanToInt(str_temp1) + i_ret + romanToInt(str_temp2);//左边  + 特殊情况的 + 右边 不断递归知道没有特殊情况
	}
	else//递归出口 ，没有特殊情况则每个字符就直接代表一个值了，不用特殊处理了
	{
		return Calue_romanToInt(s);
	}
}
int Calue_romanToInt(string str_res)
{
	int i_ret = 0;
	vector<string> vec_leijia = { "I", "V", "X", "L","C", "D", "M" };
	map<string, int> map_menu;
	map_menu["I"] = 1;
	map_menu["V"] = 5;
	map_menu["X"] = 10;
	map_menu["L"] = 50;
	map_menu["C"] = 100;
	map_menu["D"] = 500;
	map_menu["M"] = 1000;
	for (int i = 0; i < vec_leijia.size(); i++)
	{
		if (str_res.find(vec_leijia[i]) != string::npos)
		{
			i_ret += map_menu[vec_leijia[i]];
		}
	}
	return i_ret;
}

bool is_spc1jianfa(string str_src,string &str_res, int &i_ret)
{
	str_res = "";
	map<string, int> map_jianfamenu;
	map_jianfamenu["IV"] = 4;
	map_jianfamenu["IX"] = 9;
	map_jianfamenu["XL"] = 40;
	map_jianfamenu["XC"] = 90;
	map_jianfamenu["CD"] = 400;
	map_jianfamenu["CM"] = 900;
	map<string, int> map_menu;
	map_menu["I"] = 1;
	map_menu["V"] = 5;
	map_menu["X"] = 10;
	map_menu["L"] = 50;
	map_menu["C"] = 100;
	map_menu["D"] = 500;
	map_menu["M"] = 1000;
	vector<string> vec_jianfa = { "IV", "IX", "XL", "XC", "CD", "CM" };
	vector<string> vec_leijia = { "I", "V", "X", "L", "C", "D", "M"};

	//判断是否有减法组合
	for (int i = 0; i < vec_jianfa.size(); i++)
	{
		if (str_src.find(vec_jianfa[i]) != string::npos)
		{
			str_res = vec_jianfa[i];
			i_ret = map_jianfamenu[vec_jianfa[i]];
			return true;
		}
	}

	//判断是否有叠加组合
	string str_srcTmep = str_src;
	for (int i = 0; i < vec_leijia.size(); i++)
	{
		int i_cout = 0;
		string str_find = vec_leijia[i];
		while (str_srcTmep.find(str_find) != string::npos)
		{
			i_cout++;
			str_find += vec_leijia[i];
		}
		if (i_cout > 1)
		{
			for (int j = 0; j < i_cout; j++)
			{
				str_res += vec_leijia[i];
				i_ret += map_menu[vec_leijia[i]];
			}
			return true;
		}
	}

	return false;
}


/*
	力扣第9题 回文数
	by zhouwen 2020.7.26

	注意：
	同样：与数字相关的操作最好合理利用除法取余来处理
*/
bool Solution::isPalindrome(int x)
{
	int i_src = x;
	int i_res = 0;
	if (x < 0)
	{
		return false;
	}

	char ch_temp[30] = { 0 };
	sprintf_s(ch_temp, "%d", x);
	string str_src = ch_temp;
	string str_res = str_src;
	std::reverse(str_res.begin(), str_res.end());
	
	return str_res == str_src;
}
bool Solution::isPalindrome_1(int x)
{
	int i_src = x;
	int i_res = 0;
	if (x < 0)
	{
		return false;
	}
	while (i_src != 0)
	{
		i_res = i_res * 10 + i_src % 10;
		i_src = i_src / 10;
	}
	if (x == i_res)
	{
		return true;
	}
	else
	{
		return false;
	}
}



/*
	力扣第7题 整数反转
	给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
	(其中包括负数，以0结尾的，翻转后超过int范围的的输出0)
	by zhouwen 2020.7.26

	注意：
		与数字相关的操作最好合理利用除法取余来处理
*/
int Solution::reverse(int x)//数学转换 除数取余，
{
	int i_res = 0;
	while (x != 0)
	{
		i_res = i_res * 10 + x % 10;
		x = x / 10;
		if (i_res > INT_MAX || i_res < INT_MIN)
		{
			i_res = 0;
			break;
		}
	}
	return i_res;
}


int Solution::reverse1(int x)//字符串处理形式，将数字进行翻转
{
	int i_res;

	//判断是否是负数
	bool b_isfuFlag = 0;
	if (x < 0)
	{
		b_isfuFlag = 1;
		x = abs(x);
	}

	//处理后置0的问题
	while (x % 10 == 0)
	{
		x = x / 10;
	}

	char ch_temp[50] = { 0 };
	sprintf_s(ch_temp, "%d", x);
	string str_temp = ch_temp;
	std::reverse(str_temp.begin(), str_temp.end());//翻转

	if (b_isfuFlag)
	{
		string str_max = "2147483648";
		long long int  i_temp1 = atol(str_temp.c_str());
		long long int  i_temp2 = atol(str_max.c_str());
		if (i_temp1 > i_temp2)//还需要判断是否大于int的最大范围
		{
			i_res = 0;
		}
		else
		{
			i_res = atoi(str_temp.c_str());//需返回int类型
			i_res = -i_res;
		}
	}
	else
	{
		string str_max = "2147483647";
		long long int  i_temp1 = atol(str_temp.c_str());
		long long int  i_temp2 = atol(str_max.c_str());
		if (i_temp1 > i_temp2)
		{
			i_res = 0;;
		}
		else
		{
			i_res = atoi(str_temp.c_str());
		}
	}



	return i_res;
}

