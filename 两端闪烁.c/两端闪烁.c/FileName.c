#define _CRT_SECURE_NO_NO_WARNINGS 1
# include <stdio.h>
#include <string.h>
#include<windows.h>
#include<stdlib.h>
int main()
{
	int left = 0;
	char arr1[] = "HELLO,WORLD";
	char arr2[] = "***********";
	int right = sizeof(arr1) / sizeof(arr1[0])-2;

	while (left<=right)
	{
		printf("%s\n", arr2);
		arr2[left] = arr1[left];
		arr2[right] = arr1[right];
		right--;
		left++;
		Sleep(1000);
		system("cls");
	}
	return 0;
}