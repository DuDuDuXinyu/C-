#include <stdio.h>
#include <string.h>

#pragma warning (disable:4996)

typedef struct people {
	char name[32];
	int sex;
	char telephone[11];
	int age;
	char address[10];
}P;

P people[1000] = { "杜欣宇",1,"18700102071",19,"西安" };
int ad = 1;

void add() {
	char name[32];
	printf("请输入你所要添加的人的姓名 ： ");
	scanf("%s", name);
	strcpy(people[ad].name,name);
	int sex;
	printf("请输入你所要添加的人的性别（0代表女，1代表男） ： ");
	scanf("%d", &sex);
	people[ad].sex = sex;
	int age;
	printf("请输入你所要添加的人的年龄 ： ");
	scanf("%d", &age);
	people[ad].age = age;
	int telephone[11];
	printf("请输入你所要添加的人的电话号码 ： ");
	scanf("%s", telephone);
	strcpy(people[ad].telephone,telephone);
	char address[10];
	printf("请输入你所要添加的人的地址 ： ");
	scanf("%s", address);
	strcpy(people[ad].address,address);
	ad++;
}

int search()
{
	int i = 0;
	char name[32];
	printf("请输入你所要查找到的人的名字 ： ");
	scanf("%s", name);
	while (i < ad) {
		if (strcmp(people[i].name, name) == 0) {
			return ++i;
		}
		i++;
	}
	return -1;
}

void search_end()
{
	int ret = search();
	if (ret == -1) {
		printf("对不起，你所查找的人不在通讯录中 ！");
	}
	else {
		printf("你所查找的人的序号为 (%d) ！",ret);
	}
}

void delete(int number)
{
	strcpy(people[number-1].name, "");
	people[number-1].sex = 0;
	people[number-1].age = 0;
	strcpy(people[number-1].telephone, "");
	strcpy(people[number-1].address, "");
}

void delete_end()
{
	int ret = search();
	if (ret != -1) {
		printf("是否确定删除该联系人 （确定扣数字1，取消扣数字2） ：");
		int num = 0;
		scanf("%d", &num);
		if (num == 1) {
			delete(ret);
		}
		else {
			printf("您已成功取消删除操作！");
		}
	}
	else {
		printf("对不起，您所要删除的联系人不在通讯录中！");
	}
}

void modify_menu()
{
	printf("#######################################\n");
	printf("###1、修改年龄         2、修改电话#####\n");
	printf("#######################################\n");
	printf("###3、修改地址         4、返回#########\n");
	printf("#######################################\n");
	printf("Please make your choose ");
}

void modify()//修改数据
{
	int ret = search();
	if (ret == -1) {
		printf("你所要修改的联系人不存在！");
	}
	else {
		modify_menu();
		int choose = 0;
		scanf("%d", &choose);
		if (choose == 1) {
			int age;
			printf("请输入你所要修改的年龄 ： ");
			scanf("%d", &age);
			people[ret-1].age = age;
		}
		else if (choose == 2) {
			int telephone[11];
			printf("请输入你所要修改的电话号码 ： ");
			scanf("%s", telephone);
			strcpy(people[ret-1].telephone, telephone);
		}
		else if (choose == 3) {
			char address[10];
			printf("请输入你所要修改的地址 ： ");
			scanf("%s", address);
			strcpy(people[ret-1].address, address);
		}
		else {
			printf("您已成功取消修改操作！");
		}
	}
}

void empty()
{
	while (ad--) {
		strcpy(people[ad].name, "");
		people[ad].sex = 0;
		people[ad].age = 0;
		strcpy(people[ad].telephone, "");
		strcpy(people[ad].address, "");
	}
	printf("您已成功清空所有联系人！\n");
}

void show()
{
	int i = 0;
	for (; i < ad; i++) {
		printf("%d. ",i+1);
		printf("%s ", people[i].name);
		printf("%d ", people[i].sex);
		printf("%d ", people[i].age);
		printf("%s ", people[i].telephone);
		printf("%s \n", people[i].address);
	}
}

void save_to_txt()
{

}

void name_order()
{
	int i = 0;
	for (; i < ad - 1; i++) {
		int j = 0;
		for (; j < ad - i - 1; j++) {
			if (strcmp(people[j].name, people[j + 1].name) == 1) {
				char name[32];
				strcpy(name, people[j].name);
				strcpy(people[j].name, people[j + 1].name);
				strcpy(people[j + 1].name, name);
			}
		}
	}
}

void menu()
{
	printf("#########################################\n\n");
	printf("####1、添加联系人       2、查询联系人####\n\n");
	printf("####3、删除联系人       4、清空通讯录####\n\n");
	printf("####5、修改联系人       6、显示通讯录####\n\n");
	printf("####7、按姓名排序       8、退出      ####\n\n");
	printf("#########################################\n");
}

int main()
{
	while (1) {
		menu();
		int ch = 0;
		scanf("%d", &ch);
		if (ch == 8) {
			break;
		}
		switch (ch) {
		case 1:
			add();
			break;
		case 2:
			search_end();
			break;
		case 3:
			delete_end();
			break;
		case 4:
			empty();
			break;
		case 5:
			modify();
			break;
		case 6:
			show();
			break;
		case 7:
			name_order();
			break;
		}
	}
	system("pause");
	return 0;
}