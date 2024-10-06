/* 2352467 赵阿强 信08 */
#include <iostream>
#include<cmath>
using namespace std;
int main()
{
	char num2[33] = { 0 },*pnum2,*stay;
	cout << "请输入一个0/1组成的字符串，长度不超过32" << endl;
	cin >> num2;
	unsigned int num = 0,*pnum;

	pnum2 = num2;
	pnum = &num;
	stay = &num2[strlen(num2)-1];
	for (;  *pnum2!='\0'; pnum2++) {
		*pnum += (*pnum2 - 48) * pow(2, stay-pnum2);
	}
	cout << num << endl;
	return 0;
}