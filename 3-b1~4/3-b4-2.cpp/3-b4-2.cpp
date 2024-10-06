/*2352467 信08 赵阿强*/
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	cout << "请输入三角形的两边及夹角（角度）" << endl;
	int a = 0;
	int b = 0;
	int c = 0;
	const double pi = 3.14159;
	cin >> a >> b >> c;
	float s = 0;
	s = a * b * sin(c * pi / 180) / 2;
	cout << setiosflags(ios::fixed);
	cout << "三角形面积为 : " <<setprecision(3)<< s << endl;
	return 0;
}