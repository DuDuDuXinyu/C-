#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

typedef struct ListNode {
	int val;
	struct ListNode* next;
}Node;

// �ָ�����

struct ListNode* partition(struct ListNode* head, int x)
{
	//��ջ�ϴ��������յ�����

	Node lessNode = { 0,NULL };
	Node moreNode = { 0,NULL };

	//��ָ��ָ�������
	//�γɴ�ͷ�ڵ������

	Node* lessTail = &lessNode;
	Node* moreTail = &moreNode;

	//��headΪ��ֱ�ӷ���


	if (NULL == head)
	{
		return NULL;
	}

	//��������

	while (head)
	{

		//����Ĵ����ֺ�ϸ�ڣ�Ҫע��

		if (head->val < x)
		{
			//������head����lessTail��
			//��������λ�û�����lessTail��ȷ����

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

	//����������ϳ�һ������
	//ע�������ϸ��
	//moreNode��next��ǰ�����������
	//��Ϊ�Ǹ���ͷ�ڵ������

	lessTail->next = moreNode.next;

	//ע�⣺�����moreTail֮����Ҫ����һ��NULL������
	//��Ϊ��һ���������þ���NULL��Ҳ�п�����head�ڴ˽ڵ�֮���һ���ڵ�ֱ��NULL

	moreTail->next = NULL;

	//��ͷ�ڵ����������ͷ�ڵ����һ���ڵ㼴��

	return lessNode.next;
}