/*题目描述：
Path Sum Total Accepted: 52358 Total Submissions: 175369

Given a binary tree and a sum, determine if the tree has a root-to-leaf path 
such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1

return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
*/

/*思路分析：
sum是leaf节点的sum，但是这样求解是逆着求解，比较困难，因此，不妨倒过来。
当前root节点向下的path的sum等于当前节点+左子树的sum， 当前节点+右子树的sum，
比较两者，只要有一个等于给定的sum，就是true。

Status: Accepted
Runtime: 16 ms
*/

class Solution
{
public:
	bool hasPathSum(TreeNode *root, int sum)
	{
		path(root);
		for (int i = 0; i < result.size(); ++i)
		{
			if (result[i] == sum)
			{
				return true;
			}
		}
		return false;
	}
private:
	vector<int> result;
	int tmp = 0;
	int path(TreeNode *root)
	{
		
		if (root != NULL)
		{
			tmp += root->val;
			path(root->left);
			if (NULL == root->left && NULL == root->right)
			{
				result.push_back(tmp);
			}
			tmp -= root->val;

			tmp += root->val;
			path(root->right);
			if (NULL == root->left && NULL == root->right)
			{
				result.push_back(tmp);
			}
			tmp -= root->val;						
		}
		return tmp;
	}
};


/*解法2：答案提供解法

题目只要求返回true 或者false，因此不需要记录路径。
由于只需要求出一个结果，因此，当左、右任意一棵子树求到了满意结果，都可以及时return。
由于题目没有说节点的数据一定是正整数，必须要走到叶子节点才能判断，因此中途没法剪枝，
只能进行朴素深搜。

Status: Accepted
Runtime: 14 ms

 */

class Solution
{
public:
	bool hasPathSum(TreeNode *root, int sum)
	{
		if (nullptr == root)
		{
			return false;
		}

		if (nullptr == root->left && nullptr == root->right)
		{
			return (sum == root->val);
		}

		return (hasPathSum(root->left, sum - root->val)
			|| hasPathSum(root->right, sum - root->val));
	}
};
