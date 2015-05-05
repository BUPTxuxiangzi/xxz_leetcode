/*
Simplify Path Total Accepted: 26971 Total Submissions: 134475

Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

click to show corner cases.
Corner Cases:

    Did you consider the case where path = "/../"?
    In this case, you should return "/".
    Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
    In this case, you should ignore redundant slashes and return "/home/foo".
 */

/*解法：
思路分析：先不看题目的提示，分析linux环境下路径的方式：
1>对于“/home/”,可以简化为/home
2>对于“..”表示回退一个路径（单位）
3>对于“.”,直接忽略
4>对于"...",不必特殊处理

解法|：若是一个字符一个字符的求解，势必会很麻烦，因此，用单词的方式求解。忽略所有的“/”，
在最后的时候，再加上去；忽略单个的.

Status: Accepted
Runtime: 12 ms
 */
class Solution
{
public:
    string simplifyPath(string path)
    {
        vector<string> dirs; //as the stack
        string::iterator i = path.begin();
        string::iterator end = path.end();
        for (; i<end; ++i) //这儿要用<, 而不能用!=, 因为i在内部不是严格递增的
        {
            string::iterator j = find(i, end, '/');
            string dir = string(i, j);//初始化的一种方法，表示[i,j)范围内的元素,i和j必须是迭代器
            //操作结果是：只要不是/,就会生成dir
            //如果是下标形式，则用substr函数

            if (!dir.empty() && dir!=".")//当有连续‘/’时，dir为空
            {
                if (dir=="..")//只有在..且不是最后路径的情况下，才会回退一个单位
                {
                    if (!dirs.empty())
                    {
                        dirs.pop_back();
                    }
                }
                else//包括...这样的形式，也会被存入dirs中
                {
                    dirs.push_back(dir);
                }
            }

            i = j;//不能等于j+1，因为这个循环结束之后，i会++，相当于起了+1作用了
        }// end of for

        string result;
        if (dirs.empty())
        {
            result = "/";
        }
        else
        {
            for (auto s : dirs) 
            {
                result += "/" + s;
            }
        }

        return result;
    }
};