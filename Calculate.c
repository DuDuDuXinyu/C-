#include <stdio.h>
#pragma warning(disable:4996);

void add()
{
	int a, b;
	printf("�����һ������ ��");
	scanf("%d", &a);
	printf("����ڶ������� ��");
	scanf("%d", &b);

	printf("%d + %d = %d\n", a, b, a + b);
}

void sub()
{
	int a, b;
	printf("���뱻���� ��");
	scanf("%d", &a);
	printf("������� ��");
	scanf("%d", &b);

	printf("%d - %d = %d\n", a, b, a - b);
}

void mul()
{
	int a, b;
	printf("�����һ������ ��");
	scanf("%d", &a);
	printf("����ڶ������� ��");
	scanf("%d", &b);

	printf("%d * %d = %d\n", a, b, a * b);
}

void div()
{
	int a, b;
	printf("���뱻���� ��");
	scanf("%d", &a);
	printf("������� ��");
	scanf("%d", &b);

	if (b == 0)
	{
		printf("����������Ϊ0���������");
		return ;
	}

	printf("%d / %d = %d\n", a, b, a / b);
}

void menu()
{
	printf("--------------------------\n\n");
	printf("--��ӭʹ�ö�����ļ�����--\n\n");
	printf("--1���ӷ�        2������--\n\n");
	printf("--3���˷�        4������--\n\n");
	printf("---       5���˳�       --\n\n");
	printf("--------------------------\n");
}

int main()
{
	menu();
	
	while (1)
	{
		int choose = 0;
		printf("��ѡ����Ҫ���еļ��� �� ");
		scanf("%d", &choose);
		if (choose == 5)
		{
			break;
		}
		switch(choose)
		{
		case 1:
			add(); 
			break;
		case 2:
			sub();
			break;
		case 3:
			mul();
			break;
		case 4:
			div();
			break;
		default:
			break;
		}
	}
	return 0;
	system("pause");
}
