/*题目描述
Binary Tree Maximum Path Sum 

Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3

Return 6. 
*/

/*解法1：从题解上抄袭而来
这题很难，路径可以从任意节点开始，到任意节点结束。可以利用“最大连
续子序列和”问题的思路，见第§13.2节。如果说Array 只有一个方向的话，
那么Binary Tree 其实只是左、右两个方向而已，我们需要比较两个方向上的值。
不过，Array 可以从头到尾遍历，那么Binary Tree 怎么办呢，我们可以
采用Binary Tree 最常用的dfs 来进行遍历。先算出左右子树的结果L 和R，
如果L 大于0，那么对后续结果是有利的，我们加上L，如果R 大于0，
对后续结果也是有利的，继续加上R.

注意，最后return 的时候，只返回一个方向上的值，为什么？这是因为在递归中，
只能向父节返回，不可能存在L->root->R 的路径，只可能是L->root 或R->root。


Status: Accepted
Runtime: 36 ms
 */

class Solution {
public:
    int maxPathSum(TreeNode *root) {
        max_sum = INT_MIN;
        dfs(root);
        return max_sum;
    }

private:
    int max_sum;
    int dfs(const TreeNode *root) {
        if (nullptr == root) {
            return 0;
        }

        int leftDfs = dfs(root->left);
        int rightDfs = dfs(root->right);

        int sum = root->val;
        if (leftDfs > 0) {
            sum += leftDfs;
        }
        if (rightDfs > 0) {
            sum += rightDfs;
        }

        max_sum = max(max_sum, sum);

        return max(rightDfs, leftDfs) > 0 ? max(rightDfs, leftDfs) + root->val : root->val;
    }

};