/*2352467 赵阿强 信08*/
#include<iostream>
#include<cmath> 
using namespace std;
void two_different_shigen(double a, double b, double c)
{
	double x1 = 0;
	double x2 = 0;
	cout << "有两个不等实根：" << endl;
	x1 = ((-b) + sqrt(b * b - 4 * a * c)) / (2 * a);
	x2 = ((-b) - sqrt(b * b - 4 * a * c)) / (2 * a);
	if (fabs(x1) <= 1e-6)
		x1 = 0;
	if (fabs(x2) <= 1e-6)
		x2 = 0;
	cout << "x1=" << x1 << endl;
	cout << "x2=" << x2 << endl;
}
