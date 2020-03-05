#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

typedef struct ListNode {
	int val;
	struct ListNode* next;
}Node;

// 分割链表

struct ListNode* partition(struct ListNode* head, int x)
{
	//在栈上创建俩个空的链表

	Node lessNode = { 0,NULL };
	Node moreNode = { 0,NULL };

	//用指针指向空链表
	//形成带头节点的链表

	Node* lessTail = &lessNode;
	Node* moreTail = &moreNode;

	//当head为空直接返回


	if (NULL == head)
	{
		return NULL;
	}

	//遍历分类

	while (head)
	{

		//这里的存数字很细节，要注意

		if (head->val < x)
		{
			//将整个head接在lessTail后
			//但是最后的位置还是由lessTail来确定的

			lessTail->next = head;
			lessTail = head;
		}
		else
		{
			moreTail->next = head;
			moreTail = head;
		}
		head = head->next;
	}

	//将俩个链表合成一个链表
	//注意这里的细节
	//moreNode的next与前面的链表链接
	//因为是个带头节点的链表

	lessTail->next = moreNode.next;

	//注意：这里的moreTail之后需要加入一个NULL来结束
	//因为不一定这里正好就是NULL，也有可能是head在此节点之后的一串节点直到NULL

	moreTail->next = NULL;

	//带头节点的链表，返回头节点的下一个节点即可

	return lessNode.next;
}