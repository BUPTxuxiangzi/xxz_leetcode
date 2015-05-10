/*题目描述
Maximum Depth of Binary Tree 
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 */


/*从二叉树深度的定义可知，二叉树的深度应为其左、右子树深度的最大值加1，因为根结点算第1层。
由此，需先分别求得左、右子树的深度，算法中“访问结点”的操作为：求得左、右子树深度的最大值，
最后加 1
Status: Accepted
Runtime: 9 ms
*/
class Solution
{
public:
	int maxDepth(TreeNode *root)
	{
		if (root == nullptr)
		{
			return 0;
		}

		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}//maxDepth
};