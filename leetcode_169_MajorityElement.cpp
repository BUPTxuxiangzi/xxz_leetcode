/*问题描述
Majority Element
Total Accepted: 29272 Total Submissions: 84928

Given an array of size n, find the majority element. 
The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.
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