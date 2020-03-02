#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

 typedef struct ListNode {
	int val;
	struct ListNode *next;
 }Node;

 //�Ƴ�����Ԫ��

struct ListNode* removeElements(struct ListNode* head, int val) {
	Node* cur = head;
	Node* prev = NULL;

	while (cur)
	{
		if (cur->val == val)
		{
			//�жϸ���Ҫɾ����λ��������

			if (cur == head)
			{
				//��ͷ�ڵ�����
				//ͷɾ

				head = head->next;
				free(cur);
				cur = head;
			}
			else
			{
				//����ͷ�ڵ�����

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

//��ת����

//�ı�next��ָ������ת

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

//����ͷ��ķ�������ת

struct ListNode* reverseList(struct ListNode* head) {
	Node* cur = head;
	Node* newNode = NULL;

	while (cur)
	{
		//����������һ���ڵ�
		head = cur->next;
		//ͷ��
		//��head�ĵ�һ���ڵ����newNode��
		cur->next = newNode;
		newNode = cur;
		cur = head;
	}
	return newNode;
}

//�ж��Ƿ���ڻ�������
//bool��ͷ�ļ���<stdbool.h>

bool hasCycle(struct ListNode* head) {
	Node* low = head;
	Node* fast = head;

	//while���������Ҫע��
	//fast��˫��������
	//fast->next�ǵ���������

	while (fast && fast->next)
	{
		//����һ����һ��

		low = low->next;

		//���һ��������

		fast = fast->next->next;

		//����л��Ļ�fast�ͻ�׷��low

		if (low == fast)
		{
			return true;
		}
	}
	return false;
}

//�ҵ�������м�ڵ�
//Ҫ��ʱ�临�Ӷ�0��1��

struct ListNode* middleNode(struct ListNode* head) {
	Node* low = head;
	Node* fast = head;

	//fastһ���������ڵ�
	//lowһ����һ���ڵ�
	//��fast����NULL��ʱ��
	//low���Ƿ��ص�һ��Ľڵ�

	while (fast && fast->next)
	{
		low = low->next;
		fast = fast->next->next;
	}
	return low;
}

//�ж�һ�������Ƿ�Ϊ��������
//����һ���ÿ���ָ���ҵ��м�ڵ㣬Ȼ��Ѻ�벿�����ñȽ�
//������������ȫ�����������Ļ�����û�жԱ������ˣ������У�

bool isPalindrome(struct SLNode* head) {
	SLNode* low = head;
	SLNode* fast = head;
	SLNode* prev = NULL;
	SLNode* newNode = NULL;

	//��Ϊ����ĵĺ������޷��ж�����Ϊ�պ�ֻ��һ�����ݵ����

	if (head == NULL || head->next == NULL) 
	{
		//������Ϊ�ջ���ֻ��һ�����ݵ�ʱ��ֱ���ж�Ϊtrue

		return true;
	}

	//����жϵ��ǵ��������������ݵ����
	//��ε�if�����Բ�Ҫ
	//����ֻ��д�Ļ����Խ��ͺ�����ʱ�临�Ӷ�
	//����ֻ��Ҫһ�αȽϼ�������ж�

	if (head->next->next == NULL) {

		//����ֻ��Ҫ�Ƚϵ�һ���͵ڶ��������ǲ�����ͬ�ļ���

		if (head->data == head->next->data)
		{
			return true;
		}
		return false;
	}

	//while���������Ҫע��
	//fast��˫��������
	//fast->next�ǵ���������

	while (fast && fast->next)
	{
		//����low��ǰһ��ֵ
		//��Ϊ˫����ʱ��prev����ǰһ���ֵ����һ��
		prev = low;

		//����һ����һ��

		low = low->next;

		//���һ��������
		//����Ŀ�������ȷ������fast��λ��
		//fast = fast->next ? fast->next->next : fast->next;
		//����Ϊ���Ժ�Ĳ���δ�������ַ���

		fast = fast->next->next;
	}

	//ż����

	if (fast == NULL)
	{
		//��head���������һ��ĵط��ͽ���

		prev->next = NULL;

		//���ú�벿�ֵ�����

		fast = low;
		while (fast)
		{
			fast = low->next;
			low->next = newNode;
			newNode = low;
			low = fast;
		}

		//�������������ж��Ƿ�Ϊ���ĺ���

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

	//������

	else
	{
		//��λ����벿������Ŀ�ʼλ��

		fast = low->next;

		//�ͷŴ������м��λ�õ�����

		free(low);

		//���ú�벿������

		low = fast;
		prev->next = NULL;
		while (fast)
		{
			fast = low->next;
			low->next = newNode;
			newNode = low;
			low = fast;
		}

		//�������������ж��Ƿ�Ϊ���ĺ���

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