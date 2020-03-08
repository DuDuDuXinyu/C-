#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

//单链表

typedef struct ListNode {
	int val;
	struct ListNode* next;
}Node;

//带随机指针的单链表

class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};

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

//复制带随机指针的链表
//除了next指针指向下一个节点外还有一个random的指针随机指向任意节点或者NULL

//方法一：开辟一个新的链表newHead，遍历head使newHead与head的next一样
//然后在head中找每一个节点的random所指向的位置，继而让newHead的random指向自己的链表对应的位置
//返回新开辟的链表newHead

class Solution {
public:

	//自定义一个开辟空间并初始化的函数

	Node* buyNode(int val)
	{
		Node* newNode = (Node*)malloc(sizeof(Node));
		
		//判断空间是否开辟成功

		if (NULL == newNode)
		{
			return NULL;
		}

		//赋值初始化

		newNode->val = val;
		newNode->next = NULL;
		newNode->random = NULL;

		return newNode;
	}

	Node* copyRandomList(Node* head) 
	{
		//如果head为NULL直接返回

		if (NULL == head)
		{
			return NULL;
		}

		Node* newHead = NULL;
		Node* newNode = NULL;
		Node* cur = head;

		//采用尾插法来cope链表head
		//因为一开始的newHead是NULL
		//所以需要现在循坏外面给定一个初值这样才可以进入循环

		newHead = buyNode(cur->val);
		Node* tail = newHead;
		cur = cur->next;
		while (cur)
		{
			newNode = buyNode(cur->val);
			tail->next = newNode;
			tail = newNode;
			cur = cur->next;
		}

		//开始遍历head找到每一个节点的random的指向

		cur = head;
		Node* newAdd = newHead;
		while (cur)
		{
			//辅助寻找random的指针

			Node* search = head;

			//辅助给newHead链表节点赋random值的指针

			Node* addRandom = newHead;

			//用来确定random的位置的数字

			int count = 0;

			//head的random为NULL，则直接给newHead的random赋值

			if (cur->random == NULL)
			{
				newAdd->random = NULL;

				//结束这一次的查找

				cur = cur->next;
				newAdd = newAdd->next;
				continue;
			}

			//寻找random的指向

			while (cur->random != search)
			{
				count++;
				search = search->next;
			}

			//指向第一个节点的情况

			if (count == 0)
			{
				newAdd->random = newHead;
			}

			//指向非第一个节点的情况

			while (count--)
			{
				newAdd->random = addRandom->next;
				addRandom = addRandom->next;
			}

			//每一次的递增

			cur = cur->next;
			newAdd = newAdd->next;
		}

		return newHead;
	}
};

//方法二：在原链表的每一个节点的后面插入一个与其val一样的节点
//然后当原来的链表某一节点的random指向的位置的下一个就是该节点下一个节点的random的位置
//最后把链表拆开即可

class Solution {
public:

	//自定义一个开辟空间并初始化的函数

	 Node* buyNode(int val)
	 {
	     Node* newNode=(Node*)malloc(sizeof(Node));

		 //判断空间是否开辟成功

	     if(NULL==newNode)
	     {
	         return NULL;
	     }

		 //赋值初始化

	     newNode->val=val;
	     newNode->next=NULL;
	     newNode->random=NULL;

	     return newNode;
	 }

	 Node* copyRandomList(Node* head) 
	 {
		 //如果head为NULL的情况，直接返回NULL

	     if(NULL==head)
	     {
	         return NULL;
	     }

		 //在原链表中插入新的节点

	     Node* cur=head;
	     Node* newNode=NULL;
	     while(cur)
	     {
	         newNode=buyNode(cur->val);
	         newNode->next=cur->next;
	         cur->next=newNode;
	         cur=newNode->next;
	     }

		 //给新节点的random赋值

	     cur=head;
	     while(cur)
	     {
	         newNode=cur->next;
	         if(cur->random)
	         {
	             newNode->random=cur->random->next;
	         }
	         cur=newNode->next;
	     }

		 //断开新旧俩个链表

	     Node* newHead=head->next;
	     cur=head;

	     while(cur->next)
	     {
	         newNode=cur->next;
	         cur->next=newNode->next;
	         cur=newNode;
	     }

	     return newHead;
	 }
};

//对链表进行插入排序

//方法一：在新链表中一个个的进行插入

struct ListNode* insertionSortList(struct ListNode* head) 
{
	Node* newHead = NULL;
	Node* cur = head;

	while (cur)
	{
		//将cur从原链表中移除--->头删

		head = cur->next;

		//在newHead中找cur的插入位置

		Node* pos = newHead;

		//保存插入位置的前一个节点

		Node* prev = NULL;

		//遍历寻找插入位置

		while (pos)
		{
			if (cur->val < pos->val)
			{
				break;
			}
			prev = pos;
			pos = pos->next;
		}

		//cur的位置已找到
		//插入位置在头结点处

		if (pos == newHead)
		{
			cur->next = newHead;
			newHead = cur;
		}

		//插入位置不在头结点

		else
		{
			cur->next = pos;
			prev->next = cur;
		}
		cur = head;
	}

	return newHead;
}

//方法二：转换为数组，然后排序，最后转换为链表返回

 struct ListNode* insertionSortList(struct ListNode* head){
     int  a[5000],i=0,k=0;
     Node* cur=head;

	 //存入数组

     while(cur)
     {
         a[i++]=cur->val;
         cur=cur->next;
     }

	 //冒泡排序

     for(int j=0;j<i-1;j++){
         for(k=0;k<i-1-j;k++){
             if(a[k]>a[k+1]){
                 int temp=a[k];
                 a[k]=a[k+1];
                 a[k+1]=temp;
             }
         }
     }

	 //转为链表

     cur=head;
     k=0;
     while(k<i)
     {
         cur->val=a[k++];
         cur=cur->next;
     }

     return head;
 }