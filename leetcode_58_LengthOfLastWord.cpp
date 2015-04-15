/*问题描述：
 * Length of Last Word Total Accepted: 41611 Total Submissions: 146156

Given a string s consists of upper/lower-case alphabets and empty space characters ' ', 
return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example,
Given s = "Hello World",
return 5. 
 */

/*解法1：直接求解
Status: Accepted
Runtime: 4 ms
 */
class Solution{
public:
    int lengthOfLastWord(string s)
    {
        int tmp=0;
        int lastLen=0;
        int i = 0;
        int len = s.size();
        while(i<len)
        {
            if(s[i] != ' ')
            {
                ++tmp;
                lastLen = tmp;
            }
            else
            {
                tmp = 0;
            }
            ++i;//while循环时，一定不要忘了这句，可以提前把这句写好，以防止遗忘。
        }
        return lastLen;
    }
};


/*测试案例
源串string	返回值
	" "			0
	"s"			1
	"s "		1
	"s t"		1
	"s t "		1
 */