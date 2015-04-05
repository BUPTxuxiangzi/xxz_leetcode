/*
Median of Two Sorted Arrays
Total Accepted: 43715 Total Submissions: 244807

There are two sorted arrays A and B of size m and n respectively. 
Find the median of the two sorted arrays. The overall run time 
complexity should be O(log (m+n)).

Tags: divide and conquer, array, binary search
*/
//这是一道非常经典的题。这题更通用的形式是，给定两个已经排序好的数组，
//找到两者所有元素中第k 大的元素

/*法1：直接归并，时间复杂度O(m+n), 空间复杂度O(m+n)
Runtime: 57 ms
虽然可以Accepted，但是明显不符合最优O(logn)的解法
*/
class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
     	vector<int> tmp;
	int i = 0, j = 0;
	while (i != m && j != n)
	{
		if (A[i] <= B[j])
		{
			tmp.push_back(A[i++]);
		}
		else
		{
			tmp.push_back(B[j++]);
		}
	}//while
	while (i != m)
	{
		tmp.push_back(A[i++]);
	}
	while (j != n)
	{
		tmp.push_back(B[j++]);
	}

	if ((m + n) % 2)//m+n是奇数
	{
		return (double)tmp[(m + n) / 2];
	}
	else
	{
		return ((double)tmp[(m + n) / 2 - 1] + (double)tmp[(m + n) / 2]) / 2;
	}   
    }
};

/*法2：
	我们可以考虑从k 入手。如果我们每次都能够删除一个一定在第k 大元
素之前的元素，那么我们需要进行k 次。但是如果每次我们都删除一半呢？由于A 和B 都是有序
的，我们应该充分利用这里面的信息，类似于二分查找，也是充分利用了“有序”。
假设A 和B 的元素个数都大于k/2，我们将A 的第k/2 个元素（即A[k/2-1]）和B 的第k/2
个元素（即B[k/2-1]）进行比较，有以下三种情况（为了简化这里先假设k 为偶数，所得到的结
论对于k 是奇数也是成立的）：
	• A[k/2-1] == B[k/2-1]
	• A[k/2-1] > B[k/2-1]
	• A[k/2-1] < B[k/2-1]
	如果A[k/2-1] < B[k/2-1]，意味着A[0] 到A[k/2-1 的肯定在A [ B 的top k 元素的范围
内，换句话说，A[k/2-1 不可能大于A [ B 的第k 大元素。留给读者证明。
	因此，我们可以放心的删除A 数组的这k/2 个元素。同理，当A[k/2-1] > B[k/2-1] 时，可
以删除B 数组的k/2 个元素。
	当A[k/2-1] == B[k/2-1] 时，说明找到了第k 大的元素，直接返回A[k/2-1] 或B[k/2-1]
即可。
	因此，我们可以写一个递归函数。那么函数什么时候应该终止呢？
	• 当A 或B 是空时，直接返回B[k-1] 或A[k-1]；
	• 当k=1 是，返回min(A[0], B[0])；
	• 当A[k/2-1] == B[k/2-1] 时，返回A[k/2-1] 或B[k/2-1]

*///Runtime: 50 ms

class Solution {
public:
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		int total = m + n;
		if (total & 0x1)// k&0x1计算时先将k变成********八位数据 然后再和0x01相位与，
		{				//目的就是将k的高七位变成0，及屏蔽，得到k的最低位(是0还是1)
			return find_kth(A, m, B, n, total / 2 + 1);
		}
		else
		{
			return (find_kth(A, m, B, n, total / 2) + find_kth(A, m, B, n, total / 2 + 1)) / 2;
		}
	}

private:
	static double find_kth(int A[], int m, int B[], int n, int k)
	{
		//always assume that m is equal or smaller than n
		//即前一个数组的长度小于或等于后一个数组的长度
		if (m > n)
			return find_kth(B, n, A, m, k);
		if (m == 0) //即前一个数组是空数组
			return B[k - 1];
		if (k == 1)//要查找的事第一个（即要查找最小的）
			return min(A[0], B[0]);

		//divide k into two parts
		int pa = min(k / 2, m), pb = k - pa;

		if (A[pa - 1] < B[pb - 1])//意味着A[0]到A[pa-1]区间的数肯定不在AUB的前k个元素范围内
			return find_kth(A + pa, m - pa, B, n, k - pa);
		else if (A[pa - 1] > B[pb - 1])//意味着B[0]到B[pb-1]区间的数肯定不在AUB的前k个元素范围内
			return find_kth(A, m, B + pb, n - pb, k - pb);
		else
			return A[pa - 1];//找到了要查找的元素
	}
};