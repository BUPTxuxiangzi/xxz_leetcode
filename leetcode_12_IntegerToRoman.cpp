/*题目描述：
Integer to Roman 
Given an integer, convert it to a roman numeral.
Input is guaranteed to be within the range from 1 to 3999.
 */

/*
解法1：优秀的解法，直接用索引的方式
思路：关键在于，要将900，400，90，40，9，4这五个数也列出来，因为如果不列出来，会使处理的难度
增加太多。
Status: Accepted
Runtime: 45 ms
 */

class Solution
{
public:
    string intToRoman(int num)
    {
        vector<int> index{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> rom{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string result;
        for (size_t i=0; num>0; ++i)
        {
            int tmp = num / index[i];
            num = num % index[i];
            if (0==tmp)//其实这个if可以省略的，但是去掉了，速度会慢很多
            {
                continue;
            }
            else
            {
                for(int j=0; j!=tmp; ++j)
                {
                    result += rom[i]; //string可以以+的形式接到一起
                }
            }    
        } //end of for

        return result;
    }
};
/*解法2：自己的一部分思路（用map），加上题解上的思路

Status: Accepted
Runtime: 93 ms（慢了一倍）
 */
class Solution
{
public:
    string intToRoman(int num)
    {
        vector<int> index{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string result;
        for (size_t i=0; num>0; ++i)
        {
            int tmp = num / index[i];
            num = num % index[i];
            if (0==tmp)//其实这个if可以省略的
            {
                continue;
            }
            else
            {
                for(int j=0; j!=tmp; ++j)
                {
                    result += i2r[index[i]]; //string可以以+的形式接到一起
                }
            }    
        } //end of for

        return result;
    }
    
private:
    unordered_map<int, string> i2r{{1000, "M"}, {900, "CM"},
                                   {500, "D"}, {400, "CD"},
                                   {100, "C"}, {90, "XC"},
                                   {50, "L"}, {40, "XL"},
                                   {10, "X"}, {9, "IX"},
                                   {5, "V"}, {4, "IV"}, 
                                   {1, "I"}};

};

