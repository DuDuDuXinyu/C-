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

//�ҵ���������Ļ����

struct ListNode* detectCycle(struct ListNode* head) {
	Node* fast = head;
	Node* low = head;

	//ͨ������ָ�����ж������Ƿ����
	//isCircycle����������ʾ�����Ƿ�����ı�־

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

	//��������ֱ�ӷ���NULL

	if (!isCircycle)
	{
		return NULL;
	}

	//fastΪ����ָ�������ĵ�һ��������
	//���ڿ���ָ������Կ��Ե�֪��������ָ������ʱ����ָ�벢δ����һȦ
	//��ʱ��head��ͷ��ʼ��fast��headͬʱ��һ��һ���Ŀ�ʼ����
	//��fast����head��ʱ����ǻ������
	//head������������ΪL
	//������㵽fast�ľ���ΪX
	//����ΪR
	//fast���뻷���ľ���ΪR-X
	//��fast��low�Ĺ�ϵ��֪��2L+2X=L+X+nR(ǰ���2����low��·�̣�������fast��·��)
	//L=nR-X->{n=1,L=R-X}{n=2,L=R-X+R}
	//���Ե�֪����nΪ���٣���head����Lʱ��fastҲ�պ�����nR-X
	//��ó�head==fastʱ�ǻ������

	while (fast != head)
	{
		fast = fast->next;
		head = head->next;
	}

	return head;
}