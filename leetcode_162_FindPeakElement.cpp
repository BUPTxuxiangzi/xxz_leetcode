/*问题描述
Find Peak Element
Total Accepted: 21796 Total Submissions: 66965

A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

click to show spoilers.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/

/*法1：顺序查找
runtime：11ms
*/
class Solution {
public:
	int findPeakElement(const vector<int> &num) {
		int len = num.size();
		if (1 == len) //只有一个元素
		{
			return 0;
		}
		if (num[0] > num[1])//第一个就是peak
		{
			return 0;
		}
		if (num[len - 1] > num[len - 2])//最后一个就是peak
		{
			return len - 1;
		}

		for (int i = 1; i != len - 1; i++)
		{
			if (num[i] > num[i - 1] && num[i] > num[i + 1])
				return i;
		}

		//不存在
		exit(-1);
	}
};

/*法2：二分查找(迭代版)
时间复杂度O(logn),空间复杂度O(1)
runtime:9ms
*/
class Solution {
public:
	int findPeakElement(const vector<int> &num) {
		int low = 0;
		int high = num.size() - 1;
		while (low < high)
		{
			int mid = (low + high) / 2; //分成两段[low, mid], [mid+1, high], 
			//以保证无论长度是奇还是偶，前后段长度相差为1或者0
			if (num[mid] < num[mid + 1])
			{
				low = mid + 1;//闭区间[mid+1, high], 所以low = mid +1
			}
			else
			{
				high = mid;//闭区间[low, mid], 所以high = mid
			}
		}//while
		return low;
	}
};

/*法3：二分查找：递归版
时间复杂度O(logn), 空间复杂度O(logn)
runtime:10ms
*/
class Solution {
public:
	int findp(const vector<int> &num, int low, int high)
	{
		if (low == high)
		{
			return low;
		}
		int mid = (low + high) / 2; //分成两段[low, mid], [mid+1, high], 
		//以保证无论长度是奇还是偶，前后段长度相差为1或者0
		if (num[mid] < num[mid + 1])
		{
			return findp(num, mid + 1, high);//闭区间[mid+1, high], 所以low = mid +1
		}
		else
		{
			return findp(num, low, mid);//闭区间[low, mid], 所以high = mid
		}
	}

	int findPeakElement(const vector<int> &num) 
	{
		return findp(num, 0, num.size() - 1);
	}

};