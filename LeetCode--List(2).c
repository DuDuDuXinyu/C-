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

//找到带环链表的环起点

struct ListNode* detectCycle(struct ListNode* head) {
	Node* fast = head;
	Node* low = head;

	//通过快慢指针来判断链表是否带环
	//isCircycle则是用来表示链表是否带环的标志

	bool isCircycle = false;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		low = low->next;
		if (low == fast)
		{
			isCircycle = true;
			break;
		}
	}

	//不带环，直接返回NULL

	if (!isCircycle)
	{
		return NULL;
	}

	//fast为快慢指针相遇的第一次相遇点
	//由于快慢指针的特性可以得知：当快慢指针相遇时，慢指针并未走完一圈
	//此时让head从头开始，fast和head同时以一次一步的开始遍历
	//当fast等于head的时候就是环的起点
	//head到环的起点距离为L
	//环的起点到fast的距离为X
	//环长为R
	//fast距离环起点的距离为R-X
	//由fast和low的关系可知：2L+2X=L+X+nR(前面的2倍的low的路程，后面是fast的路程)
	//L=nR-X->{n=1,L=R-X}{n=2,L=R-X+R}
	//可以得知不管n为多少，当head走完L时，fast也刚好走完nR-X
	//则得出head==fast时是环的起点

	while (fast != head)
	{
		fast = fast->next;
		head = head->next;
	}

	return head;
}