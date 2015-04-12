/*问题描述
 *Count and Say Total Accepted: 38112 Total Submissions: 149682

The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string. 
 */

/*解法1：递归调用
Accepted 	
Runtimes2 ms 
*/

class Solution {
public:
    string countAndSay(int n) {
     	if (1 == n)
	{
		return "1" ;
	}

	string s = countAndSay(n - 1);

	string result;
	int index = 0;
	int count = 0;
	char tmp = s[index];
	int len = s.size();
	for (int i = 1; i != len; ++i)
	{
		if (s[i] == s[index])
		{
			count++;
		}
		else
		{
			result.push_back(count + 1 + '0');
			result.push_back(tmp);
			
			count = 0; 
			index = i;
			tmp = s[index];
		}
	}//endof for

	//最后一个结果存入string中
	result.push_back(count + 1 + '0');
	result.push_back(tmp);

	return result;   
    }
};



/*解法2：leetcode给的答案，还没认真看，抽个时间认真看一下
// @author 连城(http://weibo.com/lianchengzju)
// 时间复杂度O(n^2)，空间复杂度O(n)

 *Status: Accepted
 *Runtime: 6 ms
 */
class Solution {
public:
	string countAndSay(int n)
	{
		string s("1");
		while (--n)
			s = getNext(s);
		return s;
	}
	string getNext(const string &s)
	{
		stringstream ss;
		for (auto i = s.begin(); i != s.end();) {
			auto j = find_if(i, s.end(), bind1st(not_equal_to<char>(), *i));
			ss << distance(i, j) << *i;
			i = j;
		}
		return ss.str();
	}
};