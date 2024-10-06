/*2352467 赵阿强 信08*/
#include<iostream>
#include<cmath> 
using namespace std;
void xugen(double a, double b, double c)
{
	double shi = 0;//实数部分
	double xu = 0;//虚数部分
	cout << "有两个虚根：" << endl;
	shi = (-b) / (2 * a);
	xu = sqrt(4 * a * c - b * b) / (2 * a);
	if (fabs(shi) < 1e-6) {
		if (fabs(xu - 1) >= 1e-6 && xu >= 1e-6) {
			cout << "x1=" << "+" << xu << 'i' << endl;
			cout << "x2=" << "-" << xu << 'i' << endl;
		}
		else if (fabs(xu + 1) >= 1e-6 && xu <= -1e-6) {
			cout << "x1=" << -xu << 'i' << endl;
			cout << "x2=" << xu << 'i' << endl;
		}
		else if (fabs(xu - 1) < 1e-6 || fabs(xu + 1) < 1e-6) {
			cout << "x1=" << 'i' << endl;
			cout << "x2=" << "-i" << endl;
		}
	}
	else {
		if (fabs(xu - 1) >= 1e-6 && xu >= 1e-6) {
			cout << "x1=" << shi << "+" << xu << 'i' << endl;
			cout << "x2=" << shi << "-" << xu << 'i' << endl;
		}
		else if (fabs(xu + 1) >= 1e-6 && xu <= -1e-6) {
			cout << "x1=" << shi << "+" << -xu << 'i' << endl;
			cout << "x2=" << shi << xu << 'i' << endl;
		}
		else if (fabs(xu - 1) < 1e-6 || fabs(xu + 1) < 1e-6) {
			cout << "x1=" << shi << "+i" << endl;
			cout << "x2=" << shi << "-i" << endl;
		}
	}
}
