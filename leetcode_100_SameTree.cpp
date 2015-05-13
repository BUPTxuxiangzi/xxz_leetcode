/*题目描述：
Same Tree 

Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and
 the nodes have the same value. 
*/

/*解法1 ：自己解法，递归
Status: Accepted
Runtime: 6 ms
 */
class Solution
{
public:
	bool isSameTree(TreeNode *p, TreeNode *q)
	{
		if (nullptr == p && nullptr == q)
		{
			return true;
		}
		else if (nullptr == p && nullptr != q)
		{
			return false;
		}
		else if (nullptr != p && nullptr == q)
		{
			return false;
		}

		if (p->val != q->val)
		{
			return false;
		}

		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
};


/*解法2：leetcode题解所给解法，非递归，用栈
Status: Accepted
Runtime: 3 ms
*/

class Solution
{
public:
	bool isSameTree(TreeNode *p, TreeNode *q)
	{
		stack<TreeNode *> sta;


		sta.push(p);
		sta.push(q);

		while (!sta.empty())
		{
			p = sta.top(); 
			sta.pop();
			q = sta.top();
			sta.pop();

			if (p == NULL && q == NULL)
			{
				continue;
			}
			if (p==NULL || q==NULL)
			{
				return false;
			}

			if (p->val != q->val)
			{
				return false;
			}

			sta.push(p->left);
			sta.push(q->left);

			sta.push(p->right);
			sta.push(q->right);
		}

		return true;
	}
};