#include "ATM.h"

int cardnumber[19];
int cardpassword[6];
int mymoney=0;

void Menu()
{
	printf("------�������������-------\n");
	printf("----------1����¼----------\n");
	printf("----------2��ע��----------\n");
	printf("----------3���˳�----------\n");
	printf("---------------------------\n");
}

void Registered()
{
	printf("���п�����Ϊ�������У�\n");	
	printf("���������������п�����(6λ����)��");
	getchar();
	gets(cardpassword);
	printf("ע��ɹ���\n");
	printf("�������п�����Ϊ��1870010207187654321\n");
	strcpy(cardnumber, "1870010207187654321");
}

void Deposit()
{
	printf("����������Ҫ����Ľ�Ԫ����");
	int money = 0;
	scanf("%d", &money);
	printf("��������˻��Ľ��Ϊ %d Ԫ\n",money);
	printf("y/n��");
	char choose;
	scanf(" %c", &choose);
	if (choose == 'y')
	{
		mymoney += money;
		for (int i = 0; i <= 5; i++)
		{
			printf("						      |%d%%\r",i*20);
			int num = i;
			while (num--)
			{
				printf("---------");
			}
			printf("-------->");
			printf("%\r");
			Sleep(1000);
		}
		printf("\n�����ɣ����Ѵ���%dԪ\n",money);
	}
}

void Withdrawal()
{
	printf("����������Ҫȡ���Ľ�Ԫ����");
	int money = 0;
	scanf("%d", &money);
	printf("���Ӹ��˻�ȡ���Ľ��Ϊ %d Ԫ\n", money);
	printf("y/n��");
	char choose;
	scanf(" %c", &choose);
	if (choose == 'y')
	{
		if (money > mymoney)
		{
			printf("�������㣡\n");
			return;
		}
		mymoney -= money;
		for (int i = 0; i <= 5; i++)
		{
			printf("						      |%d%%\r", i * 20);
			int num = i;
			while (num--)
			{
				printf("---------");
			}
			printf("-------->");
			printf("%\r");
			Sleep(1000);
		}
		printf("\nȡ����ɣ�\n");
		printf("�Ƿ��ӡ��ִ����y/n��");
		scanf(" %c", &choose);
		if (choose == 'y')
		{
			time_t t;
			time(&t);
			printf("\n\n***************************\n");
			printf("******�������������******\n");
			printf("***************************\n");
			printf("ȡ�����       %dԪ\n",money);
			printf("ʣ����       %dԪ\n",Search());
			printf("%s\n\n\n", ctime(&t));
		}
	}
}

void Transfer()
{
	printf("������ת�����˺ţ�");
	int putcardnumber[19];
	getchar();
	gets(putcardnumber);
	printf("����ת�˽�");
	int money = 0;
	scanf("%d", &money);
	if (mymoney > money)
	{
		mymoney -= money;
		for (int i = 0; i <= 5; i++)
		{
			printf("						      |%d%%\r", i * 20);
			int num = i;
			while (num--)
			{
				printf("---------");
			}
			printf("-------->");
			printf("%\r");
			Sleep(1000);
		}
		printf("ת����ɣ�\n");
	}
	else
		printf("�������㣡");
}

int Search()
{
	printf("���Ϊ��%dԪ\n",mymoney);
	return mymoney;
}

void Modify()
{
	printf("��������룺");
	int putcardpassword[6];
	getchar();
	gets(putcardpassword);
	if (0 == strcmp(putcardpassword, cardpassword))
	{
		printf("���������룺");
		gets(putcardpassword);
		strcpy(cardpassword, putcardpassword); 
	}
	else
		printf("�������\n");
}

void Start()
{
	while (1)
	{
		printf("------�������������------\n");
		printf(" 1�����       2��ȡ��\n");
		printf(" 3��ת��       4����ѯ���\n");
		printf(" 5���޸�����   6���˿�\n");
		printf("--------------------------\n");
		printf("����������Ҫ���еĲ�����");

		int choose = 0;
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			Deposit();
			break;
		case 2:
			Withdrawal();
			break;
		case 3:
			Transfer();
			break;
		case 4:
			Search();
			break;
		case 5:
			Modify();
			break;
		case 6:
			return;
		default:
			return;
		}
	}	
}

int Login()
{
	int putcardnumber[19];
	int putcardpassword[6];
	printf("�������������п����ţ�19λ���֣���");
	getchar();
	gets(putcardnumber);
	printf("�������������п�����(6λ����)��");
	gets(putcardpassword);

	if (0 == strcmp(putcardnumber, cardnumber))
	{
		if (0 == strcmp(putcardpassword, cardpassword))
		{
			printf("��¼�ɹ���\n");
			Sleep(1000);
			system("cls");
			Start();
			return 1;
		}
	}
	printf("��¼ʧ�ܣ�\n");
	return 0;
}