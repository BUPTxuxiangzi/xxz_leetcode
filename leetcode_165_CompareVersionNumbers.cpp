/*问题描述
Compare Version Numbers 

Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth 
second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37
 */

/*解法1：每次只比较'.'之前的部分，若不同，返回结果，结束。若相同，继续比较后面的部分。
Status: Accepted
Runtime: 6 ms
 */
class Solution
{
	int compareVersion(string version1, string version2)
	{
		if (version1.empty())
		{
			version1.push_back('0');//防止出现1.6.5与1.6这样的比较，比较到第二个小点后，5无法与一个不存在的数比较的情况
			//所以对1.6这样的数进行扩充，扩充为1.6.0
		}
		if (version2.empty())
		{
			version2.push_back('0');
		}

		int v1len = 0, v2len = 0;
		int i = 0;
		while (i != version1.size() && version1[i++] != '.') //i!=version1.size()防止出现没有小数点的情况,
		{													//且一定要放在前面，因为后面的条件执行后i会+1
			++v1len;
		}//求version1的‘.’之前的长度

		int j = 0;
		while (j != version2.size() && version2[j++] != '.')
		{
			++v2len;
		}//求version2的‘.’之前的长度

		string tmp1;
		string tmp2;
		int k = 0;
		for (k = 0; k != v1len; ++k)
		{
			tmp1.push_back(version1[k]);
		}
		for (k = 0; k != v2len; ++k)
		{
			tmp2.push_back(version2[k]);
		}

		int t1 = stoi(tmp1);
		int t2 = stoi(tmp2);

		if (t1 > t2)
		{
			return 1;
		}
		else if (t1 < t2)
		{
			return -1;
		}
		else
		{
			//小数点之前的部分相同，若还有小数点后部分，则比较之,递归的方式
			if (v1len < version1.size() || v2len < version2.size())
			{
				string str1;
				for (int h = v1len + 1; h < version1.size(); ++h)
				{
					str1.push_back(version1[h]);
				}

				string str2;
				for (int h = v2len + 1; h < version2.size(); ++h)
				{
					str2.push_back(version2[h]);
				}

				int re = compareVersion(str1, str2);//一定要注意，comVer返回值是int型，不是string型
				if (re > 0)
				{
					return 1;
				}
				else if (re < 0)
				{
					return -1;
				}
				else
				{
					return 0;
				}
			}
			else //小数点之后都没有数字
			{
				return 0;
			}
		}
	}
};


/*解法2：依然是根据小数点进行分组，不同的是先将所有组的string转换为int
存储在vector中。最后集中进行比较

Status: Accepted
Runtime: 4 ms
 */
class Solution
{
public:
	int compareVersion(string version1, string version2)
	{
		vector<int> v1 = getInt(version1);
		vector<int> v2 = getInt(version2);
		int i = 0;
		while (v1.size() != i && v2.size() != i)
		{
			if (v1[i] > v2[i])
			{
				return 1;
			}
			else if (v1[i] < v2[i])
			{
				return -1;
			}
			else
			{
				++i;
			}
		}

		if (v1.size() != i && v1[i]!=0)//v1前面部分和v2相同，且v2没有后面部分，而v1有且不是0
		{
			return 1;
		}
		else if (v2.size() != i && v2[i]!=0)//v2前面部分和v1相同，且v1没有后面部分，而v2有且不是0
		{
			return -1;
		}
		else
		{
			return 0;
		}
	}

private:
	vector<int> getInt(string version)
	{
		vector<int> result;
		int i = 0;
		while (version.size() > i) //必须用“>”，不能用“!=” 以防止string 下标越界(i==ver.size()+1)的情况出现
		{
			string tmp;
			while (version.size() != i && '.' != version[i])//必须有两个条件约束，且第一个就应该放在第一个位置，
			{												//防止出现纯数字无法比较的情况，即类似11这样没有小数点
				tmp.push_back(version[i]);
				i++;
			}
			if (!tmp.empty())
			{
				int t = stoi(tmp);
				result.push_back(t);
				++i;
			}
		}//全部转换为数字并存储
		return result;
	}//getInt

};//class