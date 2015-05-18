/*题目描述：
Sum Root to Leaf Numbers 

Given a binary tree containing digits from 0-9 only, each root-to-leaf 
path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3

The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25. 
*/

/*思路分析：、
当前leaf的sum为当前sum*10再加上当前节点的val
从根节点遍历，若遍历到叶子结点，则sum+其路径的所有权值和
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
class Solution
{
public: 
    int sumNumbers(TreeNode *root)
    {   
        dfs(root, 0);
    }//sumNumber
    
private:
    int dfs(TreeNode *root, int sum)
    {
        if (nullptr == root)
        {
            return 0;
        }
        
        if (nullptr == root->left && nullptr == root->right)
        {
            return sum * 10 + root->val;
        }
        
        return dfs(root->left, sum * 10 + (root->val) ) + dfs(root->right, sum * 10 + (root->val) );
    }
};