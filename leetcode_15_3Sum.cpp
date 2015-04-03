/*问题描述
3Sum
Total Accepted: 48770 Total Submissions: 288933

Given an array S of n integers, are there elements a, b, c in S such that 
a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

    Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
    The solution set must not contain duplicate triplets.

    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)

*/

//解法1：Output Limit Exceeded
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
	vector<vector<int> > result;
	if (3 > num.size())
	{
		return result;
	}
	sort(num.begin(), num.end());
	vector<int> tmp;
	int t;
	for (auto a = num.begin(); a != prev(num.end(), 2); a++)
	{
		auto b = next(a);
		auto c = prev(num.end());
		while (b < c)
		{
			t = *a + *b + *c;
			if (0 == t)
			{
				tmp.push_back(*a);
				tmp.push_back(*b);
				tmp.push_back(*c);
				b++;
				result.push_back(tmp);
				tmp.clear();
			}
			else if (t > 0)
			{
				c--;
			}
			else
			{
				b++;
			}
		}//end of while
	}//end of for

	//去除重复的部分
	if (2 > result.size())
	{
		return result;
	}
	
	auto index = result.begin();
	auto j = next(index);
	while (j != result.end())
	{
		if ((*index)[0] != (*j)[0] || (*index)[1] != (*j)[1] || (*index)[2] != (*j)[2])
		{
			++index;
			(*index)[0] = (*j)[0];
			(*index)[1] = (*j)[1];
			(*index)[2] = (*j)[2];
		}
		++j;
	}
	result.erase(index+1, result.end());	
	return result; 
    }
};

/*
在if (0 == t) b++;之后再加上c--;程序结果一样是Output Limit Exceeded
*/

/*
解法2，
结果：Time Limit Exceeded 
*/
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
	vector<vector<int> > result;
	if (3 > num.size())
	{
		return result;
	}
	sort(num.begin(), num.end());
	int t;
	for (auto a = num.begin(); a != prev(num.end(), 2); ++a)
	{
		auto b = next(a);
		auto c = prev(num.end());
		while (b < c)
		{
			t = *a + *b + *c;
			if (0 == t)
			{
				result.push_back({ *a, *b, *c });
				++b;
				--c;
				
			}
			else if (t > 0)
			{
				--c;
			}
			else
			{
				++b;
			}
		}//end of while
	}//end of for
	sort(result.begin(), result.end());
	result.erase(unique(result.begin(), result.end()), result.end());
	return result;
    }
};


/*解法3：
思路:1.将数组排序，
     2.a 遍历 数组a[0]....a[n-1];         
     3.当 a=a[i]  时   后面的问题 就是 :  a[i+1] 到 a[n-1]中  b+c =-a （编程之美 2.12 快速寻找满足条件的两个数）
	 
        记 b=a[j]=a[i-1]     c=a[k]=a[n-1]   
		若 	b+c  < -a ，j++; 
			b+c > -a  ，j--;    
			b+c=-a 记录下来，并j++;
  4.还有一个问题 就是unique triplet,   所以 a=a[i] 要判断是否和a[i-1]相等，若相等，子问题已经解答。
    也要判断 b和c  是否和之前的相同，若相同，就已经判断过了。
oj结果：Accepted， 75ms
*/
class Solution {
public:
	vector<vector<int> > threeSum(vector<int> &num) {
		vector<vector<int> > result;
		if (3 > num.size())
		{
			return result;
		}
		sort(num.begin(), num.end());
		auto last = num.end();
		for (auto a = num.begin(); a != prev(last, 2); ++a)
		{
			if (a != num.begin() && *a == *prev(a)) 
			{
				continue;
			}
			
			auto b = next(a);
			auto c = prev(last);
			
			while (b < c)
			{
				if (b > next(a) && *b == *prev(b))
				{
					++b;
					continue;
				}
				if (c < prev(last) && *c == *next(c))
				{
					--c;
					continue;
				}

				if (*a + *b + *c > 0)
				{
					--c;
				}
				else if (*a + *b + *c < 0)
				{
					++b;
				}
				else
				{
					result.push_back({ *a, *b, *c });
					++b;
					--c;//有没有这一句，oj上都会通过，
					   //但是有这句话是75ms，没有这句话是77ms，所以加上这句话

				}
			}//end of while
		}//end of for

		return result;
	}
};