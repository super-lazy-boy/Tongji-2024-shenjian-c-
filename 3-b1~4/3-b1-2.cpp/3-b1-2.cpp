/*2352467 信08 赵阿强*/
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	double r, h;
	cout << "请输入半径和高度" << endl;
	cin >> r >> h;
	const double pi = 3.14159;
	cout << setiosflags(ios::fixed);
	cout <<setprecision(2) << "圆周长     : " << 2 * pi * r << endl;
	cout << setprecision(2) << "圆面积     : " << pi * r * r << endl;
	cout << setprecision(2) << "圆球表面积 : " << 4 * pi * r * r << endl;
	cout << setprecision(2) << "圆球体积   : " << 4 * pi * r * r * r / 3 << endl;
	cout << setprecision(2) << "圆柱体积   : " << pi * r * r * h << endl;

	return 0;
}
