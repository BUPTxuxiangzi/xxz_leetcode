/*题目描述
Binary Tree Postorder Traversal Total Accepted: 59188 Total Submissions: 183674

Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3

return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?
*/

/*解题思路：递归
Status: Accepted
Runtime: 0 ms
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        postTraverse(root);
        return result;
    }
    
private:
    vector<int> result;
    void postTraverse(TreeNode *root){
       
        if (nullptr == root)
        {
            return;
        }
        
        //为了方便记忆，无论是递归方式还是非递归的方式，都加上判断语句
        if (root->left != nullptr) 
        {
            postTraverse(root->left);
        }

        if (root->right != nullptr)
        {
            postTraverse(root->right);
        }
        
        result.push_back(root->val); 
    }
};