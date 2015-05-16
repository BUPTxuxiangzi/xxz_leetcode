/*问题描述：
Populating Next Right Pointers in Each Node 
Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

    You may only use constant extra space.
    You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).

For example,
Given the following perfect binary tree,

         1
       /  \
      2    3
     / \  / \
    4  5  6  7

After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
*/

/*解法1：自己的
充分利用it is a perfect binary tree这一给定的条件
时间复杂度O(n)，空间复杂度O(1)
Status: Accepted
Runtime: 24 ms
*/

class Solution
{
public:
    void connect(TreeLinkNode *root)
    {
        if (nullptr == root)
        {
            return;
        }
        if (nullptr == root->left)
        {
            root->next = nullptr;
        }

        int level = 0;
        TreeLinkNode *p;

        root->next = nullptr;
        while (root->left != nullptr)
        {
            p = root;
            int curSize = (int)pow(2, level);
            for (int i = 0; i != curSize; ++i)
            {           
                p->left->next = p->right;
                if (p->next != nullptr)
                {
                    p->right->next = p->next->left;
                    p = p->next;
                }
                else
                {
                    p->right->next = nullptr;
                }               
            }
            
            ++level;
            root = root->left;
        }    
    }   
};

/*解法2：题解上的解法
时间复杂度O(n)，空间复杂度O(logn)
Status: Accepted
Runtime: 53 ms
 */

class Solution
{
public:
    void connect(TreeLinkNode *root)
    {
        connect(root, nullptr);
    }

private:
    void connect(TreeLinkNode *root, TreeLinkNode *sibling)
    {
        if (nullptr == root)
        {
            return;
        }
        else
        {
            root->next = sibling;
        }

        connect(root->left, root->right);
        if (sibling != nullptr)
        {
            connect(root->right, sibling->left);
        }
        else
        {
            connect(root->right, nullptr);
        }
    }
};