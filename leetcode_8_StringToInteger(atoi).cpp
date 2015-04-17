/*题目描述
String to Integer (atoi) 

Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, 
please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given
input specs). You are responsible to gather all the input requirements up front. 
 */

/*
Requirements for atoi:

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
 */


/*解法1：边判断，边处理
对题解上题目的改写，因为题解上的答案是错的，无法检测出“+-”的情况
且无法检测INT_MAX / 10 < num的情况
Status: Accepted
Runtime: 18 ms
 */
class Solution
{
public:
	int myAtoi(string str)
	{
		int num = 0;
		int sign = 1;//默认为正数
		const int len= str.size();
		int i = 0;

		while (str[i] == ' ')
		{
			++i;
		}

		int first = 1;//防止“+-111”形式的出现
		if ('+' == str[i] && first)//其实这个地方的判断条件不必加first，为了美观加上吧
		{
				first = 0;
				++i;
		}

		if ('-' == str[i] && first)//不是第一次出现“+-”其中之一，
		{							//直接跳过。后面会自动处理为异常情况
			first = 0;
			sign = -1;
			++i;
		}

		for (; i != len; ++i)
		{
			if (str[i]<'0' || str[i]>'9')//只要不是数字，就立刻中断
			{
				break;
			}

			if ((INT_MAX / 10 == num && (str[i] - '0') > (INT_MAX % 10)) || INT_MAX / 10 < num)
			{
				return -1 == sign ? INT_MIN : INT_MAX;
			}

			num = num * 10 + str[i] - '0';
		}//end of myAtoi
		return num * sign;
	}//end of myAtoi
};



/*解法2：先将有效的字符存储，再处理，费时费力，抛弃这种思路。
仅仅作为其中劳动过程的一个见证而存在吧！！！
Status: Accepted
Runtime: 19 ms
 */
class Solution
{
public:
	int myAtoi(string str)
	{
		const int len = str.size();
		int i = 0;
		char firstSymbol = '+';//如果没有写，默认为正。例如“11”表示“+11”
		string newstr;//新的string，去除前面空格的
		int counter = 0;
		int first = 1;//标志位，表示第一个“+”或“-”或者数字还没有出现
		while (i != len) //第一轮，对字符串进行先期处理
		{
			if (' ' == str[i])
			{
				if (first)
				{
					++i;
					continue;
				}
				else
				{
					break;;
				}
			}

			if ('+' == str[i] || '-' == str[i])
			{
				if (first &&  (i!=len-1 && '0' <= str[i + 1] && str[i + 1] <= '9'))
				{
					first = 0;
					firstSymbol = str[i++];
				}
				else
				{
					break;
				}
				
			}
			else if ('0' <= str[i] && str[i] <= '9')
			{
				first = 0;
				++counter;
				newstr.push_back(str[i++]);
			}
			else
			{
				break;
			}
				
		}//end of while

		int numlen = counter;
		if (0 == numlen)
		{
			return 0;
		}

		double tmp = 0;
		for (int i = 0; i != numlen; ++i)
		{
			tmp += (newstr[i] - '0') * pow(10, numlen - 1 - i);
		}

		int num = (int)tmp;
		if ('-' == firstSymbol)
		{
			if (num < 0)//溢出，例如-2147483648,在计算num的时候就"2147483648"已经溢出为"-2147483648"
			{
				return INT_MIN;
			}
			else
			{
				return 0 - num;
			}
		}
		else//无符号也默认为正数
		{
			if (num < 0)//溢出
			{
				return INT_MAX;
			}
			else
			{
				return num;
			}
		}
	}//end of atoi
};