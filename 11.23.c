#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	
	int a = 0;
	int b = 0;
	scanf("%d,%d", &a, &b);
	int c = 0;
	c = a / b;
	int d = 0;
	d = a % b;
	printf("%d,%d", c, d);
	return 0;
}