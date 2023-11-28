#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int age = 0;
	scanf("%d", &age);
	if (age < 18)
		printf("少年\n");
	else if (age <= 44)
		printf("青年\n");
	else  if (age <= 59)
		printf("中老年\n");
	else if (age <= 89)
		printf("老年\n");
	else printf("老寿星\n");

	return 0;
}