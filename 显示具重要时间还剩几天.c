//实现一个C语言程序，可以显示现在离每年元旦节(1.1)、每年情人节(2.14)以及你毕业的天数(2018.6.8)。（判断闰平年）
#include <stdio.h>
#include <time.h>

#pragma warning (disable:4996)

int Leapyear(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || (year % 400 == 0)) {
		return 1;
	}
	return 0;
}

int main()
{
	time_t nowtime;
	struct tm *atime = { 0 };
	time(&nowtime);
	atime = localtime(&nowtime);
	int year =1900+ atime->tm_year;
	int mon =1+ atime->tm_mon;
	int day = atime->tm_mday;
	int leapmon[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	int notleapmon[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int nextyear=year+1;

	if (Leapyear(year) == 1) {
		if (mon == 1 && day == 1) {
			printf("今天就是元旦节！\n");
		}
		else {
			int i = 0;
			int today = 365 + 1 * ((year - 2016) / 4);
			for (; i < mon - 1; i++) {
				today -= leapmon[i];
			}
			today -= day;
			printf("距元旦节还有 %d 天！\n", today);
		}
		if (mon == 2 && day == 14) {
			printf("今天就是情人节！\n");
		}
		else if (mon == 1 ) {
			printf("距情人节还有 %d 天！\n", 31 - day + 14);
		}
		else if (mon == 2 && day < 14) {
			printf("距情人节还有 %d 天！\n", 14 - day);
		}
		else {
			int i = 1;
			int today = 365 + 1 * ((year - 2016) / 4);
			for (; i < mon - 1; i++) {
				today -= leapmon[i];
			}
			today -= day;
			printf("距情人节还有 %d 天！\n", today);
		}
		if (mon == 6 && day == 8) {
			int today = (year - 2018) * 365 + 1 * ((nextyear - 2016) / 4);
			printf("距毕业已经 %d 天！\n",today);
		}
		else if (mon < 6) {
			int today = (year - 2018) * 365 + 1 * ((nextyear - 2016) / 4);
			int i = 5;
			for (; i >= mon-1; i++) {
				today -= leapmon[i];
			}
			today += day;
			printf("距毕业已经 %d 天！\n",today);
		}
		else if (mon == 6 && day < 8) {
			int today = (year - 2018) * 365 + 1 * ((nextyear - 2016) / 4);
			today = today + 8 - day;
			printf("距毕业已经  %d 天！\n",today);
		}
		else {
			int i = 5;
			int today = (year - 2018) * 365 + 1 * ((nextyear - 2016) / 4) - 8;
			for (; i < mon - 1; i++) {
				today += leapmon[i];
			}
			today += day;
			printf("距毕业已经  %d 天！\n", today);
		}
	}
	else {
		if (mon == 1 && day == 1) {
			printf("今天就是元旦节！\n");
		}
		else {
			int i = 0;
			int today = 365 + 1 * ((year - 2016) / 4);
			for (; i < mon - 1; i++) {
				today -= notleapmon[i];
			}
			today -= day;
			printf("距元旦节还有 %d 天！\n", today);
		}
		if (mon == 2 && day == 14) {
			printf("今天就是情人节！\n");
		}
		else if (mon == 1) {
			printf("距情人节还有 %d 天！\n", 31 - day + 14);
		}
		else if (mon == 2 && day < 14) {
			printf("距情人节还有 %d 天！\n", 14 - day);
		}
		else {
			int i = 1;
			int today = 365 + 1 * ((year - 2016) / 4);
			for (; i < mon - 1; i++) {
				today -= notleapmon[i];
			}
			today -= day;
			today += 14;
			printf("距情人节还有 %d 天！\n", today);
		}
		if (mon == 6 && day == 8) {
			int today = (year - 2018) * 365 + 1 * ((nextyear - 2016) / 4);
			printf("距毕业已经 %d 天！\n", today);
		}
		else if (mon < 6) {
			int today = (year - 2018) * 365 + 1 * ((nextyear - 2016) / 4);
			int i = 5;
			for (; i >= mon - 1; i++) {
				today -= leapmon[i];
			}
			today += day;
			printf("距毕业已经 %d 天！\n", today);
		}
		else if (mon == 6 && day < 8) {
			int today = (year - 2018) * 365 + 1 * ((nextyear - 2016) / 4);
			today = today + 8 - day;
			printf("距毕业已经  %d 天！\n", today);
		}
		else {
			int i = 5;
			int today = (year - 2018) * 365 + 1 * ((nextyear - 2016) / 4) - 8;
			for (; i < mon - 1; i++) {
				today += notleapmon[i];
			}
			today += day;
			printf("距毕业已经  %d 天！\n", today);
		}
	}
	return 0;
}