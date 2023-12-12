#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdlib.h>
#include<time.h>

void menu()
{
	printf("*************************\n");
	printf("*************************\n");
	printf("*****输入1，开始游戏*****\n");
	printf("*************************\n");
	printf("*************************\n");

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
			printf("抱歉，你猜小了。\n");
		else if (guess > key)
			printf("抱歉，你猜大了。\n");
		else
		{
			printf("恭喜你。猜对了！\n");
			break;
		}

	}
}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	menu();
	scanf("%d", &input);
	switch (input)
	{
	case 1:
		game();
		break;
	default:
		printf("抱歉输入错误，请重新输入。\n");
		break;
	}
	return 0;
}

