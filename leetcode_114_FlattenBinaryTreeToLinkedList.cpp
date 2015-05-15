/*题目描述
Flatten Binary Tree to Linked List

Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6

The flattened tree should look like:

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6

*/

/*解法1:题解上面抄来的
思想是将当前的节点的左孩子，移到当前节点的右孩子之前。
这里每次需要找到左孩子最右边的节点，连接到当前右孩子。然
后依次往右处理自己的右孩子，直到右孩子为空。
Status: Accepted
Runtime: 11 ms
 */
class Solution
{
public:
    void flatten(TreeNode *root)
    {
        if (nullptr == root)
        {
            return ;
        }

        stack<TreeNode *> sta;
        TreeNode *p;
        sta.push(root);

        while (!sta.empty())
        {
            p = sta.top();//top()中元素不可能为nullptr，所以不必设置if来进行防御
            sta.pop();

            if (p->right != nullptr)
            {
                sta.push(p->right);
            }
            
            if (p->left != nullptr)
            {
                sta.push(p->left);
            }
            
            if (!sta.empty())
            {
                p->right = sta.top();//指向后不能pop，下一轮循环还要使用
            }            
            p->left = nullptr;
        }
    }
};

/*解法2：抄自网上
可以看出变换后的数实际上是按照先序遍历的顺序排列的，因此可以利用中序递归遍历，
记录先序遍历的前驱节点，依次调整每个孩子的左右子树，这里需要注意的是遍历过程
中需要先将当前节点的右子树记录下来，再调整当前节点的左右子树，然后递归调整左右子树。
Status: Accepted
Runtime: 9 ms
 */

class Solution
{
public:
    TreeNode *pre = nullptr;
    void flatten(TreeNode *root)
    {
        if (nullptr == root)
        {
            return;
        }

        TreeNode *lastright = root->right;
        if (pre != nullptr)
        {
            pre->left = nullptr;
            pre->right = root;
        }

        pre = root;
        flatten(root->left);
        flatten(lastright);
    }
};


/*解法3：抄自网上
前序遍历，再加上一个队尾指针
Status: Accepted
Runtime: 8 ms
*/

class Solution
{
public:
    TreeNode *tail;
    void preOrderTraverse(TreeNode *root)
    {
        if (root != nullptr)
        {
            TreeNode *leftchild = root->left;
            TreeNode *rightchild = root->right;
            if (nullptr == tail)
            {
                tail = root;
            }
            else
            {
                if (tail->right != root)
                {
                    tail->right = root;
                }
                tail->left = nullptr;
                tail = root;
            }
            preOrderTraverse(leftchild);
            preOrderTraverse(rightchild);
        }
    }

    void flatten(TreeNode *root)
    {
        tail = nullptr;
        preOrderTraverse(root);
    }
};