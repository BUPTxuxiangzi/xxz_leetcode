/*问题描述：
Linked List Cycle II

Given a linked list, return the node where the cycle begins. 
If there is no cycle, return null.

Follow up:
Can you solve it without using extra space? 

Status: Accepted
Runtime: 17 ms
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

 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *fast, *slow;
        fast = head;
        slow = head;
        while(slow!=NULL && fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast)
            {
                break;
            }
        }
        if(slow==NULL || fast==NULL || fast->next==NULL)//无环
        {
            return NULL;
        }

        //否则有环
        ListNode* p = head;
        ListNode* q = fast;
        while(p!=q)
        {
            p = p->next;
            q = q->next;
        }
        return p;
    }
};
