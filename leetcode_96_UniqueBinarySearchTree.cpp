/*
Unique Binary Search Trees

Given n, how many structurally unique BST's (binary search trees) 
that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

*/

/*
考虑当前根节点和左右子树。用左右子树的思想，则比较容易解题
Status: Accepted
Runtime: 0 ms
*/

class Solution {
public:
    int numTrees(int n) {
        vector<int> f(n + 1, 0); //保存从f0~fn共n+1个数，初始值全部设置为0
        f[0] = 1;
        f[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int k = 1; k <= i; ++k) {
                f[i] += f[i - k] * f[k - 1];
            }
        }
        return f[n]; 
        /*用递归会导致太多的重复运算，Time Limit Exceeded，因此不用递归，用迭代
        if (0 == n || 1 ==n) {
            return 1;
        }
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            sum += (numTrees(n - i) * numTrees(i -1));//前面那个是右子树，后面那个是左子树
        }

        return sum;
        */
         
    }
}；