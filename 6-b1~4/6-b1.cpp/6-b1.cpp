/* 2352467 赵阿强 信08 */
#include <iostream>
#include<cstring>
using namespace std;

#define  N  10	/* 假设最多转换10个数字 */

/* 不允许再定义其它函数、全局变量 */

int main()
{
	/* 如果有不需要的变量，允许删除，但不允许添加或替换为其它类型的变量 */
	char str[256], *p;
	int  a[N] = { 0 }, *pnum, *pa;


	/* 上面的定义不准动(删除不需要的变量除外)，下面为程序的具体实现，要求不得再定义任何变量、常量、常变量 */
	cout << "请输入间隔含有若干正负数字的字符串" << endl;
	pa = a;
	pnum = a;
	gets_s(str);
	for (p=str; *p >= 32 && *p <= 126; p++) {
		for (; *p >= '0' && *p <= '9'&&(pa-pnum)<=10; p++) {
			*pa = *pa * 10 + *p-48;
		}
		p--;
		if (*p >= '0' && *p <= '9'&& (pa - pnum) <=10) {
			pa++;
		}
		p++;
	}
	cout << "共" << (pa - pnum) << "个整数" << endl;
	for (int i = 0; i < (pa - pnum); i++) {
		cout << a[i]<<" ";
	}
	cout << endl;
	return 0;
}