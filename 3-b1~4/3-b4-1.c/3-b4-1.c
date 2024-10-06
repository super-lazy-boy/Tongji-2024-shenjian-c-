/*2352467 信08 赵阿强*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
int main()
{
	printf("请输入三角形的两边及其夹角（角度）\n");
	int a = 0;
	int b = 0;
	int c = 0;
	const double pi = 3.14159;
	scanf("%d %d %d", &a, &b, &c);
	double s = 0;
	s = a * b * sin(c*pi/180) / 2;
	printf("三角形面积为 : %.3f", (float)s);
	return 0;
}