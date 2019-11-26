#include <stdio.h>
#include <windows.h>

void exchange(char* p, char* q)
{
	while (p < q) {
		char temp = *p;
		*p = *q;
		*q = temp;
		p++;
		q--;
	}
}

void fun(char str[20])
{
	char* p = str;
	char* q = str;
	while (*q != '\0') {
		if (*q != ' ') {
			q++;
		}
		else {
			exchange(p, q-1);
			p = q + 1;
			q = p;
		}
	}
	exchange(p, q-1);
	exchange(str, q - 1);

}

int main()
{
	char str[] = "student a am i";
	fun(str);
	printf("%s\n", str);	
	system("pause");
	return 0;
}