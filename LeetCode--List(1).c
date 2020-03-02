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