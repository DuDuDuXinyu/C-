#include <stdio.h>

//逆置arr数组从k到i之间的数据

void reverse(char* arr, int k, int i)
{
	while (k < i)
	{
		char temp = arr[k];
		arr[k] = arr[i];
		arr[i] = temp;
		i--;
		k++;
	}
}

//将每一个单词逆置

void easyReverse(char *arr)
{
	int i = 0, k = 0;
	while (arr[i] != '\0')
	{
		if (arr[i] == ' ')
		{
			reverse(arr, k, i - 1);
			k = i + 1;
		}
		i++;
	}
	reverse(arr, k, i - 1);
	puts(arr);
}

//将字符串按单词为单位逆置

void difficultReverse(char* arr,int len)
{
	int left = 0, right = 0;
	reverse(arr, 0, len - 1);

	while (arr[right] != '\0')
	{
		if (arr[right] == ' ')
		{
			reverse(arr, left, right - 1);
			left = right + 1;
		}
		right++;
	}
	reverse(arr, left, right - 1);
	puts(arr);
}

int main()
{
	char arr[] = "I am a student";
	int len = sizeof(arr) / sizeof(arr[0]);
	puts(arr);

	easyReverse(arr);
	
	char str[] = "I am a student";
	difficultReverse(str, len-1);

	system("pause");
	return 0;
}