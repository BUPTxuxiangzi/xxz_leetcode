/*题目描述：
Minimum Depth of Binary Tree 

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path 
from the root node down to the nearest leaf(是leaf，不是left，注意！) node.
 */

/*思路分析
从二叉树深度的定义可知，二叉树的深度应为其左、右子树深度的最大值加1，因为根结点算
第1层。由此，需先分别求得左、右子树的深度，算法中“访问结点”的操作为：求得左、右子树
深度的最小值，最后加 1注意，如果左子树为空，那么当前节点的深度不能直接判定为1，必须
是右子树的深度加1。同理，右子树为空的时候，当前节点的深度不能是1，而必须是左子树的
深度加1.

Status: Accepted
Runtime: 19 ms
*/

class Solution
{
public:
	int minDepth(TreeNode *root)
	{
		if (nullptr == root)
		{
			return 0;
		}

		if (nullptr == root->left)
		{
			return minDepth(root->right) + 1;
		}

		if (nullptr == root->right)
		{
			return minDepth(root->left) + 1;
		}

		return min(minDepth(root->left), minDepth(root->right)) + 1;
	}//maxDepth
};