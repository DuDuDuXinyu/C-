//1.实现strcpy
//2.实现strcat
//3.实现strstr
//4.实现strchr
//5.实现strcmp
//6.实现memcpy
//7.实现memmove
#include <stdio.h>
#include <windows.h>

char* myself_strcpy(char* p1,char* p2)//拷贝，把p2从头开始往p1里面放，包括'\0'
{
	printf(" myself_strcpy : ");
	while (*p2 != '\0') {
		*p1 = *p2;
		p1++;
		p2++;
	}
	*p1 = '\0';
	return p1;
}

char* myself_strcat(char* p1, char* p2)//把p2的字符串追加在p1的后面，从'\0'开始添加
{
	printf(" myself_strcat : ");
	while (*p1 != '\0') {
		p1++;
	}
	while (*p2 != '\0') {
		*p1 = *p2;
		p1++;
		p2++;
	}
	*p1 = '\0';
	return p1;
}

char* myself_strstr(char* p1, char* p2)//查找子串，然后返回子串首地址
{
	printf(" myself_strstr : ");
	char* p = p1;
	char* q = p1;
	while (*p != '\0') {
		if (*p != *p2) {
			p++;
			q = p;
		}
		else {
			char* k = p2;		
			do {
				p++;
				p2++;
				if (*p2 == '\0') {
					return q;
				}
			} while (*p==*p2);
			p2 = k;
		}
	}
	return NULL;
}

char* myself_strchr(char* p1, char p2)
{
	printf(" myself_strchr : ");
	char* p = p1;
	while (*p != '\0') {
		if (*p != p2) {
			p++;
		}
		else {
			return p;
		}
	}
	return NULL;
}

int myself_strcmp(char* p1, char* p2)
{
	printf(" myself_strcmp : ");
	while (*p1 != '\0') {
		if (*p1 == *p2) {
			p1++;
			p2++;
		}
		else if (*p1 < *p2) {
			return -1;
		}
		else {
			return 1;
		}
	}
	return 0;
}

char* myself_memcpy(char* p1, char* p2,size_t size)//拷贝，把p2从头开始往p1里面放size个字节，包括'\0'
{
	printf(" myself_memcpy : ");
	if ((p1 == NULL) && (p2 == NULL)) {
		return NULL;
	}
	while (size-- > 0){
		*p1 = *p2;
		p1++;
		p2++;
	}
	return p1;
}

char* myself_memmove(char* p1, char* p2, size_t size)//拷贝，把p2从头开始往p1的指定位置里面放size个字节，包括'\0'
{
	printf(" myself_memmove : ");
	if (size == 0) {
		return NULL;
	}
	if ((p1 == NULL) && (p2 == NULL)) {
		return NULL;
	}
	while (size-- > 0) {
		*p1 = *p2;
		p1++;
		p2++;
	}
	return p1;
}

int main()
{
	char arr1[32] = "abc";
	char arr2[] = "def";
	myself_strcpy(arr1, arr2);
	printf("%s\n", arr1);

	char arr3[32] = "abc";
	char arr4[] = "def";
	myself_strcat(arr3, arr4);
	printf("%s\n", arr3);

	char arr5[] = "abc def ghi xyz.";
	char* str1;
	str1 = myself_strstr(arr5, "def");
	printf("%s\n", str1);

	char arr6[] = "abc def ghi xyz.";
	char* str2;
	str2 = myself_strchr(arr6, 'd');
	printf("found at %d\n", str2 - arr6 + 1);

	char arr7[] = "z";
	char arr8[] = "def";
	int ret1 = myself_strcmp("z", "aabc");
	if (ret1 == 1) {
		printf("str1 > str2  ！\n");
	}
	else if (ret1 == -1) {
		printf("str1 < str2  ！\n");
	}
	else {
		printf("str1 == str2  ！\n");
	}

	char arr9[32] = "ab";
	char arr10[] = "cdef";
	myself_memcpy(arr9, arr10,sizeof(arr10));
	printf("%s\n", arr9);

	char arr11[] = "abcdef";
	myself_memmove(arr11+ 1, arr11 + 3, 2);
	printf("%s\n", arr11);

	system("pause");
	return 0;
}