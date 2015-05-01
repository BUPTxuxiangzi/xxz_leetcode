/*问题描述
Longest Palindromic Substring 

Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
 */



/*
解法1：Manacher算法，抄答案而来
Status: Accepted
Runtime: 15 ms
 */
class Solution
{
public:
    //http://articles.leetcode.com/2011/11/longest-palindromic-substring-part-ii.html
    //http://www.open-open.com/lib/view/open1419150233417.html
    
    //transform S to T
    //for example, S = "abba", T = "^#a#b#b#a#$".
    // ^ and $ signs are sentinels appended to each end to avoid bounds checking 
    string preProcess(string s)
    {
        int n = s.size();
        if (0==n) 
        {
            return "^$";
        }
        
        string ret = "^";
        for (int i=0; i!=n; ++i)
        {
            ret += ("#" + s.substr(i, 1) );
        }
        
        ret += "#$";
        return ret;
    }

    string longestPalindrome(string s)
    {
        string T = preProcess(s);
        const int n = T.size();
        int *P = new int[n];
        int C = 0;
        int R = 0;

        //This "for" loop is to calculate the array P[n]
        for (int i=1; i!=n-1; ++i)//T[0] is ^, and skip it
        {
            int i_mirror = 2*C - i; //equal to i' = C - (i-C)
            
            P[i] = (R > i) ? min(R-i, P[i_mirror]) : 0;
                        
            //Attempt to expand palindrome centerreed at i 
            while (T[i+1+P[i]]==T[i-1-P[i]])
            {
                ++P[i];
            }
            
            //if palindrome centered at i expand post R
            //adjust center based on expanded palindrome
            if (i+P[i]>R)
            {
                C = i;
                R = i + P[i];
            }
        }
        
        //find the maxmum element in P
        int max_len = 0;
        int centerIndex = 0;
        for (int i=1; i!=n-1; ++i)
        {
            if (P[i]>max_len)
            {
                max_len = P[i];
                centerIndex = i;
            }
        }
        
        delete[] P;
        
        return s.substr((centerIndex - 1 - max_len)/2, max_len);
    }
};


/*解法2：
改进版暴力求解，从中间向两边扩展

中心扩展就是把给定的字符串的每一个字母当做中心，向两边扩展，这样来找最长的子回文串。算法复杂度为
O(N^2)。
但是要考虑两种情况：
1、像aba，这样长度为奇数。
2、像abba，这样长度为偶数。

Status: Accepted
Runtime: 213 ms
可以看出，时间基本上是15^2，慢了一个数量级
 */
class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.size() < 2)
        {
            return s;
        }
        
        int max_len = 0;
        string::iterator start_pos = s.begin();
        
        for (auto index=next(s.begin()); index <s.end(); ++index)//like "aba"
        {
            auto low = prev(index);
            auto high = next(index);
            while (low>=s.begin() && high<s.end() && *low==*high)
            {
                if (high-low+1>max_len)
                {
                    max_len = high -low + 1;
                    start_pos = low;
                }
                
                --low;
                ++high;
            }
        }//end of for
        
        for(auto index=next(s.begin()); index<s.end(); ++index)//like "abba"
        {
            auto low = prev(index);
            auto high = index;
            while(low>=s.begin() && high<s.end() && *low==*high)
            {
                if(high-low+1>max_len)
                {
                    max_len = high - low + 1;
                    start_pos = low;
                }
                
                --low;
                ++high;
            }
        }//end for
        
        return s.substr(start_pos-s.begin(), max_len);
    }//end of function

};//end of class