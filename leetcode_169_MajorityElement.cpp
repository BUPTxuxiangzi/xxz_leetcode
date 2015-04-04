/*问题描述
Majority Element
Total Accepted: 29272 Total Submissions: 84928

Given an array of size n, find the majority element. 
The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/

/*
30ms,时间复杂度O(n), 空间复杂度O(1)
*/
class Solution {
public:
	int majorityElement(vector<int> &num) {
		int nTimes = 0;
		int candidate = 0;
		vector<int>::iterator iter = num.begin();
		for (; iter != num.end(); iter++)
		{
			if (0 == nTimes)
			{
				candidate = *iter;
				nTimes = 1;
			}
			else
			{
				if (candidate == *iter)
				{
					nTimes++;
				}
				else
				{
					nTimes--;
				}
			}
		}//end for
		return candidate;

	}
};

/*法2：先排序，再寻找
runtime: 50ms
*/
class Solution {
public:
	int majorityElement(vector<int> &num) {
		int size = num.size();
		/*这段话不需要了，因为已经假设非空
		if (0==size)
		{
		exit(-1);
		}
		*/
		if (1 == size)
		{
			return num[0];
		}

		sort(num.begin(), num.end());
		int len = 0, tmp = 0;
		int index1 = 0;
		int index2 = 0;
		for (int i = 0; i != size; ++i)
		{
			if (num[i] == num[index1])
			{
				tmp++;
				if (tmp >= len)//即时更新最长的长度记录，且在=的时候就要更新，
				{              //因为考虑{1, 2, 2}这种情况，即只有两种值，一个比另一个只多一个的情况
					len = tmp;
					index2 = index1;
				}
			}
			else
			{

				index1 = i;
				tmp = 0;
			}
		}

		//if (len > (size/2)) //这句话不需要了，因为已经假设一定存在majority element
		return num[index2];

	}
};

/*
法3：先排序，再找中位数，中位数一定是那个majority element
runtime: 53ms
*/
class Solution {
public:
    int majorityElement(vector<int> &v) 
	{
        sort(v.begin(), v.end());
        return v[v.size()/2];
    }
};