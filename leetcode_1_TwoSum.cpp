/*问题描述
Two Sum
Total Accepted: 77135 Total Submissions: 432939

Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, 
where index1 must be less than index2. Please note that your returned answers (both index1 and index2) 
are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2 


运行时间：Runtime: 24 ms
*/

/*
方法1：暴力，复杂度O(n2)，会超时
方法2：hash。用一个哈希表，存储每个数对应的下标，复杂度O(n).
方法3：先排序，然后左右夹逼，排序O(n log n)，左右夹逼O(n)，最终O(n log n)。
	   但是注意，这题需要返回的是下标，而不是数字本身，因此这个方法行不通。
*/


// 方法2：hash。用一个哈希表，存储每个数对应的下标
// 时间复杂度O(n)，空间复杂度O(n)
class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		vector<int> result;
		if (numbers.size() < 2)
		{
			return result;
		}

		unordered_map<int, int> imap;//用哈希函数组织的map
		for (int i = 0; i != numbers.size(); i++)
		{//必须从0开始，因为numbers的下标从0开始
			imap[numbers[i]] = i;
		}

		for (int i = 0; i != numbers.size(); i++)
		{
			const int gap = target - numbers[i];
			if (imap.find(gap) != imap.end() && i != imap[gap]) //找到与numbers[i]相加等于target的数
			{//哈希查找时间复杂度为O(1)													//且不能是自身
				result.push_back(i + 1); //第一个位置
				result.push_back(imap[gap] + 1);//第二个位置
				break;
			}
		}//for
		return result;
	}
};

//哈希表查找的时间复杂度为O(1)；
//哈希表是通过计算hashcode来定位元素位置，所以只需一次即可