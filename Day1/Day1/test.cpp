#include <iostream>
#include <vector>
#include <map>
#include "Solution.h"

using namespace std;

int main()
{
	Solution sol;
	vector<int> vec_i_nuums;
	vector<int> vec_i_Ret;
	int i_target = 9;

	vec_i_nuums.push_back(2);
	vec_i_nuums.push_back(7);
	vec_i_nuums.push_back(11);
	vec_i_nuums.push_back(15);

	vec_i_Ret = sol.twoSum(vec_i_nuums, i_target);
	if (vec_i_Ret.size() > 1)
		cout << vec_i_Ret[0] << vec_i_Ret[1];
	system("pause");
	return 0;
}
