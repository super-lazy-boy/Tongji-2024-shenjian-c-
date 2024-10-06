/*2352467 信08 赵阿强*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdbool.h>
int judge(int year)
{
	bool leap = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
	if (leap)
		return 1;
	else 
		return 0;
}
int daycount( int year ,int month,int day,int days_leap[],int days[])
{
	int i = 0;
	int num = 0;
	for (i = 0; i <= month - 2; i++)
	{
		if (judge(year) == 1)
			num += days_leap[i];
		else
			num += days[i];
	}
	return num + day;
}
int main()
{
	printf("请输入年，月，日\n");
	int year, month, day;
	scanf("%d %d %d", &year, &month, &day);
	int days_leap[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	int days[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	int num = 0;
	if (month < 1 || month>12) 
		printf("输入错误-月份不正确\n");
	else {
		if (judge(year) == 1)
		{
			if (day <= days_leap[month - 1])
				printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, daycount(year,month ,day,days_leap, days));
			else
				printf("输出错误-日与月的关系非法\n");
		}
		else
		{
			if (day <= days[month - 1])
				printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, daycount(year ,month ,day,days_leap, days));
			else
				printf("输出错误-日与月的关系非法\n");
		}
	}
	return 0;
}