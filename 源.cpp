#include <stdio.h>
#include <string.h>
#include <windows.h>
int main()
{
	char *p,*q;
	char name[10] = "duxinyu";
	char firstname = 'a';
	p = name;//���鲻��Ҫȡ��ַ��&�����������Ĭ��Ϊ������ĵ�һλ�ĵ�ַ
	q = &firstname;//��������Ҫȡ��ַ��&
	puts(p);//��������ַ���
	printf("%c\n", *q);
	printf("%s\n", p);//%sҲ����������������ַ���
	for (int i = 0; i <strlen(name); i++) {
		printf("%c",*p);
		p++;
	}
	printf("\n");
	system("pause");
	return 0;
}