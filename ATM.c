#include "ATM.h"

int cardnumber[19];
int cardpassword[6];
int mymoney=0;

void Menu()
{
	printf("------杜欣宇国际银行-------\n");
	printf("----------1、登录----------\n");
	printf("----------2、注册----------\n");
	printf("----------3、退出----------\n");
	printf("---------------------------\n");
}

void Registered()
{
	printf("银行卡正在为您分配中：\n");	
	printf("请先设置您的银行卡密码(6位数字)：");
	getchar();
	gets(cardpassword);
	printf("注册成功！\n");
	printf("您的银行卡卡号为：1870010207187654321\n");
	strcpy(cardnumber, "1870010207187654321");
}

void Deposit()
{
	printf("请输入你所要存入的金额（元）：");
	int money = 0;
	scanf("%d", &money);
	printf("您存入该账户的金额为 %d 元\n",money);
	printf("y/n：");
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
		printf("\n存款完成！您已存入%d元\n",money);
	}
}

void Withdrawal()
{
	printf("请输入你所要取出的金额（元）：");
	int money = 0;
	scanf("%d", &money);
	printf("您从该账户取出的金额为 %d 元\n", money);
	printf("y/n：");
	char choose;
	scanf(" %c", &choose);
	if (choose == 'y')
	{
		if (money > mymoney)
		{
			printf("您的余额不足！\n");
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
		printf("\n取款完成！\n");
		printf("是否打印回执单：y/n：");
		scanf(" %c", &choose);
		if (choose == 'y')
		{
			time_t t;
			time(&t);
			printf("\n\n***************************\n");
			printf("******杜欣宇国际银行******\n");
			printf("***************************\n");
			printf("取出金额       %d元\n",money);
			printf("剩余金额       %d元\n",Search());
			printf("%s\n\n\n", ctime(&t));
		}
	}
}

void Transfer()
{
	printf("请输入转给的账号：");
	int putcardnumber[19];
	getchar();
	gets(putcardnumber);
	printf("输入转账金额：");
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
		printf("转账完成！\n");
	}
	else
		printf("您的余额不足！");
}

int Search()
{
	printf("余额为：%d元\n",mymoney);
	return mymoney;
}

void Modify()
{
	printf("输入旧密码：");
	int putcardpassword[6];
	getchar();
	gets(putcardpassword);
	if (0 == strcmp(putcardpassword, cardpassword))
	{
		printf("输入新密码：");
		gets(putcardpassword);
		strcpy(cardpassword, putcardpassword); 
	}
	else
		printf("密码错误！\n");
}

void Start()
{
	while (1)
	{
		printf("------杜欣宇国际银行------\n");
		printf(" 1、存款       2、取款\n");
		printf(" 3、转账       4、查询余额\n");
		printf(" 5、修改密码   6、退卡\n");
		printf("--------------------------\n");
		printf("请输入您所要进行的操做：");

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
	printf("请输入您的银行卡卡号（19位数字）：");
	getchar();
	gets(putcardnumber);
	printf("请输入您的银行卡密码(6位数字)：");
	gets(putcardpassword);

	if (0 == strcmp(putcardnumber, cardnumber))
	{
		if (0 == strcmp(putcardpassword, cardpassword))
		{
			printf("登录成功！\n");
			Sleep(1000);
			system("cls");
			Start();
			return 1;
		}
	}
	printf("登录失败！\n");
	return 0;
}