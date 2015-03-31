/*
Pascal's Triangle II
Total Accepted: 36330 Total Submissions: 122605

Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space? 
*/
//自己想出来的解法，用队列
//时间效率为6ms
class Solution {
public:
    vector<int> getRow(int rowIndex) {
    vector<int> result;
	if (0 == rowIndex)
	{
		result.push_back(1);
		return result;
	}
	if (1 == rowIndex)
	{
		result.push_back(1);
		result.push_back(1);
		return result;
	}
	//else, >=2的情况
	deque<int> qtmp;
	qtmp.push_back(1);
	qtmp.push_back(1);
	for (int i = 2; i <= rowIndex; i++)
	{
		qtmp.push_back(1);//帕斯卡三角形某行的第一个元素， 1
		for (int j = 1; j <= i - 1; j++)
		{
			qtmp.push_back(*qtmp.begin() + *(qtmp.begin() + 1));//新队尾元素
			if (!qtmp.empty())
				qtmp.pop_front();//删除队头，以保证满足空间要求O(k)
		}
		qtmp.push_back(1);//帕斯卡三角形某行的最后一个元素， 1
		if (!qtmp.empty())
			qtmp.pop_front();//删除队头，以保证满足空间要求O(k)
	}	
	deque<int>::iterator it = qtmp.begin();
	for (int i = 0; i <= rowIndex; i++)
	{
		result.push_back(*qtmp.begin());
		qtmp.pop_front();
	}
	qtmp.clear();
	return result;    
    }
};

//滚动数组解法
//时间效率为3ms，效率提高了一半
class Solution
{
	public:
	vector<int> getRow(int rowIndex)
	{
		vector<int> array;
		for (int i = 0; i <= rowIndex; i++)
		{
			for (int j = i - 1; j > 0; j--)
			{
				array[j] = array[j - 1]  +array[j];
			}
			array.push_back(1);
		}
		return array;
	}
};