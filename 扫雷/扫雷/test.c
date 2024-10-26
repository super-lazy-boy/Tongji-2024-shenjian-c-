#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include "game.h"

void menu()
{
	printf("*****************************\n");
	printf("*****************************\n");
	printf("******    1  play      ******\n");
	printf("******    0  exit      ******\n");
	printf("*****************************\n");
	printf("*****************************\n");
}
void game()
{
	//完成扫雷游戏
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	//初始化棋盘函数
	InitBoard(mine, ROWS, COLS, '0'); 
	InitBoard(show, ROWS, COLS, '*');
	//布置雷的位置（随机）
	setmine(mine, ROW, COL);
	//打印棋盘函数
	printboard(show, ROW, COL);
	
    //排查雷的函数
	findmine(mine, show, ROW, COL);

}
void test()
{
	int input = 0;
	srand(time(NULL));//随机数生成，保证布置雷的随机性
	do           
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:

			printf("游戏开始！\n");
			game();                      
			break;
		case 0:
			printf("游戏退出！\n");
			break;
		default:
			printf("输入错误！\n");
			break;
		}
	
	} while (input);
}
int main()
{
	test();
	return 0;
}