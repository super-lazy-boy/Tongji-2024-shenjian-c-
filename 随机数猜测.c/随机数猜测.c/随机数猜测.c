#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdlib.h>
#include<time.h>

void menu()
{
	printf("*************************");
	printf("*************************");
	printf("*****输入1，开始游戏*****");
	printf("*************************");
	printf("*************************");
	return 0;
}

void game()
{
	int key = rand() % 100 + 1;
	int guess = 0;
	while (1)
	{
		printf("请输入一个数字:");
		scanf("%d", &guess);
		if (guess < key)
			printf("抱歉，你猜小了。");
		else if (guess > key)
			printf("抱歉，你猜大了。");
		else
		{
			printf("恭喜你。猜对了！");
			break;
		}

	}
	return 0;
}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	menu();
	scanf("%d", &input);
	if (input == 1)
	{
		game();
		break;
	}
	else
		printf("抱歉输入错误，请重新输入。");
	return 0;
}