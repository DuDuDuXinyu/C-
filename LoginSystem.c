#include <stdio.h>

#pragma warning (disable:4996)

char name[100][20];
char password[100][20];
int size = 0;

void menu()
{
	printf("***********************\n");
	printf("1����¼\n");
	printf("2��ע���˺�\n");
	printf("3���˳�\n");
	printf("***********************\n");
}

void login()
{
	printf("���������ĵ�¼�˺ţ�");
	char yourname[20];
	gets();
	gets(yourname);
	printf("���������ĵ�¼���룺");
	char yourpassword[20];
	gets(yourpassword);

	int i = 0;
	while (i < size)
	{
		if (0 == strcmp(name[i], yourname))
		{
			if (0 == strcmp(password[i], yourpassword))
			{
				printf("��¼�ɹ���\n");
				return;
			}
			printf("�������\n");
			return;
		}
		i++;
	}
	printf("���˺Ų����ڣ���ע�ᣡ\n");
}

void registered()
{
	printf("��������ע����˺ţ�");
	char yourname[20];

	//��getchar������֮ǰѡ����֮��Ļس�
	//��Ȼgets���յģ�������һ�ε�gets����
	//gets����������\0�Ż��˳�
	//��һ����gets��Ҫ��ջ��������ڶ�����ʼ�Ͳ���Ҫ��gets�Լ����

	getchar();
	gets(yourname);
	printf("���������ĵ�¼���룺");
	char yourpassword[20];
	gets(yourpassword);

	int i = 0;
	while (i < size)
	{
		if (0 == strcmp(name[i], yourname))
		{
			printf("�˺��Ѵ���\n");
			return;
		}
		i++;
	}
	strcpy(name[size], yourname);
	strcpy(password[size], yourpassword);
	size++;
	printf("ע��ɹ���\n");
}

int main()
{
	while (1)
	{
		menu();
		int choose = 0;
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			login();
			break;
		case 2:
			registered();
			break;
		default:
			break;
		}
		if (3 == choose)
		{
			return 0;
		}
	}
}