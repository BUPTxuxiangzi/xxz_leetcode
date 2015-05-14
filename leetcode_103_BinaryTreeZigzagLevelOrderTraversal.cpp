/*题目描述
Given a binary tree, return the zigzag level order traversal of its nodes' values. 
(ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},

	    3
	   / \
	  9  20
    	/  \
	   15   7

return its zigzag level order traversal as:

	[
	  [3],
	  [20,9],
	  [15,7]
	]

*/

/*解法1：自己写的迭代版
分析： 无
Status: Accepted
Runtime: 6 ms
*/
class Solution
{
public:	
	vector<vector<int> > zigzagLevelOrder(TreeNode *root)
	{
		vector<vector<int> > result;
		
		if (root == nullptr)
		{
			return result;
		}

		bool reverseOrder = false;

		queue<TreeNode *> que;
		TreeNode *p;
		que.push(root);
		while (!que.empty())
		{
			int curSize = que.size();
			vector<int> tmp;
			for (int i = 0; i != curSize; ++i)
			{
				if (que.front() != nullptr)
				{
					p = que.front();
					que.pop();
					tmp.push_back(p->val);
					if (p->left != nullptr)
					{
						que.push(p->left);
					}
					if (p->right != nullptr)
					{
						que.push(p->right);
					}
				}//end of if 
			}//end of for

			if (reverseOrder == 1)
			{
				reverse(tmp.begin(), tmp.end());
			}
			result.push_back(tmp);
			reverseOrder = !reverseOrder;
		}//end of while
		
		return result;
	}	
};


