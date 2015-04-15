/*问题描述
Longest Common Prefix 

Write a function to find the longest common prefix string amongst an array of strings. 
 */

/*解法1：直接求解（横向扫描型）
细节题，最重要的是要考虑到前缀有可能不某个string还长的情况，这种情况下需要预先删去超出的部分
Status: Accepted
Runtime: 9 ms
 */
class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        string result;
        if(strs.empty())
        {
            return result;
        }

        vector<string>::iterator iter = strs.begin();
        result = *iter;
        for(iter+1; iter!=strs.end(); ++iter)
        {
            size_t ilen = (*iter).size();//当前string长度
            size_t relen = result.size();//前缀长度
            if(ilen < relen) //预处理，直接截去result比*iter长的部分，因为那部分不可能成为前缀
            {
                result.erase(result.begin()+ilen,result.end());
            }
            size_t i = 0;
            while(i<ilen && i<relen) //后面那句是为了在result短于*iter长度时结束循环
            {
                if(result[i] == (*iter)[i])
                {
                    ++i;
                }
                else
                {
                    result.erase(result.begin()+i,result.end());
                    break;
                }
            }//end of while
        }//end of for
        return result;
    }//function
};//class


/*解法2：纵向扫描
从位置0开始，对每一个位置比较所有字符串，直到遇到第一个不匹配的
时间复杂度O(n1+n2+n3...)
Status: Accepted
Runtime: 7 ms
 */

class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        if(strs.empty())
            return "";

        for(size_t idx = 0; idx != strs[0].size(); ++idx)
        {
            for(size_t i = 1; i != strs.size(); ++i)
            {
                if(strs[i][idx] != strs[0][idx])
                    return strs[0].substr(0, idx);
            }
        }
        return strs[0];//这是为了防止出现全部相等的状况，而没有返回值
    }//function
};//class

