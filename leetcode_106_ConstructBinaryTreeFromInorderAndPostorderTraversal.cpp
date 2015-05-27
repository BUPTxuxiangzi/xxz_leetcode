/*
Construct Binary Tree from Inorder and Postorder Traversal 

Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree. 
*/

/*思路：
与通过前序和中序遍历构建二叉树思路基本一致
Status: Accepted
Runtime: 56 ms
*/

//根据中序和后序遍历重建二叉树
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        return buildTree(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }

    typedef vector<int>::iterator iter;
    TreeNode *buildTree(iter in_begin, iter in_end, iter post_begin, iter post_end)
    {
        if (in_begin == in_end || in_begin == post_end) {
            return nullptr;
        }

        TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
        if (nullptr == root) {
            exit(-1);
        }
        root->val = *prev(post_end);
        iter root_inPosition = find(in_begin, in_end, *prev(post_end));
        int leftTreeSize = distance(in_begin, root_inPosition);

        //重建左子树
        root->left = buildTree(in_begin, root_inPosition, 
            post_begin, post_begin + leftTreeSize);
        //重建右子树
        root->right = buildTree(next(root_inPosition), 
            in_end, post_begin + leftTreeSize, prev(post_end));

        return root;
    }
};