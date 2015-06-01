/*
Unique Binary Search Trees II 

Given n, generate all structurally unique BST's (binary search trees)
that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

*/


/*
Status: Accepted
Runtime: 24 ms
*/

class Solution {
public: 
    vector<TreeNode*> generateTrees(int n) {
        if (0 == n) {
            return generate(1, 0);
        }

        return generate(1, n);
    } //  end method generateTrees

private:
    vector<TreeNode *> generate(int start, int end) {
        vector<TreeNode *> subTree;
        if (start > end) {
            subTree.push_back(nullptr);
            return subTree;
        }

        for (int k = start; k <= end; ++k) {
            vector<TreeNode *> leftSubs = generate(start, k - 1);
            vector<TreeNode *> rightSubs = generate(k + 1, end);
            //只想到了上面这步，没想到下面的处理方式
            for (auto i : leftSubs) {
                for (auto j : rightSubs) {
                    TreeNode *node = new TreeNode(k);
                    node->left = i;
                    node->right = j;
                    subTree.push_back(node);
                }
            }
        }// end for
        return subTree;
    } // end method generate

};