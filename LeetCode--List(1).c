#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

//单链表的创建

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

//方法一：逆置全部链表，这样的话就是没有对比链表了（不可行）
//方法二：用快慢指针找到中间节点，然后把后半部分逆置比较

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

		if (head->val == head->next->val)
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
			if (newNode->val == head->val)
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
			if (newNode->val == head->val)
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

//方法三：将链表的数据存在数组中然后判断
//虽然方法很暴力但是思维很简单，并且运行时间快
//缺点就是占用了额外的内存

bool isPalindrome(struct ListNode* head) {
	Node* cur = head;

	//由于未知链表的长度，所以数组的容量需要更大

	int a[50000];

	//存入数组

	int i = 0;
	while (cur)
	{
		a[i++] = cur->val;
		cur = cur->next;
	}

	//用数组的方法来判断是否为回文

	int left = 0, right = i - 1;
	while (left < right)
	{
		if (a[left] == a[right])
		{
			left++;
			right--;
		}
		else {
			return false;
		}
	}

	return true;
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

//方法三：直接连接俩个链表

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	if (NULL == l1)
	{
		return l2;
	}
	if (NULL == l2)
	{
		return l1;
	}

	//用newNode来指向他们其中的一个节点

	Node* newNode = NULL;

	//指向新链表的最后一个节点

	Node* tail = NULL;

	if (l1->val <= l2->val)
	{
		newNode = l1;
		l1 = l1->next;
	}
	else
	{
		newNode = l2;
		l2 = l2->next;
	}

	//因为现在newNode只有一个数据
	//所以tail就和newNode在同一个位置

	tail = newNode;

	//比较拼接

	while (l1 && l2)
	{
		//小的数据连接在tail的后面

		if (l1->val <= l2->val)
		{
			tail->next = l1;
			l1 = l1->next;
		}
		else
		{
			tail->next = l2;
			l2 = l2->next;
		}
		tail = tail->next;
	}

	//while出来之后肯定有一个链表为空
	//所以直接把为遍历完的直接接在tail的后面

	if (l1)
	{
		tail->next = l1;
	}
	else
	{
		tail->next = l2;
	}

	return newNode;
}

//方法四：方法三的优化版本
//采用的是带头节点的链表

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	if (NULL == l1)
	{
		return l2;
	}
	if (NULL == l2)
	{
		return l1;
	}

	//在栈上开辟的一个newNode

	Node newNode;

	//指向新链表的最后一个节点

	Node* tail = &newNode;
	while (l1 && l2)
	{
		if (l1->val <= l2->val)
		{
			tail->next = l1;
			l1 = l1->next;
		}
		else
		{
			tail->next = l2;
			l2 = l2->next;
		}
		tail = tail->next;
	}
	if (l1)
	{
		tail->next = l1;
	}
	else
	{
		tail->next = l2;
	}

	//返回的时候返回newNode的下一个节点

	return newNode.next;
}

//从尾到头打印链表,要求：用数组返回

//方法一：先将存后逆置

int* reversePrint(struct ListNode* head, int* returnSize) {

	//使用malloc开辟一个空间

	int* res = (int*)malloc(sizeof(int) * 10000);

	//将链表的数据存在开辟的res中

	int i = 0;
	while (head)
	{
		res[i++] = head->val;
		head = head->next;
	}

	int left = 0, right = i - 1;
	
	//逆置数组

	while (left < right)
	{
		int temp = res[left];
		res[left] = res[right];
		res[right] = temp;
		left++;
		right--;
	}

	//*returnSize的值就是改变外部数字的变量，来确定一共有几个数据

	*returnSize = i;

	return res;
}

//方法二：先逆置链表在存储

int* reversePrint(struct ListNode* head, int* returnSize) {
	int* res = (int*)malloc(sizeof(int) * 10000);

	//改变链表的指向，来逆置

	Node* cur = head;
	Node* prev = NULL;

	while (cur)
	{
		head = cur->next;
		cur->next = prev;
		prev = cur;
		cur = head;
	}

	//存入数组

	int i = 0;
	head = prev;
	while (head)
	{
		res[i++] = head->val;
		head = head->next;
	}
	*returnSize = i;

	return res;
}

//输出链表中倒数第k个节点

//方法一：先逆置之后然后在逆置k个结点即可

struct ListNode* getKthFromEnd(struct ListNode* head, int k) {
	//先逆置遍历整个链表

	Node* cur = head;
	Node* prev = NULL;

	while (cur)
	{
		head = cur->next;
		cur->next = prev;
		prev = cur;
		cur = head;
	}

	//开始逆置k个结点，所得到的链表就是返回的链表

	head = prev;
	cur = head;
	prev = NULL;
	while (k--)
	{
		head = cur->next;
		cur->next = prev;
		prev = cur;
		cur = head;
	}

	return prev;
}

//方法二：采用双指针来解决

struct ListNode* getKthFromEnd(struct ListNode* head, int k) {
	Node* latter = head;
	Node* former = head;

	//先让former走k个字节

	while (k--)
	{
		former = former->next;
	}

	//latter和former一起走
	//当former走到末尾的时候
	//这时latter所在的位置就是倒数第k个节点
	//latter和直接的差距就是k个字节

	while (former)
	{
		latter = latter->next;
		former = former->next;
	}

	return latter;
}

//相交链表
//判断俩个链表是否相交
//相交指的是从某一个节点之后的所有节点都相同

struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) 
{
	//当有一个链表为空的时候，那么俩个链表就不会相交

	if (NULL == headA || NULL == headB)
	{
		return NULL;
	}

	Node* curA = headA;
	Node* curB = headB;

	int along = 0, blong = 0;

	//俩个链表都走到最后
	//并计数得出俩个链表的长度

	while (curA)
	{
		along++;
		curA = curA->next;
	}
	while (curB)
	{
		blong++;
		curB = curB->next;
	}

	//如果俩个链表相交的话，那么他们最后的节点一定是相同的
	//所以我们只需要判断俩个链表的最后一个节点是否相同即可得知俩个链表是否相同

	if (curA != curB)
	{
		return NULL;
	}

	//因为俩个链表有可能不是一样的长度，但是从相交节点之后都是相同的
	//所以我们需要让长的链表从和短的链表的等长的地方开始
	//这样俩个链表再开始同时向后遍历
	//此时遇到俩个链表相同的节点就是相交的节点

	int num = along - blong;
	curA = headA;
	curB = headB;
	if (num > 0)
	{
		while (num--)
		{
			curA = curA->next;
		}
	}
	else
	{
		while (num++)
		{
			curB = curB->next;
		}
	}

	while (curA != curB)
	{
		curA = curA->next;
		curB = curB->next;
	}

	return curA;
}