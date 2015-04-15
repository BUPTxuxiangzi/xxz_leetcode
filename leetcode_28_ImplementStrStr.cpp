/*问题描述
Implement strStr().

Returns the index of the first occurrence of needle in haystack, 
or -1 if needle is not part of haystack.
 */

/*法1，暴力求解算法
Status: Accepted
Runtime: 7 ms
 */
class Solution
{

public:
    int strStr(string haystack, string needle)
    {
        int i = 0, j = 0;
        const int hlen = haystack.size();
        const int nlen = needle.size();
        while (i != hlen && j != nlen)
        {
            if (haystack[i] == needle[j])
            {
                ++i;
                ++j;
            }
            else
            {
                i = i - j + 1;//i-j表示退回本轮寻找的起始字符，+1表示本轮其实字符的下一个字符，以开始下一轮比较
                j = 0;
            }
        }

        if (j == nlen) //
        {
            return i - nlen;//i-needle.size()是起始位置
        }

        else
            return -1;
    }

};


//未AC
class Solution
{
private:
    int* getNext(string str)
    {
        int m = str.size();
        int* next = new int[m];
        int t = next[0] = -1;
        int j = 0;
        while(j<m)
        {
            if(t==-1 || str[j]==str[t])
            {
                ++j;
                ++t;
                next[j] = t;
            }
            else
            {
                t = next[t];
            }
        }//end of while

        return next;
    }

public:
    int strStr(string haystack, string needle)
    {
        int* next = getNext(needle);
        int halen = haystack.size(), i=0;
        int nelen = needle.size(), j=0;
        while(i<halen && j<nelen)
        {
            if(j==-1 || haystack[i]==needle[j])
            {
                ++i;
                ++j;
            }
            else
            {
                j = next[j];
            }
        }
        //delete [] next;
        if(j==nelen)
        {
            return i-j;
        }
        else
        {
            return -1;
        }
    }
};