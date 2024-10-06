/* 信08 2352467 赵阿强 */
/*2354088 万子恒 2353125 郑凯博 2352468 李姝 2350219 朱鸿杰 2351277 汪志贤*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define row 10
#define col 26

int main()
{
	char o[row][col] = { 0 };
	int i = 0, j = 0;
	for (i = 0; i <  row ; i++) {
		for (j = 0; j < col; j++) {
			scanf("%c", &o[i][j]);
			while ((o[i][j] < '0' || o[i][j]>'8') && o[i][j] != '*')
			{
				o[i][j] = getchar();
			}
		}
	}
	char test[row + 1][col + 1] = { '0'};
	for (i = 1; i < row + 1; i++) {
		for (j = 1; j < col + 1; j++) {
			test[i][j] = o[i - 1][j - 1];
		}
	}
	int count = 0;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			if (o[i][j] == '*')
				count++;
		}
	}
	int judge = 0;
	int x = 0, y = 0;
	for (i = 1; i < row + 1; i++) {
		for (j = 1; j < col + 1; j++) {
			if (test[i][j] != '*') {
				int num = 0;
				for (x = 0; x < 3; x++) {
					for (y = 0; y < 3; y++) {
						if (test[i - 1 + x][j - 1 + y] == '*')
							num++;
					}
				}
				if (test[i][j] - 48 != num)
					judge++;
			}
		}
	}
	if (judge == 0 && count == 50)
		printf("正确\n");
	else if (count != 50 && judge == 0)
		printf("错误1\n");
	else
		printf("错误2\n");
	return 0;
}