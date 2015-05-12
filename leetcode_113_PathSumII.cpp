/*题目描述：
Path Sum II 

Given a binary tree and a sum, find all root-to-leaf paths 
where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1


return
[
   [5,4,11,2],
   [5,8,4,5]
]
*/

/*
Status: Accepted
Runtime: 49 ms
 */


class Solution
{
public:
	vector<vector<int> > pathSum(TreeNode* root, int sum) 
	{
		path(root);

		vector<vector<int> > paths;
		int len = result.size()/2;
		for (int i = 0; i < len; ++i)
		{
			result[i] = result[2 * i];
		}
		result.erase(result.begin() + len, result.end());

		for (int j = 0; j < len; ++j)
		{
			int comp = 0;
			for (auto t : result[j])
			{
				comp += t;
			}

			if (sum == comp)
			{
				paths.push_back(result[j]);
			}
		}

		return paths;
	}

private:
	vector<vector <int>> result;
	vector<int> tmp;
	vector<int> path(TreeNode *root)
	{
		if (nullptr == root)
		{
			return tmp;
		}

//---------------------下面遍历左子树--------------------------
		tmp.push_back(root->val);
		path(root->left);
		if (nullptr == root->left && nullptr == root->right)
		{
			result.push_back(tmp);
		}
		tmp.pop_back();

//-----------------------------下面遍历右子树------------------
		tmp.push_back(root->val);
		path(root->right);
		if (nullptr == root->left && nullptr == root->right)
		{
			result.push_back(tmp);
		}
		tmp.pop_back();
//-------------------------------------------------------------
		return tmp;
	}
};

/*解法2：leetcode题解上的
跟112题相比，本题是求路径本身。且要求出所有结果，左子树求到了满意结果，不能return，
要接着求右子树。
Status: Accepted
Runtime: 18 ms

 */
class Solution
{
public:
	vector<vector<int> > pathSum(TreeNode *root, int sum)
	{
		vector<vector<int> > result;
		vector<int> cur;

		paths(root, sum, cur, result);
		return result;
	}

private:
	void paths(TreeNode *root, int gap, vector<int> &cur, vector<vector<int> > &result)
	{
		if (nullptr == root)
		{
			return;
		}

		cur.push_back(root->val);

		if (root->left == nullptr && root->right == nullptr)
		{
			if (gap == root->val)
			{
				result.push_back(cur);
			}
		}

		paths(root->left, gap - root->val, cur, result);
		paths(root->right, gap - root->val, cur, result);

		cur.pop_back();
	}
};