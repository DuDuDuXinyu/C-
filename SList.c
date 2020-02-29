#include "SList.h"

//构建一个新的节点

SLNode* BuySLNode(DateType data)
{
	SLNode* newNode = (SLNode*)malloc(sizeof(SLNode));
	if (NULL == newNode)
	{
		printf("申请节点失败 ！");
		arrest(newNode);
	}
	newNode->data = data;
	newNode->next = NULL;

	return newNode;
}

//尾插

void SLPushBack(SLNode** head, DateType data)
{
	//判断链表是否存在
	assert(head);

	SLNode* newNode = BuySLNode(data);
	
	//链表是否为空
	if (*head == NULL)
	{
		//第一个节点的插入方式
		*head = newNode;
	}
	else 
	{
		//说明链表中已经有节点了
		//进行尾插
		//先去找链表的最后一个节点（next为NULL）
		SLNode* tail = *head;
		//用循环找到最后的节点
		while (tail->next) 
		{
			//由于是单链表，不是顺序表
			//所以不可以用tail++
			tail = tail->next;
		}
		//将新节点链接到最后一个节点之后
		tail->next = newNode;
	}
}

//尾删

void SLPopBack(SLNode** head)
{
	assert(head);

	//空链表
	if (NULL == *head)
	{
		return;
	}
	else if (NULL == (*head)->next)
	{
		free(*head);
		*head = NULL;
	}
	else
	{
		//有多个节点
		//需要借助cur先找到最后一个节点
		//并且保存cur的前一个节点
		SLNode* cur = *head;
		SLNode* prev = NULL;
		while (cur->next)
		{
			prev = cur;
			cur = cur->next;
		}
		prev->next = cur->next;
		free(cur);
	}
}

//头插

void SLPushFront(SLNode** head, DateType data)
{
	assert(head);

	SLNode* newNode = BuySLNode(data);
	newNode->next = *head;
	*head = newNode;
}

// 头删

void SLPopFront(SLNode** head)
{
	assert(head);

	SLNode* delNode = (*head);

	if (NULL == *head)
	{
		return;
	}

	*head = delNode->next;
	free(delNode);
}

//在pos位置之后插入data

void SLInseartAfter(SLNode* pos, DateType data)
{
	SLNode* newNode = NULL;

	//检测参数

	if (NULL == pos)
	{
		return;
	}

	newNode = BuySLNode(data);
	newNode->next = pos->next;
	pos->next = newNode;

}

//删除pos后面的节点

void SLEraseAfter(SLNode* pos)
{
	SLNode* delNode = NULL;

	//无法删除第一个节点和最后一个节点
	
	if (NULL == pos || NULL == pos->next)
	{
		return;
	}
	delNode = pos->next;
	pos->next = delNode->next;
	free(delNode);
}

//链表的长度

int SLSize(SLNode* head)
{
	int count = 0;
	SLNode* cur = head;
	while (cur) 
	{
		count++;
		cur = cur->next;
	}
	return count;
}

//找到数据为data的节点

SLNode* SLFind(SLNode* head, DateType data)
{
	SLNode* cur = head;
	while (cur)
	{
		if (cur->data == data)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//摧毁链表

void SLDeatroy(SLNode** head)
{
	assert(head);
	SLNode* cur = *head;

	//因为free只能释放当前一个节点
	//所以需要一个个的去释放
	//不然会造成内存泄露

	while (cur)
	{
		*head = cur->next;
		free(cur);
		cur = *head;
	}
}

//打印链表

void PrintSList(SLNode* head)
{
	SLNode* cur = head;
	while (cur) {
		printf("%d--->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}