/*
4Sum
Total Accepted: 30657 Total Submissions: 143357

Given an array S of n integers, are there elements a, b, c, and d in S such that
 a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

    Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
    The solution set must not contain duplicate quadruplets.

    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)

*/

/*
方法1：先排序，然后左右夹逼，时间复杂度O(n^3)
OJ操作结果：196ms
*/
class Solution {
public:
	vector<vector<int> > fourSum(vector<int> &num, int target) {
		vector<vector<int> > result;
		if (num.size() < 4)
		{
			return result;
		}

		sort(num.begin(), num.end());
		vector<int>::iterator a = num.begin();
		vector<int>::iterator last = num.end();
		for (; a != prev(last, 3); a++)
		{
			vector<int>::iterator b = next(a);
			for (; b != prev(last, 2); b++)
			{
				vector<int>::iterator c = next(b);
				vector<int>::iterator d = prev(last);
				while (c < d)
				{
					if (*a + *b + *c + *d > target)
					{
						--d;
					}
					else if (*a + *b + *c + *d < target)
					{
						++c;
					}
					else
					{
						result.push_back({ *a, *b, *c, *d });
						++c;
						--d;
					}
				}//while
			}//for b
		}//for a
		sort(result.begin(), result.end());//先排序，以为了下一步去掉重复的使用
		result.erase(unique(result.begin(), result.end()), result.end());
		return result;
	}
};

/*
方法2：用一个hashmap 先缓存两个数的和
时间复杂度，平均O(n^2)，最坏O(n^4)，空间复杂度O(n^2)
Runtime: 229 ms
*/
class Solution {
public:
	vector<vector<int> > fourSum(vector<int> &num, int target) {
		vector<vector<int> > result;
		if (num.size() < 4)
		{
			return result;
		}

		sort(num.begin(), num.end());
		unordered_map<int, vector<pair<int, int> > > cache;//生成一个缓存
		size_t len = num.size();
		for (size_t a = 0; a != len; ++a)
		{
			for (size_t b = a + 1; b != len; ++b)
			{
				//所建立的缓存的键为num[a]+num[b],值为pair<a, b>即位置
				cache[num[a] + num[b]].push_back(pair<int, int>(a, b));
			}
		}


		for (int c = 0; c != len; ++c)
		{
			for (size_t d = c + 1; d != len; ++d)
			{
				const int key = target - num[c] - num[d];
				if (cache.find(key) == cache.end()) //即没有*a+*b+*c+*d != target
				{//unordered_map的find的时间复杂度为0(1)
					continue;
				}

				//有*a+*b+*c+*d != target的情况
				const vector<pair<int, int> >vec = cache[key];//vec为 vector<pair<int, int> >类型
				size_t vlen = vec.size();//实际上vec中只存储了一个。即pair<a, b>
				for (size_t k = 0; k != vlen; ++k)
				{
					if (c <= vec[k].second)//有重叠
					{//循环时已经规定的顺序为a<b, c<d;但是并没有限制b,c的关系
						//这里人为地规定a<b<c<d,以为了防止同一个数被两次算进去,且导致无序性问题
						continue;
					}
					result.push_back({ num[vec[k].first], num[vec[k].second], num[c], num[d] });
				}
			}
		}
		sort(result.begin(), result.end());//先排序，以为了下一步去掉重复的使用
		result.erase(unique(result.begin(), result.end()), result.end());
		return result;
	}
};



/*
方法3：先排序，然后左右夹逼，时间复杂度O(n^3)，空间复杂度O(1)
OJ操作结果：Time Limit Exceeded

所以这样的方法不适应。
*/
class Solution {
public:
	vector<vector<int> > fourSum(vector<int> &num, int target) {
		vector<vector<int> > result;
		if (num.size() < 4)
		{
			return result;
		}

		sort(num.begin(), num.end());
		vector<int>::iterator a = num.begin();
		vector<int>::iterator last = num.end();
		for (; a != prev(last, 3); a++)
		{
			vector<int>::iterator b = next(a);
			for (; b != prev(last, 2); b++)
			{
				vector<int>::iterator c = next(b);
				vector<int>::iterator d = prev(last);
				while (c < d)
				{
					if (c>next(b) && *c == *prev(c))
					{
						++c;
						continue;
					}
					if (d < prev(last) && *d == *next(d))
					{
						--d;
						continue;
					}//上面两个if是去掉重复选项

					if (*a + *b + *c + *d > target)
					{
						--d;
					}
					else if (*a + *b + *c + *d < target)
					{
						++c;
					}
					else
					{
						result.push_back({ *a, *b, *c, *d });
						++c;
						--d;
					}
				}//while
			}//for b
		}//for a
		return result;
	}
};