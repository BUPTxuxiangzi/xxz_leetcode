/*问题描述
Remove Element
Total Accepted: 49512 Total Submissions: 152781

Given an array and a value, remove all instances of
 that value in place and return the new length.

The order of elements can be changed. It doesn't
 matter what you leave beyond the new length. 
*/
/*
解题思路：尽管题目说出了新的长度，别的不用管，但是依然
要在原数组上执行删除操作，又要求了in place， 即就地删除，
所以，设置一个标志index，只用来指示新的存储位置，而存储
什么样的数据，由A[i]与elem的关系来判断，相等，不必存储下
来，直接忽略掉；不相等的才需要存储下来。
*/
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
    int index = 0;
	for (int i = 0; i < n; i++)
	{
		if (A[i] != elem)
		{	
		    A[index++] = A[i];
		}
	}
	return index;  
    }
};