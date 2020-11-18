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
	int reverse1(int x);//������ת
	bool isPalindrome_1(int x);//�ж��Ƿ��ǻ��Ĵ�
	bool isPalindrome(int x);//�ж��Ƿ��ǻ��Ĵ���ʹ���ַ�������
	int romanToInt1(string s);//��������ת��Ϊint��,ʹ�õݹ��ַ�����ʽ���
	int romanToInt(string s);//��������ת��Ϊint��,�����ó�
	string longestCommonPrefix(vector<string>& strs);//�����ǰ׺
	bool isValid(string s);//�����������Ƿ���Ч
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);//�������
	int lengthOfLongestSubstring(string s);//���ظ��ַ�����Ӵ�
	string longestPalindrome(string s);//������Ӵ�
	string convert(string s, int numRows);//�ַ�����z����������˳�����
	int maxArea(vector<int>& height);//����������
	vector<vector<int>> threeSum(vector<int>& nums);//����֮��
	ListNode* mergeKLists(vector<ListNode*>& lists);//�ϲ�K����������
	ListNode* removeNthFromEnd(ListNode* head, int n);//ɾ������ĵ�����n��Ԫ��
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);//Ѱ�����������������λ��
	int myAtoi(string str);//�ַ���ת������ atoi����ʵ��
	vector<string> letterCombinations(string digits);//�绰�������ĸ���
	int findMaxConsecutiveOnes(vector<int>& nums);//�������1�ĸ���
	int findPoisonedDuration(vector<int>& timeSeries, int duration);//��Ī����
	int findPoisonedDuration1(vector<int>& timeSeries, int duration);
	int thirdMax(vector<int>& nums);//���������
	

	//��̬�滮
	int maxSubArray(vector<int>& nums);//������������к�
	int climbStairs(int n);//��¥��
	int maxProfit(vector<int>& prices);//������Ʊ�����ʱ��
	int rob(vector<int>& nums);//��ҽ���
	int uniquePaths(int m, int n);//��ͬ·��
	int numDecodings(string s);//���뷽��
};

