#pragma once
#include <string>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
	
	Solution();
	~Solution();
	int reverse(int x);
	int reverse1(int x);//整数反转
	bool isPalindrome_1(int x);//判断是否是回文串
	bool isPalindrome(int x);//判断是否是回文串，使用字符串方法
	int romanToInt1(string s);//罗马数字转换为int数,使用递归字符串形式解决
	int romanToInt(string s);//罗马数字转换为int数,遍历得出
	string longestCommonPrefix(vector<string>& strs);//最长公共前缀
	bool isValid(string s);//括号组合最后是否有效
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);//两数相加
	int lengthOfLongestSubstring(string s);//无重复字符的最长子串
	string longestPalindrome(string s);//最长回文子串
	string convert(string s, int numRows);//字符串已z字形排列再顺序输出
	int maxArea(vector<int>& height);//输出最大容量
	vector<vector<int>> threeSum(vector<int>& nums);//三数之和
	ListNode* mergeKLists(vector<ListNode*>& lists);//合并K个排序序列
	ListNode* removeNthFromEnd(ListNode* head, int n);//删除链表的倒数第n个元素
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);//寻找两个正序数组的中位数
	int myAtoi(string str);//字符串转换整数 atoi函数实现
	vector<string> letterCombinations(string digits);//电话号码的字母组合
	int findMaxConsecutiveOnes(vector<int>& nums);//最大连续1的个数
	int findPoisonedDuration(vector<int>& timeSeries, int duration);//提莫攻击
	int findPoisonedDuration1(vector<int>& timeSeries, int duration);
	int thirdMax(vector<int>& nums);//第三大的数
	

	//动态规划
	int maxSubArray(vector<int>& nums);//最大连续子序列和
	int climbStairs(int n);//爬楼梯
	int maxProfit(vector<int>& prices);//买卖股票的最佳时期
	int rob(vector<int>& nums);//打家劫舍
	int uniquePaths(int m, int n);//不同路径
	int numDecodings(string s);//解码方法
};

