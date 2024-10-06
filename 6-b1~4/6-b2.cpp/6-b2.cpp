/* 2352467 赵阿强 信08 */
#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char str[81] = { 0 },*p1,*p2;//最后一位是留给\0
	cout << "请输入一个长度小于80的字符串（回文串）" << endl;
	int judge = 0,*pjudge;

	pjudge = &judge;

	fgets(str, 80,stdin);
	p1 = &str[0];
	p2 = &str[strlen(str) - 2];
	for (; p1<p2; p1++,p2--) {
		if (*p1 != *p2) {
			judge++;
			break;
		}
	}
	if (judge == 0)
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	return 0;
}