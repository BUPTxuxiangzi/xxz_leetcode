/*题目描述
 *Insertion Sort List 
 *Sort a linked list using insertion sort.
 */

/*数据结构
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

/*解法一：直接插入排序
OJ判决结果：Accepted
Runtime:98ms
*/
class Solution {
public:
	ListNode *insertionSortList(ListNode *head) 
	{
		if (!head)
		{
			return head;
		}
		ListNode* p = head;
		ListNode* newList = (ListNode *)malloc(sizeof(ListNode));//新建一个链表
		newList->next = NULL;
		ListNode* q1 = newList;

		//先处理第一个节点
		ListNode *s = (ListNode *)malloc(sizeof(ListNode));
		s->val = p->val;
		s->next = q1->next;
		q1->next = s;
		p = p->next;

		ListNode* q2;
		while (p)//第一个链表还没有到最后
		{
			q1 = newList;
			q2 = q1->next;

			while (q2)
			{
				if (q2->val > p->val)//表中有比待插入大的
				{
					ListNode *s = (ListNode *)malloc(sizeof(ListNode));
					s->val = p->val;
					s->next = q1->next;
					q1->next = s;
					break;
				}
				q2 = q2->next;
				q1 = q1->next;
			}//while

			if (!q1->next)//已经是最后一个
			{
				ListNode *s = (ListNode *)malloc(sizeof(ListNode));
				s->val = p->val;
				s->next = q1->next;
				q1->next = s;
			}

			p = p->next;
		}//while
		newList = newList->next;
		return newList;
	}
};



/*法一的改进：将频繁使用的插入操作改为函数
 *OJ判决结果：Accepted
 *Runtime:
 */
class Solution {
public:
	void insertNext(ListNode* A, ListNode* B)
	{
		ListNode *s = (ListNode *)malloc(sizeof(ListNode));
		s->val = B->val;
		s->next = A->next;
		A->next = s;
	}
	ListNode *insertionSortList(ListNode *head) 
	{
		if (!head)//!!!一定不要忘了处理空链表
		{
			return head;
		}
		ListNode* p = head;
		ListNode* newList = (ListNode *)malloc(sizeof(ListNode));//新建一个链表
		newList->next = NULL;
		ListNode* q1 = newList;

		//先处理第一个节点
		insertNext(q1, p);
		p = p->next;

		ListNode* q2;
		while (p)//第一个链表还没有到最后
		{
			q1 = newList;
			q2 = q1->next;

			while (q2)
			{
				if (q2->val > p->val)//表中有比待插入大的
				{
					insertNext(q1, p);
					break;
				}
				q2 = q2->next;
				q1 = q1->next;
			}//while

			if (!q1->next)//已经是最后一个
			{
				insertNext(q1, p);
			}

			p = p->next;
		}//while
		newList = newList->next;
		return newList;
	}
};

/*解法3：继续改进，将函数改为inline
 *Runtime:92ms
 *代码省略，基本一致
 */