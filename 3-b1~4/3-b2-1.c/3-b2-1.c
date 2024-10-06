/*2352467 信08 赵阿强*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	printf("请输入一个[1..30000]间的整数:\n");
	int num = 0;
	scanf("%d", &num);
	printf("万位 : %d\n", num / 10000);
	printf("千位 : %d\n", num % 10000 / 1000);
	printf("百位 : %d\n", num % 1000 / 100);
	printf("十位 : %d\n", num % 100 / 10);
	printf("个位 : %d\n", num % 10);
	
	return 0;
}