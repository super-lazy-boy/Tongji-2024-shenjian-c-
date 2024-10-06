/*2352467 赵阿强 信08*/
#include<iostream>
#include<cmath> 
using namespace std;
void a_0();
void two_different_shigen();
void two_same_shigen();
void xugen();
double a = 0;
double b = 0;
double c = 0;
int main()
{
	double a = 0;
	double b = 0;
	double c = 0;
	cout << "请输入一元二次方程的三个系数a,b,c:" << endl;
	cin >> a >> b >> c;
	if (fabs(a) <= 1e-6)
		a_0();
	else {
		if (fabs(b * b - 4 * a * c) <= 1e-6)
			two_same_shigen();
		else if ((b * b - 4 * a * c) > 1e-6)
			two_different_shigen();
		else
			xugen();
	}
	return 0;
}