/*пе08 2352467 ут╟╒г©*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int i, j,num;
	for (i = 1; i <= 9; i++)
	{
		for (j = 1; j <= i; j++)
		{
			num = i * j;
			printf("%dx%d=%d", j, i, num);
			if (num < 10)
				printf("   ");
			else
				printf("  ");
		}
		printf("\n");
	}
	printf("\n");
	return 0;
}