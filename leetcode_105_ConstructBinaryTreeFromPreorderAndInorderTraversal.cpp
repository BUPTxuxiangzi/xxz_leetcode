/*
Construct Binary Tree from Preorder and Inorder Traversal

Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree. 
*/

/*思路分析：
题目要求根据前序遍历和中序遍历，来重建二叉树。
根据前序遍历的定义可知：前序遍历的第一个序列是树的根节点。
根据中序遍历的定义可知：根节点前面的序列全部是左子树上的，后面的序列是右子树上的。

由此，可以重建二叉树：前序遍历序列的第一个值，是root->val;
搜索中序遍历的序列，找到*pre_begin，在这个位置之前的所有序列是root->left, 在这个
位置之后的是root->right

Status: Accepted
Runtime: 56 ms
*/

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        return buildTree(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    } // end of mathod 

    typedef vector<int>::iterator iter;
    TreeNode* buildTree(iter pre_begin, iter pre_end, iter in_begin, iter in_end) 
    {                                   //注意：end等同于end(),是不包括在序列中的
        if (pre_begin == pre_end) { //这个的功能还包括给叶子的左右孩子赋值为nullptr
            return nullptr;
        }
        if (in_begin == in_end) {
            return nullptr;
        }

        TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
        if (root == nullptr) { // 分配内存失败
            exit(-1);
        }
        root->val = *pre_begin; //根节点的值

        iter root_inPosition = find(in_begin, in_end, *pre_begin); //根节点在中序遍历序列中的位置
        int leftTreeSize = distance(in_begin, root_inPosition); //左子树的大小

        root->left = buildTree(next(pre_begin), next(pre_begin + leftTreeSize) ,
            in_begin, root_inPosition);
        root->right = buildTree(next(pre_begin + leftTreeSize), pre_end,
            next(root_inPosition), in_end);
        
        return root;
    } // end of method

};// end class Solution