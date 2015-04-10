/*问题描述
Linked List Cycle Total Accepted: 54367 Total Submissions: 149546

Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space? 

 */

/**数据结构
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*解法1：
设置两个指针，一个快指针（每次前进两格），一个慢指针（每次前进一格），
且快指针在一开始就比慢指针考前一格，以防止出现链表还没有遍历一遍就出相遇。
若是fast和slow能相遇，则证明

Status: Accepted
Runtime: 18 ms
 */
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if( head==NULL || head->next==NULL)
            return false;

        ListNode *fast, *slow;
        fast = head->next;//注意，一定要一开始fast就比slow前一格，否则可能半途就相遇
        slow = head;
        while(fast!=slow )
        {
            if( fast==NULL || fast->next==NULL)//f为了防止出现fast->next和fast->next->next是野指针的情况
            {
                break;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        if( fast==NULL || fast->next==NULL)
            return false;
        else//即因为fast == slow而终止循环的情况，证明有环
            return true;
    }
};

/*
解法2：对解法1在代码上的优化

Status: Accepted
Runtime: 18 ms
 */
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *fast, *slow;
        fast = head;
        slow = head;
        while(slow!=NULL && fast!=NULL && fast->next!=NULL)//第一步时候就相当于判断了head==NULL和head->next==NULL的情况
        {
            slow = slow->next;
            fast = fast->next->next;
            if(fast==slow)
            {
                return true;
            }
        }//若循环是因为判断条件而终止，则证明其中有环
        return false;
    }
};