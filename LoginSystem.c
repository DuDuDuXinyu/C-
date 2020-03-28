#include <stdio.h>

#pragma warning (disable:4996)

char name[100][20];
char password[100][20];
int size = 0;

void menu()
{
	printf("***********************\n");
	printf("1、登录\n");
	printf("2、注册账号\n");
	printf("3、退出\n");
	printf("***********************\n");
}

void login()
{
	printf("请输入您的登录账号：");
	char yourname[20];
	gets();
	gets(yourname);
	printf("请输入您的登录密码：");
	char yourpassword[20];
	gets(yourpassword);

	int i = 0;
	while (i < size)
	{
		if (0 == strcmp(name[i], yourname))
		{
			if (0 == strcmp(password[i], yourpassword))
			{
				printf("登录成功！\n");
				return;
			}
			printf("密码错误！\n");
			return;
		}
		i++;
	}
	printf("该账号不存在，请注册！\n");
}

void registered()
{
	printf("请设置您注册的账号：");
	char yourname[20];

	//用getchar来吸收之前选择功能之后的回车
	//不然gets吸收的，就算这一次的gets结束
	//gets的输入遇到\0才会退出
	//第一次用gets需要清空缓冲区，第二个开始就不需要，gets自己清空

	getchar();
	gets(yourname);
	printf("请设置您的登录密码：");
	char yourpassword[20];
	gets(yourpassword);

	int i = 0;
	while (i < size)
	{
		if (0 == strcmp(name[i], yourname))
		{
			printf("账号已存在\n");
			return;
		}
		i++;
	}
	strcpy(name[size], yourname);
	strcpy(password[size], yourpassword);
	size++;
	printf("注册成功！\n");
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