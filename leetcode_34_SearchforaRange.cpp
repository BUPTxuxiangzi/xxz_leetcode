
/*题目描述：
Search for a Range Total Accepted: 39281 Total Submissions: 142051

Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4]. 
 */


/*
OJ判决结果：Accepted
Runtime: 17 ms
 */
class Solution {
public:
	vector<int> searchRange(int A[], int n, int target) {
		vector<int> result;
		if (!n || A[0] > target || A[n - 1] < target)
		{
			result.push_back(-1);
			result.push_back(-1);
			return result;
		}

		int low = 0, high = n - 1; //闭区间[0, n-1]
		int mid = (low + high) >> 1;
		while (low != high && A[mid] != target)//一定要自己品味为什么判决条件是两个
		{
			if (A[mid] < target)
				low = mid + 1;
			else
				high = mid;
			mid = (low + high) >> 1;//两个区间[low, mid], [mid+1, high]
		}

		if (A[mid] != target)
		{
			result.push_back(-1);
			result.push_back(-1);
			return result;
		}
		else
		{
			low = mid;
			high = mid;//从当前找到的位置开始进行前向和后向搜索
			while (A[low] == target && low != -1)//一定要限制low的范围，即限制0是最终能比较的，否则会有无法预料的错误
			{
				--low;
			}
			result.push_back(low + 1);
			while (A[high] == target && high != n)//一定要限制low的范围，否则会有无法预料的错误
			{
				++high;
			}
			result.push_back(high - 1);
			return result;
		}

	}
};