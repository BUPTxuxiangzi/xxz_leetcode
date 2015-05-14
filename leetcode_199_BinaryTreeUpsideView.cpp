/*
Binary Tree Right Side View 
Given a binary tree, imagine yourself standing on the right side of it, 
return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,

	   1            <---
 	/   \
	2     3         <---
	 \     \
 	 5     4       <---

You should return [1, 3, 4]. 
*/

/*思路分析：
要求右边的视图，就是求每一层的最右侧的节点。所以进行层次遍历，找出每层的最后一个节点。
Status: Accepted
Runtime: 12 ms
*/

class Solution
{
public:	
	vector<int> rightSideView(TreeNode *root)
	{
		vector<int> result;
		if (root == nullptr)
		{
			return result;
		}
		queue<TreeNode *> que;
		TreeNode *p;
		que.push(root);
		
		while (!que.empty())
		{
			int curSize = que.size();//每一层的节点数理
			for (int i = 0; i != curSize; ++i)
			{
				if (que.front() != nullptr)
				{
					p = que.front();
					que.pop();
					if (i == curSize - 1)
					{
						result.push_back(p->val);
					}
									
					if (p->left != nullptr)
					{
						que.push(p->left);
					}
					if (p->right != nullptr)
					{
						que.push(p->right);
					}
				}
			}//end of for 
		}//end of while

		return result;
	}
	
};