#include <iostream>
#include <vector>
#include <string>
#include "Solution.h"

using namespace std;

int main()
{
	Solution solution =  Solution();

	//int i_target = 0, i_src = 0;
	//cin >> i_src;
	//i_target = solution.reverse(i_src);
	//cout << i_target;

	//int i_target = 0, i_src = 0;
	//bool b_isPalindrome = false;
	//cin >> i_src;
	//b_isPalindrome = solution.isPalindrome(i_src);

	//string str_src;
	//int i_target = 0;
	//cin >> str_src;
	//i_target = solution.romanToInt(str_src);

	//vector<string> str_res = { "aca", "cba" };
	//solution.longestCommonPrefix(str_res);
	

	//bool b_res = solution.isValid("()]");

	//ListNode* l1 = NULL;
	//ListNode* l2 = NULL;
	//vector<ListNode> vec_ln1;
	//ListNode lntempl11 = ListNode(9);
	//l1 = &lntempl11;
	//ListNode lntempl211 = ListNode(1);
	//ListNode lntempl22 = ListNode(2);
	//ListNode lntempl23 = ListNode(7);
	//l2 = &lntempl211;
	//l2->next = &lntempl22;
	//lntempl22.next = &lntempl23;
	//solution.addTwoNumbers(l1, l2);

	//solution.lengthOfLongestSubstring("aabaab!bb");

	//solution.longestPalindrome("cbbbbc");
	//solution.convert("LEETCODEISHIRING", 3);

	//vector<int> height = {0,0,0,0,1,-1};
	//solution.maxArea(height);

	//solution.threeSum(height);

	/*
	ListNode* l1 = NULL;
	ListNode* l2 = NULL;
	ListNode* l3 = NULL;
	ListNode lntempl1 = ListNode(1);
	ListNode lntempl4 = ListNode(4);
	ListNode lntempl5 = ListNode(5);
	l1 = &lntempl1;
	l1->next = &lntempl4;
	l1->next->next = &lntempl5;
	ListNode lntemp21 = ListNode(1);
	ListNode lntemp24 = ListNode(3);
	ListNode lntemp25 = ListNode(4);
	l2 = &lntemp21;
	l2->next = &lntemp24;
	l2->next->next = &lntemp25;
	ListNode lntemp31 = ListNode(2);
	ListNode lntemp34 = ListNode(6);
	l3 = &lntemp31;
	l3->next = &lntemp34;
	vector<ListNode*> vc_lnTemp; 
	l1 = NULL;
	l2 = NULL;
	l3 = NULL;
	vc_lnTemp.push_back(l1);
	vc_lnTemp.push_back(l2);
	vc_lnTemp.push_back(l3);

	ListNode* l1 = NULL;
	solution.mergeKLists(vc_lnTemp);
	*/

	/*
	ListNode* l1 = NULL;
	ListNode lntempl1 = ListNode(1);
	ListNode lntempl4 = ListNode(4);
	ListNode lntempl5 = ListNode(5);
	ListNode lntempl7 = ListNode(7);
	l1 = &lntempl1;
	l1->next = &lntempl4;
	l1->next->next = &lntempl5;
	lntempl5.next = &lntempl7;
	solution.removeNthFromEnd(l1, 4);
	*/
	//vector<int> vc_iNums1 = {1, 2};
	//vector<int> vc_iNums2 = {3, 4};
	//solution.findMedianSortedArrays(vc_iNums1, vc_iNums2);

	//solution.myAtoi("  -42");

	//solution.letterCombinations("23");

	//vector<int> vc_iNums2 = { 1, 1, 0, 0, 1, 1, 1 };
	//solution.findMaxConsecutiveOnes(vc_iNums2);

	//vector<int> vc_iNums2 = {1,2,2};
	//solution.findPoisonedDuration(vc_iNums2, 5);
	//solution.thirdMax(vc_iNums2);

	//solution.climbStairs(3);

	vector<int> vc_iNums2 = { 1, 2, 3, 1 };
	//solution.maxProfit(vc_iNums2);
	//solution.rob(vc_iNums2);
	//solution.uniquePaths(7,3);
	solution.numDecodings("01");

	system("pause");
}