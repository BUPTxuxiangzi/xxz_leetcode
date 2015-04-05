/*问题描述：
Longest Consecutive Sequence
Total Accepted: 36235 Total Submissions: 124295

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity. 
*/


/*法一：
先排序，再计数，这样时间复杂度为O(nlogn)
显然不符合题目时间复杂度为O(n)的要求
runtime:23ms
*/
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
     	int len = num.size();
	if (len < 2)
	{
		return len;
	}

	sort(num.begin(), num.end());//O(nlogn)
	num.erase(unique(num.begin(), num.end()), num.end());
	int times = 0, tmp = 0;
	for (int i = 1; i != num.size(); i++)
	{
		if (num[i] == num[i - 1] + 1)
		{
			tmp++;
			if (tmp >= times)
			{
				times = tmp;
			}
		}
		else
		{
			tmp = 0;
		}

	}//for

	return times + 1;   
    }
};

/*法二：
用一个哈希表unordered_map<int, bool> imap 记录每个元素是否使用，对每个元素，以该
元素为中心，往左右扩张，直到不连续为止，记录下最长的长度。
runtimes：27ms
*/
class Solution {
public:
	int longestConsecutive(vector<int> &num) {
		int len = num.size();
		if (len < 2)
		{
			return len;
		}

		unordered_map<int, bool> imap;
		for (int i = 0; i != len; i++)
		{
			imap[num[i]] = false;//全部标志位false，以表示未使用过
		}
		int ctimes = 0; //连续次数

		for (int j = 0; j != len; j++)
		{
			if (imap[num[j]])//==true的情况
			{
				continue;
			}
			//未使用过的情况
			int tmp = 1;
			imap[num[j]] = true;//表示访问
			for (int i = num[j] + 1; imap.find(i) != imap.end(); ++i)//找最大的，直到没有
			{//找比num[j]大的，num[j]+1, num[j]+2,..,num[j]+..
				imap[i] = true;//
				++tmp;
			}
			for (int i = num[j] - 1; imap.find(i) != imap.end(); --i)
			{//找比num[j]小的，num[j]11, num[j]-2,..,num[j]-..
				imap[i] = true;
				++tmp;
			}

			ctimes = max(ctimes, tmp);
		}

		return ctimes;
	}
};

/*法三：
依然哈希，不过这次外循环改用范围for语句，即for(auto x : a)
runtimes:31ms
*/

class Solution {
public:
	int longestConsecutive(vector<int> &num) {
		int len = num.size();
		if (len < 2)
		{
			return len;
		}

		unordered_map<int, bool> imap;
		for (int i = 0; i != len; i++)
		{
			imap[num[i]] = false;//全部标志位false，以表示未使用过
		}
		int ctimes = 0; //连续次数

		for (auto j : num)
		{
			if (imap[j])//==true的情况
			{
				continue;
			}
			//未使用过的情况
			int tmp = 1;
			imap[j] = true;//表示访问
			for (int i = j + 1; imap.find(i) != imap.end(); ++i)//找最大的，直到没有
			{//找比j大的，j+1, j+2,..,j+..
				imap[i] = true;//
				++tmp;
			}
			for (int i = j - 1; imap.find(i) != imap.end(); --i)
			{//找比j小的，j-1, j-2,..,j-..
				imap[i] = true;
				++tmp;
			}

			ctimes = max(ctimes, tmp);
		}

		return ctimes;
	}
};