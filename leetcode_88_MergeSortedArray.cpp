/*问题描述
Merge Sorted Array
Total Accepted: 47504 Total Submissions: 157379

Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note:
You may assume that A has enough space (size that is greater or equal to m + n) 
to hold additional elements from B. The number of elements initialized in A and 
B are m and n respectively.
*/

class Solution {
public:
    void merge(int A[], int m, int B[], int n) 
    {
    int i = m - 1;//当前A数组的最后一个元素
	int j = n - 1;//当前B数组的最后一个元素
	int k = m + n - 1;//在A的尾部（或者说最终结果的尾部）
	while (0 <= i && 0 <= j)//都没有到达头部
	{
		if (A[i] >= B[j])//A[i]>=B[j]的情况
		{
			A[k] = A[i];
			i--;
			k--;
		}
		else
		{
			A[k] = B[j];
			j--;
			k--;
		}
	}
	//无需考虑A还没有处理到头的情况，因为这种情况下归并后的A的头部，就是原来的A的头部
	//质考虑A到头的情况即可（即B可能没有到头）
	if (0 > i)//即A已经处理到头部，这时候B可能还没有到达头部
	{
		if (0 <= j)//B还没有处理到头部
		{
			for (; j >= 0, k >= 0; j--, k--)
			{
				A[k] = B[j];
			}
		}
	}//B处理完
    }//merge
};