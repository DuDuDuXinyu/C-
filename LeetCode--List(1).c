#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

 typedef struct ListNode {
	int val;
	struct ListNode *next;
 }Node;

 //移除链表元素

struct ListNode* removeElements(struct ListNode* head, int val) {
	Node* cur = head;
	Node* prev = NULL;

	while (cur)
	{
		if (cur->val == val)
		{
			//判断该需要删除的位置在哪里

			if (cur == head)
			{
				//在头节点的情况
				//头删

				head = head->next;
				free(cur);
				cur = head;
			}
			else
			{
				//不在头节点的情况

				prev->next = cur->next;
				free(cur);
				cur = prev->next;
			}
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
	return head;
}

//反转链表

//改变next的指向来反转

 struct ListNode* reverseList(struct ListNode* head){
     Node* prev=NULL;
     Node* cur=head;
     Node* next=NULL;

     while(cur)
     {
         assert(cur);

         next=cur->next;
         cur->next=prev;
         prev=cur;
         cur=next;
     }
     return prev;
 }

//采用头插的方法来反转

struct ListNode* reverseList(struct ListNode* head) {
	Node* cur = head;
	Node* newNode = NULL;

	while (cur)
	{
		//用来保存下一个节点
		head = cur->next;
		//头插
		//把head的第一个节点插在newNode里
		cur->next = newNode;
		newNode = cur;
		cur = head;
	}
	return newNode;
}

//判断是否存在环形链表
//bool的头文件是<stdbool.h>

bool hasCycle(struct ListNode* head) {
	Node* low = head;
	Node* fast = head;

	//while里面的条件要注意
	//fast是双数的条件
	//fast->next是单数的条件

	while (fast && fast->next)
	{
		//慢的一次走一个

		low = low->next;

		//快的一次走俩个

		fast = fast->next->next;

		//如果有环的话fast就会追上low

		if (low == fast)
		{
			return true;
		}
	}
	return false;
}

//找到链表的中间节点
//要求：时间复杂度0（1）

struct ListNode* middleNode(struct ListNode* head) {
	Node* low = head;
	Node* fast = head;

	//fast一次走俩个节点
	//low一次走一个节点
	//当fast到达NULL的时候
	//low就是返回的一半的节点

	while (fast && fast->next)
	{
		low = low->next;
		fast = fast->next->next;
	}
	return low;
}