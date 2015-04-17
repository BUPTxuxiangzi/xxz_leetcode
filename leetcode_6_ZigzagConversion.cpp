/*
ZigZag Conversion

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
(you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);

convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR". 
 */

/*解法1：找规律
Status: Accepted
Runtime: 37 ms
 */
class Solution {
public:
	string convert(string s, int nRows) 
	{
		if (nRows < 2)//无需转换
		{
			return s;
		}

		vector<string> zigzag(nRows);
		vector<string>::iterator iter = zigzag.begin();
		//int i = 0;
		int k = 0;
		int len = s.size();
		while (k < len)
		{
			while (iter < zigzag.end() && k < len) 
			{ 
				(*iter).push_back(s[k++]); 
				iter++;
			}
			iter--;
			iter--;

			while (iter > zigzag.begin() && k < len) //第一个不能带“=”，因为向前越界，无法返回。
			{ 
				(*iter).push_back(s[k++]); 
				iter--;
			}

			if (k < len)//处理zigzag.begin()
			{
				(*iter).push_back(s[k++]);
			}
			iter++;
		}

		string str;
		for (int j = 0; j < zigzag.size(); ++j)
		{
			str += zigzag[j];
		}
		return str;
	}
};