#define _CET_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0]) - 1;
	int mid = 0;
	int find = 0;
	srand((unsigned int)time(NULL));
	int key = rand() % 10 + 1;           //设置所要找的数为十以内的随机数
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (arr[mid] < key)
			left = mid + 1;
		else if (arr[mid] > key)
			right = mid - 1;
		else
		{
			find = arr[mid];
			printf("要找的数是%d", find);
			break;
		}
	}
	return 0;
}