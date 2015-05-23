/*
Recover Binary Search Tree Total Accepted: 31839 Total Submissions: 129923

Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.
Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution? 
*/

/*
Status: Accepted
Runtime: 48 ms
*/

class Solution {
public:
    void recoverTree(TreeNode *root) 
    {
        inOrderTraverse(root);
        TreeNode *pos1 = nullptr; 
        TreeNode *pos2 = nullptr;
        int len = ivec.size();

        //从前往后找第一个逆序的位置
        for (int i = 0; i != len-1; ++i) {
            if (ivec[i]->val >= ivec[i + 1]->val) {
                pos1 = ivec[i];
                break;
            }
        }

        //从后往前找第二个逆序的位置
        for (int i = len - 1; i != 0; --i) {
            if (ivec[i]->val <= ivec[i - 1]->val) {
                pos2 = ivec[i];
                break;
            }
        }

        int tmp;
        tmp = pos1->val;
        pos1->val = pos2->val;
        pos2->val = tmp;

    }

    void inOrderTraverse(TreeNode *root)
    {
        if (root == nullptr) {
            return;
        }

        inOrderTraverse(root->left);
        ivec.push_back(root);
        inOrderTraverse(root->right);
    }

private:
    vector<TreeNode *> ivec;
};