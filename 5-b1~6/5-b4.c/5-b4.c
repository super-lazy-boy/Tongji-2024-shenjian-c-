/*2352467 信08 赵阿强*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	printf("请输入成绩（最多1000个），负数结束输入\n");
	int score[1000];
	int i = 0;
	for (i = 0; i < 1000; i++)//初始化为-1
		score[i] = -1;
	for (i = 0; i < 1000; i++)//输入数据
	{
		scanf("%d", &score[i]);
		if (score[i] < 0)
			break;
	}
printf("输入的数组为:\n");
int row = 0;
	for (i = 0; i < 1000; i++)//打印
	{
		if (score[i] >= 0) {
			if (row % 10 == 0 && row != 0)
				printf("\n");
			printf("%d ", score[i]);
		}
		else 
			break;
	}
	int mid = 0;
	int j = 0;
	for (i = 0; i <999; i++)//排序
	{
		for(j=0;j<=1000-(i+1);j++)
		if (score[j] < score[j + 1]) {
			mid = score[j];
			score[j] = score[j + 1];
			score[j + 1] = mid;
		}
	}
	
	printf("\n");
	printf("分数与人数的对应关系为:\n");
	int count = 1;
	for (i = 0; i < 1000; i++)
	{
		if (score[i] >= 0)
		{
			if (score[i] == score[i - 1]) {
				count++;
			}
			else {
				printf("%d %d\n", score[i], count);
				count = 1;
				continue;
			}
		}
		else
			break;
	}

	return 0;
}