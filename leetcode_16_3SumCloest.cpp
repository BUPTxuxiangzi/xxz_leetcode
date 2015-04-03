/*问题描述
3Sum Closest
Total Accepted: 33913 Total Submissions: 125849

Given an array S of n integers, find three integers in S such that the sum 
is closest to a given number, target. Return the sum of the three integers. 
You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).


*/

///法一:暴力求解
//时间复杂度达到O(n3)
//结果：Time Limit Exceeded，所以这种方法是不可取的
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) 
	{
      	int result = *num.begin() + *(num.begin() + 1) + *(num.begin() + 2);
		int width =  abs(target - result);
		for (vector<int>::iterator i = num.begin(); i != num.end() - 2; i++)
		{
			for (vector<int>::iterator j = i + 1; j != num.end() - 1; j++)
			{
				for (vector<int>::iterator k = j + 1; k != num.end(); k++)
				{
					int t = *i + *j + *k;
					int tmp = abs(target - t);
					if (width > tmp)
					{
						result = tmp;
						result = t;
					}
				}
			}
		}
		return result;  
    }
};


/*
方法2,：先排序，在左右夹逼
时间复杂度O(nlogn + n2) = O(n2)
oj运行时间：54ms
*/
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) 
	{
		int result = 0;
		int min_gap = INT_MAX;
		sort(num.begin(), num.end());

		for (auto a = num.begin(); a != prev(num.end(), 2); a++)
		{
			auto b = next(a);
			auto c = prev(num.end());
			while (b < c)
			{
				const int sum = *a + *b + *c;
				const int gap = abs(target - sum);
				if (gap < min_gap)
				{
					min_gap = gap;
					result = sum;
				}
				if (sum < target) b++;
				else c--;
			}
		}
	return result;
    }
};