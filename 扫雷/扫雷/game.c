#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
#include<stdio.h>

void InitBoard(char board[ROWS][COLS], int rows, int cols,char set)
{
	int i = 0;
	for (i = 0; i < rows;i++)
	{
		int j = 0;
		for (j = 0;j < cols; j++)
		{
			board[i][j] = set;
		}
	}

}
void printboard(char arr[ROWS][COLS], int row, int col)
{
	printf("-----扫雷开始-----\n");
	int i = 0;
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row;i++)
	{
		int j = 0;
		printf("%d ", i);
		for (j = 1; j <= col;j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
}

void setmine(char arr[ROWS][COLS], int row, int col)
{
	int count = easycount;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (arr[x][y] == '0')
		{
			arr[x][y] = '1';
			count--; 
		}
	}
}
static int get_mine_count(char arr[ROWS][COLS], int x, int y)
{
	int count = 0;
	int i = 0;
		for (i= x - 1;i <=x + 1;i++)
		{
			int j = 0;
			for (j= y - 1; j <=y + 1;j++)
			{
				count += arr[i][j];
			}
		}
	count = count - 9 * '0';
	return count;
}
void findmine(char arr[ROWS][COLS], char arr2[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win<row+col-easycount)
	{
		printf("请输入你要排查的坐标：");
		scanf("%d %d", &x, &y);
		//判断坐标的合理性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (arr2[x][y] == '*')
			{
				if (arr[x][y] == '1')
				{
					printf("不好意思，你被炸死了！\n");
					printboard(arr, ROW, COL);
					break;
				}
				else
				{
					int count = get_mine_count(arr, x, y);
					arr2[x][y] = count + '0';
					printboard(arr2, ROW, COL);
					win++;
				}
			}
			else
			{
				printf("该坐标已经被排查，重新输入坐标\n");
			}
		}
		else
		{
			printf("坐标非法！\n");
		}
	}
    if (win == row * col - easycount)
    {
	    printf("恭喜你，排雷成功\n");
	    printboard(arr[ROWS][COLS], ROW, COL);
     }  
}
