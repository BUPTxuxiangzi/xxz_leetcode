/*题目描述:Longest Substring Without Repeating Characters
Given a string, find the length of the longest substring without repeating characters. 
For example, the longest substring without repeating letters for "abcabcbb" is "abc", 
which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/

/*解法1:
用两个指针，一个指向当前子串的头，一个指向尾，尾指针不断往后扫描，当有字符前面出现过了，记录当前子串长度和最优解的比较结果。
然后头指针不断往后扫描，直到扫描到一个字符和尾指针相同，则尾指针继续扫描，当尾指针到达字符串结尾，算法结束。
复杂度O(n) + O(n) = O(n)
一个O(n)是头指针用的，一个O(n)是尾指针用的
*/
class Solution
{
public:
	int lengthOfLongestSubstring(string s)
	{
		if (s.size()<=1)
		{
			return s.size();
		}
		
		//else
		bool canUse[256];
		memset(canUse, true, sizeof(canUse));
		int result = 0;
		int count = 0;
		int start_pos = 0;
		int len = s.size();
		for (int i=0; i!=len; ++i)
		{
			if (canUse[s[i]]) //true
			{
				canUse[s[i]] = false;
				++count;
			}
			else
			{
				result = max(result, count);
						
				while (s[start_pos]!=s[i])
				{
					canUse[s[start_pos]] = true;
					++start_pos;
					--count;
				}//头指针指向一个和尾指针指向相同的字符
				
				++start_pos;//相同字符的下一个
				canUse[s[i]] = false;				
			}//end of else
			
		}//end of for()
		result = max(result, count);
		
		return result;
	}	
};


//对上述代码进行优化
class Solution
{
public:
	int lengthOfLongestSubstring(string s)
	{
		//当s为空串时end_pos为0，会自动跳过for循环，最终result = max(0, 0-0);
		//所以不必对空串进行特殊处理
		
		bool canUse[256];
		memset(canUse, true, sizeof(canUse));
		int result = 0;
		int start_pos = 0; //头指针位置
		int len = s.size();
		for (int end_pos=0; end_pos!=len; ++end_pos) //end_pos是尾指针之后的指针
		{
			//s[i]是一个字符型，ASCII码表中用数字0-255来表示，所以可以用s[i]作为索引，查看是否可以使用
			if (canUse[s[end_pos]]) //true
			{
				canUse[s[end_pos]] = false;
			}
			else
			{
				result = max(result, end_pos-start_pos);//end_pos-start_pos是当前不重复子串的长度
						
				while (s[start_pos]!=s[end_pos])
				{
					canUse[s[start_pos]] = true;
					++start_pos;
				}//头指针指向一个和尾指针指向相同的字符
				
				++start_pos;//相同字符的下一个
				canUse[s[end_pos]] = false;				
			}//end of else
			
		}//end of for()
		result = max(result, len-start_pos);
		
		return result;
	}	
};