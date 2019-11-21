#include <stdio.h>
#include <string.h>
#include <windows.h>
int main()
{
	char *p,*q;
	char name[10] = "duxinyu";
	char firstname = 'a';
	p = name;//数组不需要取地址符&，数组的名字默认为该数组的第一位的地址
	q = &firstname;//非数字需要取地址符&
	puts(p);//用于输出字符串
	printf("%c\n", *q);
	printf("%s\n", p);//%s也可以用于输出整个字符串
	for (int i = 0; i <strlen(name); i++) {
		printf("%c",*p);
		p++;
	}
	printf("\n");
	system("pause");
	return 0;
}