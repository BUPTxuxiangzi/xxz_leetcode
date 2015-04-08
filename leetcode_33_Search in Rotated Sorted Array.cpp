/*问题面熟
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
 */

/*解法1：二分查找
*OJ判决结果: Accepted
Runtime: 12 ms

 */
class Solution {
public:
	int search(int A[], int n, int target) {
		if (!n)//n为0，即空数组的情况
		{
			return -1;
		}
		int low = 0, high = n - 1;
		int mid;
		while (low != high)
		{
			mid = (low + high) >> 1;
			if (A[low] < A[mid]) //前半段必定是有序的
			{
				if (A[low] <= target && target <= A[mid])//在前半段（有序段）
				{//一定要用双条件限制死了！！！
					high = mid;
				}
				else
				{
					low = mid + 1;
				}
			}
			else//否咋后半段必然有序
			{
				if (A[mid + 1] <= target && target <= A[high])
				{
					low = mid + 1;
				}
				else
				{
					high = mid;
				}
			}
		}//while
		if (A[low] != target)
		{
			return -1;
		}
		else
		{
			return low;
		}
	}
};