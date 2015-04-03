/*问题描述
Rotate Array
Total Accepted: 16641 Total Submissions: 95080

Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different 
ways to solve this problem.

[show hint]
Hint:
Could you do it in-place with O(1) extra space?

Related problem: Reverse Words in a String II

Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.
*/

//解法1，最笨的方法
//时间复杂度O(n+k)，空间复杂度0(k)
//Runtime: 29 ms
class Solution
{
public:
	void rotate(int nums[], int n, int k)
	{	
		if (0 == n)
		{
			return ;
		}

		k = k%n;
		if (0 == k)
		{
			return ;
		}

		vector<int> B;
		for (int i = n - k; i != n; i++)
		{
			B.push_back(nums[i]);
		}

		for (int i = n - 1; i != k - 1; i--)
		{
			nums[i] = nums[i - k];
		}
		vector<int>::iterator iter = B.begin();
		for (int i = 0; i != k; i++)
		{
			nums[i] = *(iter++);
		}
	}
};

/*
这一种是在上面的基础上改的，
时间复杂度O(n+k)，空间复杂度0(k)
运行时间为29ms
*/
class Solution
{
public:
	void rotate(int nums[], int n, int k)
	{
		if (0 == n)
		{
			return;
		}

		k = k%n;
		if (0 == k)
		{
			return;
		}

		int *B = new int[k];
		int index = 0;
		for (int i = n - k; i != n; i++)
		{
			B[index++] = nums[i];
		}

		for (int i = n - 1; i != k - 1; i--)
		{
			nums[i] = nums[i - k];
		}
		for (int i = 0; i != k; i++)
		{
			nums[i] = B[i];
		}
		delete[] B;
	}
};

/*
3次旋转，时间复杂度为O(2n) = O(n)
空间复杂度为O(1)
leetcode oj 上运行的时间为29ms
*/
class Solution {
public:

    void reverse(int A[], int x)
    {
	    int l, h;
    	l = (int)floor(x / 2);
	    h = (int)ceil(x / 2);
    	int i, j;
	    int tmp;
    	for (i = 0, j = x-1; i != l, j >=h; i++, j--)
    	{
	    	tmp = A[j];
	    	A[j] = A[i];
	    	A[i] = tmp;
	    }
    }

    void rotate(int nums[], int n, int k) 
    {
        if (0 == n)
	    {
	    	return;
    	}

	    k = k%n;
    	if (0 == k)
    	{
	    	return;
    	}
	
    	reverse(nums, n);
    	int *p1 = nums;
	    reverse(p1, k);
    	int *p2 = &nums[k];
    	reverse(p2, n - k);
    }
};


