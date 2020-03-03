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

//判断一个链表是否为回文链表
//方法一：用快慢指针找到中间节点，然后把后半部分逆置比较
//方法二：逆置全部链表，这样的话就是没有对比链表了（不可行）

bool isPalindrome(struct ListNode* head) {
	SLNode* low = head;
	SLNode* fast = head;
	SLNode* prev = NULL;
	SLNode* newNode = NULL;

	//因为下面的的函数体无法判断链表为空和只有一个数据的情况

	if (head == NULL || head->next == NULL) 
	{
		//当链表为空或者只有一个数据的时候，直接判定为true

		return true;
	}

	//这个判断的是当链表有俩个数据的情况
	//这段的if语句可以不要
	//但是只有写的话可以降低函数的时间复杂度
	//这里只需要一次比较即可完成判断

	if (head->next->next == NULL) {

		//我们只需要比较第一个和第二个数据是不是相同的即可

		if (head->data == head->next->data)
		{
			return true;
		}
		return false;
	}

	//while里面的条件要注意
	//fast是双数的条件
	//fast->next是单数的条件

	while (fast && fast->next)
	{
		//保存low的前一个值
		//因为双数的时候prev才是前一部分的最后一个
		prev = low;

		//慢的一次走一个

		low = low->next;

		//快的一次走俩个
		//用三目运算符来确定最后的fast的位置
		//fast = fast->next ? fast->next->next : fast->next;
		//但是为了以后的步骤未采用这种方法

		fast = fast->next->next;
	}

	//偶数个

	if (fast == NULL)
	{
		//让head这个链表在一半的地方就结束

		prev->next = NULL;

		//逆置后半部分的链表

		fast = low;
		while (fast)
		{
			fast = low->next;
			low->next = newNode;
			newNode = low;
			low = fast;
		}

		//遍历俩个链表，判断是否为回文函数

		while (newNode && head)
		{
			if (newNode->data == head->data)
			{
				newNode = newNode->next;
				head = head->next;
			}
			else {
				return false;
			}
		}
		return true;
	}

	//奇数个

	else
	{
		//定位到后半部分链表的开始位置

		fast = low->next;

		//释放处于最中间的位置的数据

		free(low);

		//逆置后半部分链表

		low = fast;
		prev->next = NULL;
		while (fast)
		{
			fast = low->next;
			low->next = newNode;
			newNode = low;
			low = fast;
		}

		//遍历俩个链表，判断是否为回文函数

		while (newNode && head)
		{
			if (newNode->data == head->data)
			{
				newNode = newNode->next;
				head = head->next;
			}
			else {
				return false;
			}
		}
		return true;
	}
}

//给定一个节点，在链表中删除该节点

void deleteNode(struct ListNode* node) 
{
	//cur是用来释放node所替代的节点的
	//为了防止造成内存泄露

	Node* cur = node->next;
	node->val = node->next->val;
	node->next = node->next->next;
	free(cur);
}

// 二进制链表转整数
//链表中每个结点的值不是 0 就是 1

int getDecimalValue(struct ListNode* head) {

	//

	int bit[32], i = 0, sum = 0, count = 0;

	//把链表的数据按顺序的放在数组中

	while (head)
	{
		bit[i++] = head->val;
		head = head->next;
	}
	count = i;

	//二进制转换为整数

	while (i)
	{
		if (bit[i - 1] == 1)
		{
			sum += pow(2, count - i);
		}
		i--;
	}
	return sum;
}

//合并两个已排序的链表

//方法一：采用了递归的方法来解决整个问题
//好处就是并没有开辟新空间
//不好处就是当链表过长（数据量很大）的时候，递归所需要的栈空间和时间的消耗比较大

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	if (l1 == NULL) {
		return l2;
	}
	if (l2 == NULL) {
		return  l1;
	}
	if (l1->val < l2->val) {
		l1->next = mergeTwoLists(l1->next, l2);
		return l1;
	}
	else {
		l2->next = mergeTwoLists(l1, l2->next);
		return l2;
	}
}

//方法二：开辟一个新的链表来存储整个俩个链表的数据

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	Node* newNode = NULL;

	//头插法来把小的数据压入newNode中

	while (l1 && l2)
	{
		if (l1->val > l2->val)
		{
			Node* cur = l2->next;
			l2->next = newNode;
			newNode = l2;
			l2 = cur;
		}
		else
		{
			Node* cur = l1->next;
			l1->next = newNode;
			newNode = l1;
			l1 = cur;
		}
	}

	//注意这里不可以直接把未插入的链表接到newNode的后
	//因为之前的排序过程中将最小的数字给排在了newNode的开始
	//所以后面的排序也需要按之前的头插进去

	while (l1)
	{
		Node* cur = l1->next;
		l1->next = newNode;
		newNode = l1;
		l1 = cur;
	}
	while (l2)
	{
		Node* cur = l2->next;
		l2->next = newNode;
		newNode = l2;
		l2 = cur;
	}

	//由于这样出来的newNode的链表是逆序的
	//调用逆置表的很熟reverseList来逆置一下

	return reverseList(newNode);
}