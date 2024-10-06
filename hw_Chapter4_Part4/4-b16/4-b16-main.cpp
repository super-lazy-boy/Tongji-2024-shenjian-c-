/*2352467 赵阿强 信08*/
#include<iostream>
using namespace std;
#include"4-b16.h"
int main()
{
	double a = 0;
	double b = 0;
	double c = 0;
	cout << "请输入一元二次方程的三个系数a,b,c:" << endl;
	cin >> a >> b >> c;
	if (fabs(a) <= 1e-6)
		a_0(a, b, c);
	else {
		if (fabs(b * b - 4 * a * c) <= 1e-6)
			two_same_shigen(a, b, c);
		else if ((b * b - 4 * a * c) > 1e-6)
			two_different_shigen(a, b, c);
		else
			xugen(a, b, c);
	}
	return 0;
}
