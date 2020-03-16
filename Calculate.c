#include <stdio.h>
#pragma warning(disable:4996);

void add()
{
	int a, b;
	printf("输入第一个加数 ：");
	scanf("%d", &a);
	printf("输入第二个加数 ：");
	scanf("%d", &b);

	printf("%d + %d = %d\n", a, b, a + b);
}

void sub()
{
	int a, b;
	printf("输入被减数 ：");
	scanf("%d", &a);
	printf("输入减数 ：");
	scanf("%d", &b);

	printf("%d - %d = %d\n", a, b, a - b);
}

void mul()
{
	int a, b;
	printf("输入第一个乘数 ：");
	scanf("%d", &a);
	printf("输入第二个乘数 ：");
	scanf("%d", &b);

	printf("%d * %d = %d\n", a, b, a * b);
}

void div()
{
	int a, b;
	printf("输入被除数 ：");
	scanf("%d", &a);
	printf("输入除数 ：");
	scanf("%d", &b);

	if (b == 0)
	{
		printf("被除数不能为0，计算错误！");
		return ;
	}

	printf("%d / %d = %d\n", a, b, a / b);
}

void menu()
{
	printf("--------------------------\n\n");
	printf("--欢迎使用杜欣宇的计算器--\n\n");
	printf("--1、加法        2、减法--\n\n");
	printf("--3、乘法        4、除法--\n\n");
	printf("---       5、退出       --\n\n");
	printf("--------------------------\n");
}

int main()
{
	menu();
	
	while (1)
	{
		int choose = 0;
		printf("请选择所要进行的计算 ： ");
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
