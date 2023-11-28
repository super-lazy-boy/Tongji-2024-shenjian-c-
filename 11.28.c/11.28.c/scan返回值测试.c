# define _CRT_SECURE_NO_WARNINGS 1
#include  <stdio.h> 
int main()
{
	int a = 0;
	int b = 0;
	float f = 0.0f;
	int r=scanf("%d %d %f", &a, &b, &f);
	printf("%d %d %f\n ", a, b, f);
	printf("%d\n", r);
	return 0;
}
