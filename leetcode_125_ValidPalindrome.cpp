/*问题描述
Valid Palindrome 

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome. 
 */

/*解法1：直接求解，先提取出有效字符，再比较。
Status: Accepted
Runtime: 16 ms
这种解法虽然速度快，但是需要考虑的太多，不推荐，建议用解法2。
 */
class Solution {
public:
	bool isPalindrome(string s)
	{
		string newstr;
		int slen = s.size();
		for (int i = 0; i != slen; ++i)  //整个循环所起的作用，就是一个transform，所以太差了
		{
			if (isalpha(s[i]))//是字母
			{
				newstr.push_back(tolower(s[i]));//将所有字母转换为小写字母存入新string中
			}
			else if (isdigit(s[i]))//是数字
			{
				newstr.push_back(s[i]);//是数字，直接存入新数组中
			}
			else//其他情况，直接跳过
			{
				continue;
			}
		}//end for

		int newlen = newstr.size();
		if (!newlen)
		{
			return true;
		}
		int mid = (newlen-1) / 2;
		int j;
		for (j = 0; j <= mid; ++j)
		{
			if (newstr[j] == newstr[newlen - 1 - j])
			{
				;
			}
			else
			{
				break;
			}
		}

		if (j == mid + 1)//因为循环终止的条件是j==mid+1
		{
			return true;
		}
		else//循环终止条件是break
		{
			return false;
		}
	}
};

/*解法2：边处理字符，边判断
改自题解，题解中有错误
Status: Accepted
Runtime: 24 ms
 */
class Solution{
public:
	bool isPalindrome(string s)
	{
		transform(s.begin(), s.end(), s.begin(), ::tolower);//注意，tolower之前一定要加::
		string::iterator left = s.begin(), right = prev(s.end());
		while (left < right)
		{
			if (!::isalnum(*left))
			{
				++left;
			}
			else if (!::isalnum(*right))
			{
				--right;
			}
			else if (*left != *right)
			{
				return false;
			}
			else//题解中没了这一句，错误
			{
				++left;
				--right;
			}

		}//end of while

		return true;
	}
};

/*
tansform函数的作用是：将某操作应用于指定范围的每个元素。transform函数有两个重载版本：

1.transform(first,last,result,op);//first是容器的首迭代器，last为容器的末迭代器，result为存放结果的容器，op为要进行操作的一元函数对象或sturct、class。

2.transform(first1,last1,first2,result,binary_op);//first1是第一个容器的首迭代器，last1为第一个容器的末迭代器，first2为第二个容器的首迭代器，result为存放结果的容器，binary_op为要进行操作的二元函数对象或sturct、class。
注意：第二个重载版本必须要保证两个容器的元素个数相等才行，否则会抛出异常。

http://blog.sina.com.cn/s/blog_8ec0965801012szd.html
 */