/*题目描述
 Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.

click to show clarification.
Clarification:

    What constitutes a word?
    A sequence of non-space characters constitutes a word.
    Could the input string contain leading or trailing spaces?
    Yes. However, your reversed string should not contain leading or trailing spaces.
    How about multiple spaces between two words?
    Reduce them to a single space in the reversed string.

*/

/*解法1:
先整体翻转,再对各个单词内部翻转。注意，空格的处理。

时间复杂度O(n)+O(n)=O(n), 空间复杂度O(k),其中k为某个单词的长度
Status: Accepted
Runtime: 14 ms
*/
class Solution
{
public:
	void reverseWords(string &s)
	{
		//先整体翻转
		reverse(s.begin(), s.end()); //reverse()是泛型算法中的，在algorithm头文件中

		string result;
		string word;
		int len = s.size();//可以使程序减少2ms
		for (int i = 0; i != len; ++i)
		{
			if (s[i] != ' ')
			{
				word.push_back(s[i]);
			}
			else if (!word.empty())//防止s中间有多个空格,空格对应的word是empty的
			{
				reverse(word.begin(), word.end());
				result += word + " ";//注意，如果翻转后的s是以空格结束的，则会导致result末尾出现空格,要去掉空格
				word.clear();
			}
			//else 
		    // continue
			
		}//end for()				
		
		if (!word.empty()) //如果翻转后的s不是是以空格结束的,则最后一个word还没有处理
		{
			reverse(word.begin(), word.end());//处理可能出现的最后一个word
			result += word;//最后一个word接到string中，并且最后不加空格
		}

		if (*prev(result.end()) == ' ') //如果翻转后的s是以空格结束的，则会导致result末尾出现空格,要去掉空格
		{
			result.erase(prev(result.end()));
		}

		s.clear();//不加上这一句,会使得runtime为28ms
		s = result;//无返回值,所以要将最后结果赋给s
	}
};



/*解法2：
抄自discuss
https://leetcode.com/discuss/32666/11ms-understandable%26concise-c-solution
时间复杂度O(n)+O(n)=O(n)，空间复杂度O(1)
Status: Accepted
Runtime: 10 ms
*/

class Solution
{
public:
	void reverseWords(string &s)
	{		
		//以下是对各个word进行翻转
		int len = s.size();
		for (size_t i=0; i<len; ++i)//不能用!=，因为内部会有多次++i，或者--i，用!=可能会导致死循环，即i超过了len也不会停下来
		{
			if (s[i]!=' ')
			{
				int j = i;
				while (i!=len && s[i]!=' ') //这里前一个运算符可以用"!="操作符来取代"<"，因为循环内i是严格自增的，											
				{							//不会在等于len之前先出现大于len的现象。这样可以减少2ms
					++i;
				}
				reverse(s.begin()+j, s.begin()+i);
			}
			else if (i>0 && s[i-1]==' ')
			{
				s.erase(s.begin()+i);
				--i;
			}
		}//end of for()
		
		//先去掉头部的空格，以保证翻转后的string的末尾没有空格
		while (!s.empty() && s[0]==' ')
		{
			s.erase(s.begin());
		}
		
		//去掉空格后， 字符串整体翻转
		reverse(s.begin(), s.end());
		
		//整体翻转后，去掉头部的空格
		while (!s.empty() && s[0]==' ')
		{
			s.erase(s.begin());
		}
		
	}//end of reverseWords()	
};


/*解法3：
抄自discuss
https://leetcode.com/discuss/28062/c-super-clean-in-place-12ms-12-lines
时间复杂度O(n)+O(n)=O(n)，空间复杂度O(1)
Status: Accepted
Runtime: 12 ms
*/

class Solution
{
public:
	void reverseWords(string &s)
	{
		reverse(s.begin(), s.end());
		
		auto left = find_if(s.begin(), s.end(), [] (char c) {return c!=' ';});//第一个非空格
		auto new_end = s.begin();
		string space;
		
		while (left!=s.end())
		{
			auto right = find(left, s.end(), ' ');
			reverse(left, right);
			new_end = copy(space.begin(), space.end(), new_end);
			new_end = copy(left, right, new_end);
			left = find_if(right, s.end(), [] (char c) {return c!=' ';});
			space = " ";
		}
		s.resize(new_end-s.begin());
	}	
};