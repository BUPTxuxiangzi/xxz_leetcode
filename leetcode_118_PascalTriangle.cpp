/*问题描述
Pascal's Triangle
Total Accepted: 40686 Total Submissions: 134375
Given numRows, generate the first numRows of Pascal's triangle.
For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

/*思路
下一行第一个元素和最后一个元素赋值为1，中间的每个元素，等于上一行的左
上角和右上角元素之和。
*/

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
    vector<int> ptLine;
	vector<vector<int> > pac_tri;
	numRows = numRows-1;//数组（向量）的计数从0开始
	if (0 == numRows)
	{
		ptLine.push_back(1);
		pac_tri.push_back(ptLine);
		return pac_tri;
	}

	for (int i = 0; i <= numRows; i++)
	{
		if (0 == i)
		{
			ptLine.push_back(1);
		}
		
		else
		{
			for (int j = 0; j <= i; j++)
			{
				if (0 == j || i == j)
				{
					ptLine.push_back(1);
				}
				else
				{
					ptLine.push_back(pac_tri[i - 1][j - 1] + pac_tri[i - 1][j]);
				}
			}
		}
		pac_tri.push_back(ptLine);
		ptLine.clear();	
	}
	return pac_tri; 
    }
};