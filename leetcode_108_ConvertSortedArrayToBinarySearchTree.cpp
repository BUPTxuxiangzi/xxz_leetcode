/*题目描述：
Convert Sorted Array to Binary Search Tree 

Given an array where elements are sorted in ascending order, 
convert it to a height balanced BST.
*/


/*思路分析：
题目说明数组的顺序是升序的，又要求BST是平衡的，所以左右子树的节点数目相差应不超过1，
所以，去中间的点作为root，中间点之前的作为left，中间点之后的作为right。

这样，递归定义出BST

Status: Accepted
Runtime: 28 ms
*/

class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int>& nums)
    {
        int len = nums.size();
        if (0 == len) {
            return nullptr;
        }

        TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
        int rootPosition = len / 2;
        root->val = nums[rootPosition];

        vector<int> leftNums(nums.begin(), nums.begin() + rootPosition);
        vector<int> rightNums(nums.begin() + rootPosition + 1, nums.end());
        nums.clear();
        root->left = sortedArrayToBST(leftNums);
        root->right = sortedArrayToBST(rightNums);

        return root;
    }
};


/*解法2，代码上的优化
Status: Accepted
Runtime: 20 ms

虽然时间上优化的不多，但是空间上的优化是很可观的
*/

class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int>& nums)
    {
        return sortedArrayToBST(nums.begin(), nums.end());
    }

    typedef vector<int>::iterator iter;
    TreeNode *sortedArrayToBST(iter beg, iter end)
    {
        const int len = distance(beg, end);

        if (len <= 0) {
            return nullptr;
        }
        
        TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
        iter mid = beg + (end - beg) / 2;
        root->val = *mid;
        root->left = sortedArrayToBST(beg, mid);
        root->right = sortedArrayToBST(mid + 1, end);

        return root;
    }
};