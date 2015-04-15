/*问题描述
Roman to Integer 

Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
 */

/*罗马数字
罗马数字有如下符号：

Ⅰ（1）Ⅴ（5）Ⅹ（10）L（50）C（100）D（500）M（1000）

计数规则：

1.若干相同数字连写表示的数是这些罗马数字的和，如III=3；

2.小数字在大数字前面表示的数是用大数字减去小数字，如IV＝4；

3.小数字在大数字后面表示的数是用大数字加上小数字，如VI=6;

组合规则：

(1)基本数字Ⅰ、X 、C 中的任何一个，自身连用构成数目，或者放在大数的右边连用构成数目，
	都不能超过三个；放在大数的左边只能用一个。
(2)不能把基本数字 V 、L 、D 中的任何一个作为小数放在大数的左边采用相减的方法构成数目；
	放在大数的右边采用相加的方式构成数目，只能使用一个。
(3)V 和 X 左边的小数字只能用Ⅰ。
(4)L 和 C 左边的小数字只能用×。
(5)D 和 M 左 边的小数字只能用 C 。

 */

/*分析：
因为必须是正确的罗马数字，才能转换成阿拉伯数字，所以，不必考虑组合规则(即给出的罗马数字
是符合规则的)，只要考虑计数规则就可以了。

令 int t[i] <-> string s[i], int result = 0;

对于计数规则1，则可以表示为t：[i]==t[i-1], 则result = result + t[i] (s[i-1]已经包含在result中)
对于计数规则2，可以表示为：t[i]>t[i-1], 则result = (result-t[i-1]) + (t[i]-t[i-1]), 因为result
		中已经预先包含了t[i-1], 所以要先减去t[i-1], 在加上两个罗马字母组合构成的数(t[i]-t[i-1])
对于计数规则3，可以表示为：t[i] < t[i-1], 则result = result + t[i]
 */


/*解法1：
3999 / 3999 test cases passed.
Status: Accepted
Runtime: 90 ms
注：如果将map不写入private，而是直接写在函数中，Runtime 是 99ms
 */
class Solution {
private:
    unordered_map<char, int> r2i = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, 
    									{'C', 100}, {'D', 500}, {'M', 1000} };

public:
    int romanToInt(string s)
    {
        int result = r2i[s[0]];
        for(size_t j=1; j!=s.size(); ++j)
        {
            if(r2i[s[j]] <= r2i[s[j-1]])
            {
                result += r2i[s[j]];
            }
            else
            {
                result = result - 2*r2i[s[j-1]] + r2i[s[j]];
            }
        }
        return result;
    }
};


/*解法2：迭代器版本
Status: Accepted
Runtime: 89 ms
 */
class Solution
{
private:
	unordered_map<char, int> r2i = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, 
    									{'C', 100}, {'D', 500}, {'M', 1000} };

public:
	int romanToInt(string s)
	{
		string::iterator iter = s.begin();
		int result = r2i[*iter++];
		int pre = result;
		for(; iter != s.end(); ++iter)
		{
			int num = r2i[*iter];
			result += num;
			if(num > pre)
			{
				result = result - 2*num; //因为上一步已经先把num加进来，所以这一步不必加；
                                        //有上一轮循环中，pre已经被加进来，所以要减两次。
			}
			pre = num;
		}//end of for 
		return result;
	}
};