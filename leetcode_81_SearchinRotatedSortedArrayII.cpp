/*问题描述
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
 */


/*解法1：只需要判断最后一个是否与第一相等即可，若相等，则去掉后面相等的部分
数组操作中，一定一定要注意越界问题，加判断条件，防止越界
Status: Accepted
Runtime: 21 ms
 */
class Solution {
public:
	bool search(int A[], int n, int target) {
		if (!n)//n为0，即空数组的情况
		{
			return false;
		}
		int low = 0, high = n - 1;
		int mid;

		while (low != high)
		{
			if (A[low] != A[high])
			{
				mid = (low + high) >> 1;
				if (A[low] <= A[mid]) //前半段必定是有序的
				{
					if (A[low] <= target && target <= A[mid])//在前半段（有序段）
					{
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
			}
			else//最后的和第一个一样
			{//去掉后面和第一个一样的部分
				int i = high;
				while (A[i] == A[high] && i != low)//一定要双条件约束，以防止越界！！！
				{
					--i;
				}
				high = i;
			}
		}//while
		if (A[low] != target)
		{
			return false;
		}
		else
			return true;
	}
};



/*解法2：照抄discuss讨论区来的
Status: Accepted
Runtime: 14 ms，比解法1快了1/3
 */
bool binSearch(int a[], int l, int h, int target) {
	if (l > h) {
		return false;
	}

	int m = (l + h) / 2;

	if (a[m] == target) {
		return true;
	}

	// the code does not change much except handling the condition like
	// [1,3,1,1,1] or [1,1,1,3,1] & searching for 3
	if (a[m] == a[l] && a[m] == a[h]) {
		if (!binSearch(a, l, m - 1, target)) {
			return binSearch(a, m + 1, h, target);
		}
		return true;
	}

	if (a[m] >= a[l]) {
		if (target >= a[l] && target < a[m]) {
			return binSearch(a, l, m - 1, target);
		}
		else {
			return binSearch(a, m + 1, h, target);
		}
	}
	else {
		if (target > a[m] && target <= a[h]) {
			return binSearch(a, m + 1, h, target);
		}
		else {
			return binSearch(a, l, m - 1, target);
		}
	}
}
bool search(int A[], int n, int target)
{
	return binSearch(A, 0, n - 1, target);
}


/*解法3：照着手册抄的
分析
允许重复元素，则上一题中如果A[m] >= A[l], 那么[l, m] 为递增序列的假设就不能成立了，比
如[1, 3, 1, 1, 1]。
如果A[m] >= A[l] 不能确定递增，那就把它拆分成两个条件：
• 若A[m] > A[l]，则区间[l, m] 一定递增
• 若A[m] == A[l] 确定不了，那就l++，往下看一步即可。

时间复杂度O(n)，空间复杂度O(1)
Runtime: 14 ms
*/
class Solution {
public:
	bool search(int A[], int n, int target) {
		int first = 0, last = n;
		while (first != last) {
			const int mid = (first + last) / 2;
			if (A[mid] == target)
				return true;
			if (A[first] < A[mid]) {
				if (A[first] <= target && target < A[mid])
					last = mid;
				else
					first = mid + 1;
			}
			else if (A[first] > A[mid]) {
				if (A[mid] <= target && target <= A[last - 1])
					first = mid + 1;
				else
					last = mid;
			}
			else
				//skip duplicate one, A[start] == A[mid]
				first++;
		}
		return false;
	}
};