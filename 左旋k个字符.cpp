#include <stdio.h>
#include <windows.h>

#pragma warning (disable:4996)

void Rotate(char str[20], int m, int sum)
{
	int i = 0;
	char arr[20];
	sum -= (m+1);
	for (; i < m; i++) {
		arr[sum] = str[i];
		sum++;
	}
	int n = 0;
	for (; i <sum; i++) {
		arr[n] = str[i];
		n++;
	}
	i = 0;
	for (; i < sum; i++) {
		printf("%c", arr[i]);
	}
	
}
void LoopMove(char* pStr, int steps)
{
	char* pArr=pStr;
	char str[20];
	int num = 0;
	while (*pArr != '\0') {
		str[num]=*pArr++;
		num++;
	}
	pArr = pStr;
	while (*pArr != '\0') {
		str[num] = *pArr++;
		num++;
	}
	num /= 2;
	int i = num - steps;
	while (num--) {
		printf("%c", str[i]);
		i++;
	}
	printf("\n");
}

void Point(char* p, int steps)
{
	char* arr = p;
	int num = 0;
	while (*arr != '\0') {
		arr++;
		num++;
	}
	int sum=num-1;
	int i = 0;
	for (; i < steps; i++) {
		num = sum;
		for (; num > 0; num--) {
			char temp = *(p + num);
			*(p + num) = *(p - 1 + num);
			*(p - 1 + num) = temp;
		}
	}
	printf("%s\n", p);
}

int main()
{
	//int k = 0;
	//printf("请输入要选择的个数：##\n");
	//scanf("%d", &k);
	char str[] = "abcdef";
	Point(str, 2);
	//int ret = sizeof(str) / sizeof(str[0]);
	//Rotate(str, k,ret);
	return 0;
}