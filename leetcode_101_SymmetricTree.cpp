/*题目描述：
Symmetric Tree 

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3

But the following is not:

    1
   / \
  2   2
   \   \
   3    3

Note:
Bonus points if you could solve it both recursively and iteratively. 
*/

/*思路分析：
Status: Accepted
Runtime: 10 ms
*/

class Solution
{
public:
	bool isSym(TreeNode *p, TreeNode *q)
	{
		if (p == nullptr && q == nullptr)
		{
			return true;
		}
		if (p == nullptr || q == nullptr)
		{
			return false;
		}		

		return (p->val == q->val) && isSym(p->left, q->right) && isSym(p->right, q->left);

	}
	
	bool isSymmetric(TreeNode *root)
	{
		if (root == nullptr)
		{
			return true;
		}
		else
		{
			return isSym(root->left, root->right);
		}		
	}
};

/*解法2：非递归版本
Status: Accepted
Runtime: 7 ms

 */
class Solution
{
public:	
	
	bool isSymmetric(TreeNode *root)
	{
		if (root == nullptr)
		{
			return true;
		}
		
		TreeNode *p;
		TreeNode *q;
		stack<TreeNode *> sta;

		sta.push(root->left);
		sta.push(root->right);
		while (!sta.empty())
		{
			p = sta.top();
			sta.pop();
			q = sta.top();
			sta.pop();

			if (p == nullptr && q == nullptr)
			{
				continue;
			}
			if (p == nullptr || q == nullptr)
			{
				return false;
			}

			if (p->val != q->val)
			{
				return false;
			}

			sta.push(p->left);
			sta.push(q->right);

			sta.push(p->right);
			sta.push(q->left);
		}

		return true;
	}
};