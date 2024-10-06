/* 信08 2352467 赵阿强*/
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdbool.h>

int main()
{
	int year = 0;
	int month = 0;
	int week = 0;
	int ret = 0;
	while (1) {
		printf("请输入年份(2000-2030)和月份(1-12) : ");
		ret = scanf("%d %d", &year, &month);
		if (ret != 2 )
		{
			scanf("%*[^\n]");
			printf ("输入非法，请重新输入\n");
			continue;
		}
		if (month < 1 || month>12 || year < 2000 || year>2030)
		{
			printf("输入非法，请重新输入\n");
			continue;
		}
		break;
	}
	while (1)
	{
		printf("请输入%d年%d月1日的星期(0-6表示星期日-星期六) : ",year,month);
		ret = scanf("%d", &week);
		if (ret != 1 || week < 0 || week>6)
		{
			scanf("%*[^\n]");
			printf("输入非法，请重新输入\n");
			continue;
		}
			break;
	}
	printf("\n");
	printf("%d年%d月的月历为:\n",year ,month);
	printf("星期日  星期一  星期二  星期三  星期四  星期五  星期六\n");
	int row = 0;
	while (week > 0)
	{
		printf("        ");
		row += 8;
		week--;
	}
	bool leap = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
	int days = 0;
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		days = 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		days = 30;
		break;
	case 2:
		if (leap) {
			days = 29;
			break;
		}
		else {
			days = 28;
			break;
		}
	}
	int count = 1;
	for (count; count <= days; count++)
	{
		printf("  ");
		printf("%2d", count);
		printf("  ");
		printf("  ");
		row += 8;
		if (row == 56) {
			row -= 56;
			printf("\n");
		}
	}

}