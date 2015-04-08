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

/*解法一：新建一个链表，直接插入排序
时间复杂度O(n^2)，空间复杂度O(n)
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

/*解法一继续改进，将函数改为inline
 *Runtime:92ms
 *代码省略，基本一致
 */

/*解法二：就地插入排序，不新建
*时间复杂度O(n^2)，空间复杂度O(1)
*OJ判决结果：Accepted
*Runtime: 94 ms
*/
class Solution {
public:
	ListNode *insertionSortList(ListNode *head) {
		if (!head)
		{
			return head;
		}
		ListNode* newHead = (ListNode *)malloc(sizeof(ListNode));
		newHead->next = head;
		//newHead->val = 0;
		ListNode *p1, *p2, *q1, *q2;
		//p = head;
		q1 = head;//q1是为了删除q2时起作用
		q2 = head->next;//从第二个节点开始
		while (q2)
		{
			p1 = newHead;
			p2 = p1->next;
			while (p2 != q2)
			{
				if (p2->val > q2->val)
				{
					ListNode *s = (ListNode *)malloc(sizeof(ListNode));
					s->val = q2->val;
					s->next = p1->next;
					p1->next = s;//将s插入到p1,p2之间结束


					q1->next = q2->next;
					q2->next = NULL;
					free(q2);
					break;
				}
				else
				{
					p1 = p1->next;
					p2 = p1->next;
				}
			}//end while(p2 != q2)

			if (p2 == q2) //即前面已经排好序的当中没有比要插入的还大的，那么呆在原位置，就要将标志指针向后移一个单位
			{
				q1 = q1->next;
			}
			
			q2 = q1->next;//必须用这种方法
		}//end while
		newHead = newHead->next;
		return newHead;
	}
};
