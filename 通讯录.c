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

P people[1000] = { "������",1,"18700102071",19,"����" };
int ad = 1;

void add() {
	char name[32];
	printf("����������Ҫ��ӵ��˵����� �� ");
	scanf("%s", name);
	strcpy(people[ad].name,name);
	int sex;
	printf("����������Ҫ��ӵ��˵��Ա�0����Ů��1�����У� �� ");
	scanf("%d", &sex);
	people[ad].sex = sex;
	int age;
	printf("����������Ҫ��ӵ��˵����� �� ");
	scanf("%d", &age);
	people[ad].age = age;
	int telephone[11];
	printf("����������Ҫ��ӵ��˵ĵ绰���� �� ");
	scanf("%s", telephone);
	strcpy(people[ad].telephone,telephone);
	char address[10];
	printf("����������Ҫ��ӵ��˵ĵ�ַ �� ");
	scanf("%s", address);
	strcpy(people[ad].address,address);
	ad++;
}

int search()
{
	int i = 0;
	char name[32];
	printf("����������Ҫ���ҵ����˵����� �� ");
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
		printf("�Բ����������ҵ��˲���ͨѶ¼�� ��");
	}
	else {
		printf("�������ҵ��˵����Ϊ (%d) ��",ret);
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
		printf("�Ƿ�ȷ��ɾ������ϵ�� ��ȷ��������1��ȡ��������2�� ��");
		int num = 0;
		scanf("%d", &num);
		if (num == 1) {
			delete(ret);
		}
		else {
			printf("���ѳɹ�ȡ��ɾ��������");
		}
	}
	else {
		printf("�Բ�������Ҫɾ������ϵ�˲���ͨѶ¼�У�");
	}
}

void modify_menu()
{
	printf("#######################################\n");
	printf("###1���޸�����         2���޸ĵ绰#####\n");
	printf("#######################################\n");
	printf("###3���޸ĵ�ַ         4������#########\n");
	printf("#######################################\n");
	printf("Please make your choose ");
}

void modify()//�޸�����
{
	int ret = search();
	if (ret == -1) {
		printf("����Ҫ�޸ĵ���ϵ�˲����ڣ�");
	}
	else {
		modify_menu();
		int choose = 0;
		scanf("%d", &choose);
		if (choose == 1) {
			int age;
			printf("����������Ҫ�޸ĵ����� �� ");
			scanf("%d", &age);
			people[ret-1].age = age;
		}
		else if (choose == 2) {
			int telephone[11];
			printf("����������Ҫ�޸ĵĵ绰���� �� ");
			scanf("%s", telephone);
			strcpy(people[ret-1].telephone, telephone);
		}
		else if (choose == 3) {
			char address[10];
			printf("����������Ҫ�޸ĵĵ�ַ �� ");
			scanf("%s", address);
			strcpy(people[ret-1].address, address);
		}
		else {
			printf("���ѳɹ�ȡ���޸Ĳ�����");
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
	printf("���ѳɹ����������ϵ�ˣ�\n");
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
	printf("####1�������ϵ��       2����ѯ��ϵ��####\n\n");
	printf("####3��ɾ����ϵ��       4�����ͨѶ¼####\n\n");
	printf("####5���޸���ϵ��       6����ʾͨѶ¼####\n\n");
	printf("####7������������       8���˳�      ####\n\n");
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