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
���۵�91�� ���뷽��
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
	//��̬����Ϊ��if(s[i-1] - '0') * 10 + (s[i] - '0')С�ڵ���26��OPT[i] = opt[i-1]+opt[i-2];��֮����opt[i-1]
	for (int i = 2; i < i_len; i++)
	{
		if (s[i-1] == 0)//���¿�ʼ
		{
			i_Ret += i_a2;//��ô01�Ĵ���ʽҪ�ý���
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
���۵�62�� ��ͬ·�� 
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
	//��̬���̾��ǵ�������������ұߵķ�����
	for (int i = n-1; i > 0; i--)//������
	{
		for (int j = m - 1; j > 0; j--)
		{
			opt[j][i] = opt[j + 1][i] + opt[j][i + 1];
		}
	}
	return opt[1][1];
}


/*
���۵�198�� ��ҽ���
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
���۵�121�� ������Ʊ�����ʱ��
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
���۵�70�� ��¥��
by zhouwen 2020.8.13
*/
int Solution::climbStairs(int n)
{
	int i_temp1, i_temp2, i_temp3;//����������ʽ����Ϊֻ��ǰ�����йأ����Ҳ�֪��n�Ĵ�С���ö�������
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
���۵�53�� ��������к�
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
���۵�414�� ���������  ��ʹ��ά�����������ķ�������vector��������¼�������������n��Ҳһ��
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
���۵�495�� ��Ī���� ��Ӿ����������һ����duration���߼Ӳ�ֵ
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
		if (i_end < timeSeries[i])//��Ӿ����������һ����duration���߼Ӳ�ֵ
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
���۵�485�� �������1�ĸ���
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
	if (i_cout > i_size)//�����Ҳ��Ҫ���ϵ�
	{
		i_size = i_cout;
	}
	return i_size;
}

/*
���۵�17�� �绰�������ĸ���  �ݹ����
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
//�ݹ����
void diguiString(string str_zuhe, string str_src)
{
	if (str_src.size() == 0)
	{
		g_vcstrRet.push_back(str_zuhe);
		return;
	}
	else
	{
		//str_src��ȡ��һλ
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
���۵�8�� �ַ���ת������ atoi����ʵ�� 
by zhouwen 2020.8.6
*/
int Solution::myAtoi(string str)
{
	long long l_ret = 0;
	string str_temp = "";

	//���0���������
	//1��ȫ�ǿո�
	//2����һ���ַ��ǿո��Ҳ������ֺ�-���š��ַ���Ϊ��
	if (str == "")
	{
		return 0;
	}

	//�޳�ǰ�ÿո�
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
			i_flag = 1;//��ʾ�����ǿո��ַ���
			if ((str[i] != '+') && (str[i] != '-') && !(str[i] >= '0' && str[i] <= '9'))//��ʾ�ǿյĵ�һ���ַ�������Ч��
			{
				return 0;
			}
		}
	}
	if (i_flag == 0)//��ʾȫ�ǿո�
	{
		return 0;
	}

	//������
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
	//��������
	for (int i = i_startPos; i < str.size(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			l_ret = l_ret * 10 + (str[i] - 48);
			if (l_ret > INT_MAX && i_fushuflag == 0)//�������32λint���������int��������Сֵ����
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
	����hopt100�еĵ�4�� Ѱ�����������������λ��
	by zhouwen 2020.8.5
*/
double Solution::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	vector<int> vc_iNunRet;
	double f_ret = 0.0;

	int i_numSize1 = nums1.size();
	int i_numSize2 = nums2.size();
	//�ȿ����������
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
	//��������
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
���۵�19�� ɾ������ĵ�����n��Ԫ��
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
	while (lt_post->next != NULL)//�����⼸��˳�򻨷���ʱ�� ����ѡ�� lt_pos != NULL
	{
		if (i_flag == 1)//�����⼸�����Ⱥ�˳�򻨷���ʱ��
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
���۵�23�� �ϲ�K����������
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
	for (int i = 0; i < vc_lnTemp.size(); i++)//�����������
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
				if (i_flagMin == 1)//ÿ��һ�ж�min����ֵ
				{
					i_min = vc_lnTemp[i]->val;
					i_flagMin = 0;
				}
				int i_1 = vc_lnTemp[i]->val;

				if (i_1 <= i_min)//�ҵ���һ����Сֵ����ָ���¼�ڴ��ַ
				{
					ln_temp = vc_lnTemp[i];
					i_jilu = i;
					i_min = ln_temp->val;
				}
				
			}
		}
		i_flagMin = 1;
		vc_lnTemp[i_jilu] = vc_lnTemp[i_jilu]->next;//��һ�еĵ�һ�д�����Сֵ��������¼��ǰ�������ƶ�һ����λ
		if (vc_lnTemp[i_jilu] == NULL)
		{
			i_cnt--;
		}
		if (ln_Rettemp == NULL)//�����Ǹ�ָ���¼��λ�ã�����Сֵ��¼����  
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
���۵�15�� ����֮��
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
	���۵�11�� ʢ���ˮ��������˫���ƶ���˼·
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
���۵�6�� Z���α任
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
	���۵�5�� ������Ӵ���˫���ƶ���˼·
	by zhouwen 2020.7.29

	ע�⣺
		�����ַ��������Ӵ����⣬ʹ��ǰ���ƶ�(��������)˼·�����ͦ�õ�
*/
string Solution::longestPalindrome(string s)
{
	int i_pos = 0;//�����Ӵ��м�Ԫ����s�е�λ��
	int i_startPos = 0;//�����Ӵ��ʼ��s�е�λ��
	int i_endPos = 0;//�����Ӵ������s�е�λ��
	
	int i_sLen = s.size();
	string str_PalindromeRet = "";
	int i_PalindromeStrSize = 0;
	string str_temp = "";

	for (int i = 0; i < i_sLen - i_PalindromeStrSize / 2; i++)//��ȥ- i_PalindromeStrSize / 2 ��ʣ�೤�ȶ�С���������Ӵ���һ���ʱ���û��Ҫ������
	{
		str_temp = s[i];
		i_pos = i;
		i_startPos = i_pos - 1;
		i_endPos = i_pos + 1;

		//��Ҫ���������Ȳ����Ƿ�����ͬԪ�ص��ڴ˻�������ȥ���Ƿ��в�ͬԪ�ص���ǰ����ɻ��Ĵ���
		//������ͬԪ�صĻ��Ĵ���aa��aaaa
		while (i_endPos < i_sLen)//������
		{
			if (s[i_pos] == s[i_endPos])//������ͬԪ�صĻ��Ĵ�bb
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
		//����ǰ�����ͬ�Ļ��Ĵ�aba
		while (!(i_startPos < 0 || i_endPos >= i_sLen))//������
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
	���۵�3�� ���ظ��ַ�����Ӵ���˫���ƶ���˼·
	by zhouwen 2020.7.28

	ע�⣺
		�����ַ��������Ӵ����⣬ʹ��ǰ���ƶ�(��������)˼·�����ͦ�õ�
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
		for (; i_endPos < s.size(); i_endPos++)//�������ڽ��ȡ���������⣬���Ӵ�
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

		set_chRet.erase(s[i]);//˵����һ��Ԫ�������ظ��ģ����޳���ȥ����������û�и�����
	}
	string str_ret = s.substr(i_startPos, i_max);

	return i_max;
}
/*
���۵�2�� ������ӣ�����ͬʱ����
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
	//ListNode *p_LNRetTempt = p_LNRet;//��Ҫ�����Ƿ�������,û�����õģ���Ҫָ����Ч��ַ
	
	int i_ret = 0;//��¼�����б��ڵ�͵ĸ�λ
	int i_jinwei = 0;//��¼�����б��ڵ�͵�ʮλ

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
���۵�20�� ��Ч���ţ�ֱ��ʹ��ջ�ķ���
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
				ch_temp = sta_kuohao.top();//Ҫ���ж�ջ�Ƿ�Ϊ��
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
���۵�14�� �����ǰ׺ �������
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
	���۵�13�� ��������ת����
	by zhouwen 2020.7.26

	ע�⣻���˾��õݹ��˼·���У���Ȼû���ҹ��ɼ��
*/
int Solution::romanToInt(string s)//�����ҹ��ɴ���
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

int Solution::romanToInt1(string s)//ʹ�õݹ�ķ�������������ֵ��������
{
	while (s.find("\"") != -1)
	{
		s.erase(s.find("\""), 1);
	}
	string str_res;
	int i_ret = 0;
	//����м������ߵ��ӵ����
	if (is_spc1jianfa(s, str_res, i_ret))//�Ȱ�������������ˣ�Ȼ������������ߵĶ���һ���´���ϵ�
	{
		string str_temp1 = s.substr(0, s.find(str_res));
		int i = s.find(str_res) + strlen(str_res.c_str());
		int j = s.size();
		string str_temp2 = s.substr(s.find(str_res) + strlen(str_res.c_str()), strlen(s.c_str()) - (s.find(str_res) + strlen(str_res.c_str())));
		return romanToInt(str_temp1) + i_ret + romanToInt(str_temp2);//���  + ��������� + �ұ� ���ϵݹ�֪��û���������
	}
	else//�ݹ���� ��û�����������ÿ���ַ���ֱ�Ӵ���һ��ֵ�ˣ��������⴦����
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

	//�ж��Ƿ��м������
	for (int i = 0; i < vec_jianfa.size(); i++)
	{
		if (str_src.find(vec_jianfa[i]) != string::npos)
		{
			str_res = vec_jianfa[i];
			i_ret = map_jianfamenu[vec_jianfa[i]];
			return true;
		}
	}

	//�ж��Ƿ��е������
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
	���۵�9�� ������
	by zhouwen 2020.7.26

	ע�⣺
	ͬ������������صĲ�����ú������ó���ȡ��������
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
	���۵�7�� ������ת
	����һ�� 32 λ���з�������������Ҫ�����������ÿλ�ϵ����ֽ��з�ת��
	(���а�����������0��β�ģ���ת�󳬹�int��Χ�ĵ����0)
	by zhouwen 2020.7.26

	ע�⣺
		��������صĲ�����ú������ó���ȡ��������
*/
int Solution::reverse(int x)//��ѧת�� ����ȡ�࣬
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


int Solution::reverse1(int x)//�ַ���������ʽ�������ֽ��з�ת
{
	int i_res;

	//�ж��Ƿ��Ǹ���
	bool b_isfuFlag = 0;
	if (x < 0)
	{
		b_isfuFlag = 1;
		x = abs(x);
	}

	//�������0������
	while (x % 10 == 0)
	{
		x = x / 10;
	}

	char ch_temp[50] = { 0 };
	sprintf_s(ch_temp, "%d", x);
	string str_temp = ch_temp;
	std::reverse(str_temp.begin(), str_temp.end());//��ת

	if (b_isfuFlag)
	{
		string str_max = "2147483648";
		long long int  i_temp1 = atol(str_temp.c_str());
		long long int  i_temp2 = atol(str_max.c_str());
		if (i_temp1 > i_temp2)//����Ҫ�ж��Ƿ����int�����Χ
		{
			i_res = 0;
		}
		else
		{
			i_res = atoi(str_temp.c_str());//�践��int����
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

