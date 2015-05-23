/*
Validate Binary Search Tree Total Accepted: 48211 Total Submissions: 230688

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.
*/

/*解法1：
Status: Accepted
Runtime: 16 ms
*/

class Solution {
public:
    bool isValidBST(TreeNode *root)
    {
        if (nullptr == root) { //空树
            return true;
        }

        if (nullptr == root->left && nullptr == root->right) { //只有根节点的树
            return true;
        }

        if (root->left != nullptr) {
            if (root->val <= root->left->val) {
                return false;
            }
            
            TreeNode *left_lastRight = root->left->right; //左子树上的最右边节点
            while (left_lastRight != nullptr) {
                if (root->val <= left_lastRight->val) {
                    return false;
                }
                left_lastRight = left_lastRight->right;
            }
        }
        
        
        //右子树最左节点是否大于根节点
        if (root->right != nullptr) {
            if (root->val >= root->right->val) {
                return false;
            }
            
            TreeNode *right_lastLeft = root->right->left; //右子树上最左边的节点
            while (right_lastLeft != nullptr) {
                if (root->val >= right_lastLeft->val) {
                    return false;
                }
                right_lastLeft = right_lastLeft->left;
            }
        }
        
        return isValidBST(root->left) && isValidBST(root->right);
    }
};