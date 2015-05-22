
/*题目描述：
Balanced Binary Tree 

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as 
a binary tree in which the depth of the two subtrees of every 
node never differ by more than 1.
*/

/*解法1：自己想的
关于一棵树是否平衡，题目中只给了一个限定条件，即左右子树高度
之差不超过1，所以，不必关心其他，只关心高度即可。用暴力求解法
Status: Accepted
Runtime: 16 ms

*/
class Solution {
public:
    bool isBalanced(TreeNode *root)
    {
        if (nullptr == root) {
            return true;
        }

        int gap = abs(height(root->left) - height(root->right));
        if (gap < 2) {
            return (isBalanced(root->left) && isBalanced(root->right));
        
            
        } else { //gap >= 2
            return false;
        }

        return true;
    }// end of isBalanced() method

private:
    int height(TreeNode *root)
    {
        if (nullptr == root) {
            return 0;
        }

        return max(height(root->left), height(root->right)) + 1;
    }
};

/*解法2:剪枝（题解上）
Status: Accepted
Runtime: 12 ms
快了25%
 */
class Solution {
public:
    bool isBalanced(TreeNode *root)
    {
        return balancedHeight(root) >= 0; //0或1时为真
    }

private:
    int balancedHeight(TreeNode *root)
    {
        if (nullptr == root)
        {
            return 0;
        }

        int leftHeight = balancedHeight(root->left);
        int rightHeight = balancedHeight(root->right);
        //int gap = abs(leftHeight - rightHeight);
        
        //leftHeight, rightHeight小于0，是递归定义的
        if (leftHeight < 0 || rightHeight < 0 || gap > 1) {  //剪枝策略
            return -1;
        }

        return max(leftHeight, rightHeight)) + 1;
    }

};