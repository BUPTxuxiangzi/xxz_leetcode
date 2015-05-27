/*
Populating Next Right Pointers in Each Node II T

Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

    You may only use constant extra space.

For example,
Given the following binary tree,

         1
       /  \
      2    3
     / \    \
    4   5    7

After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL

*/

/*解题思路：(根据题解上答案得来)
要处理一个节点，可能需要最右边的兄弟节点，首先想到用广搜。但广搜不是常数空间的，本
题要求常数空间。

那就利用next节点，一层一层的来遍历好了。首先是root，我们把它的left和right连起来，
然后root切换到下一层

然后遍历下一层的每个节点（因为next连了的）再分别把他们的left，right什么的连起来

用两个变量就ok了
一个prevNode记录当前层前一节点是啥（用来连接的
一个nextLevelStart记录下一层的开始（用户切换到下一层

*/

class Solution {
public:
    void connect(TreeNode *root)
    {
        TreeNode *nextLevelStart = nullptr;
        TreeNode *prevNode = nullptr;
        
        while (root != nullptr) { //  深度上的循环（纵向）
            nextLevelStart = nullptr;
            prevNode = nullptr;
            
            for (; root != nullptr; root = root->next) { //每一层内部的循环
                
                if (nullptr == nextLevelStart) {
                    nextLevelStart = root->left ? root->left : root->right;
                }

                if (root->left != nullptr) {
                    if (prevNode != nullptr) {
                        prevNode->next = root->left;
                    }
                    prevNode = root->left;
                }

                if (root->right != nullptr) {
                    if (prevNode != nullptr) {
                        prevNode->next = root->right;
                    }
                    prevNode = root->right;
                }

            }// end for()
            
            root = nextLevelStart; //turn to next level

        } // end while()
    }// end method connect()

};// end class Solution