/*问题描述
Find Minimum in Rotated Sorted Array
Total Accepted: 36368 Total Submissions: 110540

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/

/*
法一：二分查找高效版，每次迭代，只需要比较两次
时间复杂度O(logn), 空间复杂度O(1)
Runtime: 7 ms
*/

class Solution {
public:
	int findMin(vector<int> &num) 
	{

		int len = num.size();
		int l = 0, h = len - 1;//闭区间[l, h]	
		while (l < h)
		{
			int mid = (h + l) >> 1;//以中点为轴, 用位运算的方式，效率远比除的方式高
			if (num[l] <= num[mid])//前半段有序
			{
				if (num[l] <= num[h])//整段的第一个比最后一个小，则最小值必然在前半段
				{
					h = mid;//在前半段
				}
				else//否则在后半段
				{
					l = mid + 1;//在后半段
				}
			}
			else//若前半段无序，则后半段必然有序，即至少有一段是有序的
			{
				if (num[l] >= num[h]) //整段的第一个比最后一个大，则最小的必然在前半段
				{
					h = mid;
				}
				else
				{
					l = mid + 1;
				}
			}
		}//while
		return num[l];
	}
};

/*
法二：加了异常处理的
时间复杂度O(logn), 空间复杂度O(1)
Runtime: 7 ms
*/
class Solution {
public:
	int findMin(vector<int> &num) 
	{
		if (num.empty())
		{
			exit(-1);//异常退出
		}
		int len = num.size();
		int l = 0, h = len - 1;//闭区间[l, h]	
		while (l < h)
		{
			int mid = (h + l) >> 1;//以中点为轴，用位运算的方式，效率远比除的方式高
			if (num[l] <= num[mid])//前半段有序
			{
				if (num[l] <= num[h])//整段的第一个比最后一个小，则最小值必然在前半段
				{
					h = mid;//在前半段
				}
				else//否则在后半段
				{
					l = mid + 1;//在后半段
				}
			}
			else//若前半段无序，则后半段必然有序，即至少有一段是有序的
			{
				if (num[l] >= num[h]) //整段的第一个比最后一个大，则最小的必然在前半段
				{
					h = mid;
				}
				else
				{
					l = mid + 1;
				}
			}
		}//while
		return num[l];
	}
};



