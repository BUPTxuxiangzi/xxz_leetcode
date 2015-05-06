/*Largest Rectangle in Histogram 

Given n non-negative integers representing the histogram's bar height where the width of 
each bar is 1, find the area of largest rectangle in the histogram. 
*/


/* 解法一是穷举法:
对于直方图的每一个右边界，穷举所有的左边界。将面积最大的那个值记录下来。时间复杂度为O(n^2).
单纯的穷举在LeetCode上面过大集合时会超时。可以通过选择合适的右边界，做一个剪枝(Pruning)。
观察发现当height[k] >=height[k - 1]时，无论左边界是什么值，选择height[k]总会比选择
height[k -1]所形成的面积大。因此，在选择右边界的时候，首先找到一个height[k] < height[k - 1]的k，
然后取k - 1作为右边界，穷举所有左边界，找最大面积。  

时间复杂度O(n^2),空间复杂度O(1)
Status: Accepted 
Runtime: 24 m 
*/

class Solution
{
public:
	int largestRectangleArea(vector<int> &height)
	{
		int result = 0;
		int tmp = 0;
		int n = height.size();
		for (int i = 0; i!=n; ++i)
		{
			for (int j = i+1; j != n; ++j)//j的起始位置是i+1，否则当i=0，j=0时，会导师j-1=-1的下标出现
			{
				if (height[j]<height[j - 1])
				{
					i = j - 1;
					break; //找到右边界，停止寻找。
				}
				else
				{
					i = j;//实时更新右边界的值，防止一直没找到。若一直没找到，则最后一个作为边界
				}
			}

			int lowest = height[i];
			for (int k = i; k >= 0; --k)//对于当前的右边界，穷举所有左边界
			{
				if (height[k]<lowest)
				{
					lowest = height[k];
				}

				tmp = lowest * (i - k + 1);
				result = max(result, tmp);
			}
		}

		return result;
	}
};


/*
解法2：用栈，时间复杂度为O(n), 空间复杂度为O(n).


Status: Accepted
Runtime: 31 ms
 */

class Solution
{
public:
	int largestRectangleArea(vector<int> &height)
	{
		stack<int> s;
		height.push_back(0);
		int result = 0;
		int n = height.size();
		int i = 0;
		while(i < n)
		{
			if (s.empty() || height[i]>height[s.top()])
			{
				s.push(i++);
			}
			else
			{
				int tmp = s.top();
				s.pop();
				int currArea = height[tmp] * (s.empty() ? i : i - s.top() - 1);
				result = max(result, currArea);
			}
		}//end of for

		return result;
	}
};