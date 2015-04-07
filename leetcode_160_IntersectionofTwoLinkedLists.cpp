/*问题描述：
Intersection of Two Linked Lists Total Accepted: 23369 Total Submissions: 84259

Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3

begin to intersect at node c1.

Notes:

    If the two linked lists have no intersection at all, return null.
    The linked lists must retain their original structure after the function returns.
    You may assume there are no cycles anywhere in the entire linked structure.
    Your code should preferably run in O(n) time and use only O(1) memory.

*/

/**数据结构
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 /*法一：建立一个哈希表
 时间复杂度O(n+m), 空间复杂度O(n+m)
 显然不符合题目要求内存为O(1)的要求
 OJ判定结果： Memory Limit Exceeded
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode* p = headA;
        unordered_map<ListNode*, bool> imap;//共用一个哈希
        while(p!=NULL) //先将A的全部置为false
        {
            imap[p] = false;
            p = p->next;
        }
        ListNode* q = headB;
        while(q!=NULL)//再将B的全部置为true
        {
            imap[q] = true;
            q = q->next;
        }

        //最后从A开始找，找到true则返回节点，否则找到最后
        p = headA;
        while(p!=NULL)
        {
            if(imap[p] == true)
                return p;
            p=p->next;
        }
        return NULL;
    }
};



/*法二：双指针法
 双指针法 ，指针pa、pb分别指向链表A和B的首节点。
遍历链表A，记录其长度lengthA，遍历链表B，记录其长度lengthB。
因为两个链表的长度可能不相同，比如题目所给的case，lengthA=5，
lengthB=6，则作差得到 lengthB- lengthA=1，将指针pb从链表B的首
节点开始走1步，即指向了第二个节点，pa指向链表A首节点，然后
它们同时走，每次都走一步，当它们相等时，就是交集的节点。

时间复杂度O(lengthA+lengthB)，空间复杂度O(1)。双指针法的代码如下： 
OJ判定结果：Accepted
Runtime: 74 ms
*/
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode* pA = headA;
        ListNode* pB = headB;
        int lenA = 0;
        int lenB = 0;
        while(NULL!=pA)
        {
            ++lenA;
            pA = pA->next;
        }
        while(NULL!=pB)
        {
            ++lenB;
            pB = pB->next;
        }

        pA = headA;
        pB = headB;
        if(lenA >= lenB)
        {
            int gap = lenA - lenB;
            for(int i=0; i!=gap; ++i)
            {
                pA = pA->next;
            }
            for(int j=0; j!=lenB; ++j)
            {
                if(pA==pB)//要先判断再前进，以防止第一个就相交
				{
					return pA;
				}
                pA = pA->next;
                pB = pB->next;

            }
            return NULL;
        }
        else
        {
            int gap = lenB - lenA;
            for(int i=0; i!=gap; ++i)
            {
                pB = pB->next;
            }
            for(int j=0; j!=lenA; ++j)
            {
                if(pB==pA)
				{
					return pB;
				}
                pB = pB->next;
                pA = pA->next;

            }
            return NULL;
        }

    }
};


/*法三：双指针法，对法二在c++实现上的一个改进
OJ判定结果： Accepted
Runtime: 80 ms
*/

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode* pA = headA;
        ListNode* pB = headB;
        int lenA = 0;
        int lenB = 0;
        while(NULL!=pA)
        {
            ++lenA;
            pA = pA->next;
        }
        while(NULL!=pB)
        {
            ++lenB;
            pB = pB->next;
        }

        pA = headA;
        pB = headB;
        int gap = 0;
        if(lenA >= lenB)
        {
            gap = lenA - lenB;
            for(int i=0; i!=gap; ++i)
            {
                pA = pA->next;
            }
        }
        else
        {
            gap = lenB - lenA;
            for(int i=0; i!=gap; ++i)
            {
                pB = pB->next;
            }
        }

        while(pA!=pB) //有交点，则在交点时终止循环
        {
            //无交点，则在全部等于NULL时才退出循环
            pA = pA->next;
            pB = pB->next;
        }
        return pA;

    }
};