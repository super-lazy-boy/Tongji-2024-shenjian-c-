/*2352467 信08 赵阿强*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	printf("请输入[0-100亿）之间的数字:\n");
	double num = 0;
	scanf("%lf", &num);
	/*printf("十亿位 : %d\n", (int)(num / 1e9) );
	printf("亿位   : %d\n", (int)(num / 1e8  )- (int)(num / 1e9) * 10);
	printf("千万位 : %d\n", (int)(num / 1e7  )- (int)(num / 1e8) * 10);
	printf("百万位 : %d\n", (int)(num / 1e6  )- (int)(num / 1e7) * 10);
	printf("十万位 : %d\n", (int)(num / 1e5  )- (int)(num / 1e6) * 10);
	printf("万位   : %d\n", (int)(num / 1e4  )- (int)(num / 1e5) * 10);
	printf("千位   : %d\n", (int)(num / 1e3  )- (int)(num / 1e4) * 10);
	printf("百位   : %d\n", (int)(num / 1e2  )- (int)(num / 1e3) * 10);
	printf("十位   : %d\n", (int)(num / 10  )- (int)(num / 1e2) * 10);
	printf("圆     : %d\n",(int) ((num - (int)(num / 1e5) * 1e5) - (int)((num - (int)(num / 1e5) * 1e5) / 10) * 10));
	printf("角     : %lf\n", num /0.1);
	printf("分     : %lf\n", num / 1000000000 - 0.5 - (int)(num / 1000000000 - 0.5));*/
	int a = 0;
	double c = 1e9;
	num = num + 0.005;
	a = (int)(num / c);
	printf("十亿位 : %d\n", a);
	num = num - a * c;
	c /= 10;
	a = (int)(num / c);
	printf("亿位   : %d\n", a);
	num = num - a * c;
	c /= 10;
	a = (int)(num / c);
	printf("千万位 : %d\n", a);
	num = num - a * c;
	c /= 10;
	a = (int)(num / c);
	printf("百万位 : %d\n", a);
	num = num - a * c;
	c /= 10;
	a = (int)(num / c);;
	printf("十万位 : %d\n", a);
	num = num - a * c;
	c /= 10;
	a = (int)(num / c);
	printf("万位   : %d\n", a);
	num = num - a * c;
	c /= 10;
	a = (int)(num / c);
	printf("千位   : %d\n", a);
	num = num - a * c;
	c /= 10;
	a = (int)(num / c);
	printf("百位   : %d\n", a);
	num = num - a * c;
	c /= 10;
	a = (int)(num / c);
	printf("十位   : %d\n", a);
	num = num - a * c;
	c /= 10;
	a = (int)(num / c);
	printf("圆     : %d\n", a);
	num = num - a * c;
	c /= 10;
	a = (int)(num /c);
	printf("角     : %d\n", a);
	num = num - a * c;
	c /= 10;
	a = (int)(num / c);
	printf("分     : %d\n", a);
	return 0;
}

