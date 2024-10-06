/*2352467 信08 赵阿强*/
#include<iostream>
using namespace std;
int main()
{
	cout << "请输入[0-100亿）之间的数字:\n" ;
	double num = 0;
	cin >> num;
	int a = 0;
	double c = 1e9;
	num = num + 0.005;
	a = (int)(num / c);
	cout << "十亿位 : " << a << endl;
	num = num - a * c;
	c /= 10;
	a = (int)(num / c);
	cout << "亿位   : " << a << endl;
	num = num - a * c;
	c /= 10;
	a = (int)(num / c);
	cout << "千万位 : " << a << endl;
	num = num - a * c;
	c /= 10;
	a = (int)(num / c);
	cout << "百万位 : " << a << endl;
	num = num - a * c;
	c /= 10;
	a = (int)(num / c);
	cout << "十万位 : " << a << endl;
	num = num - a * c;
	c /= 10;
	a = (int)(num / c);
	cout << "万位   : " << a << endl;
	num = num - a * c;
	c /= 10;
	a = (int)(num / c);
	cout << "千位   : " << a << endl;
	num = num - a * c;
	c /= 10;
	a = (int)(num / c);
	cout << "百位   : " << a << endl;
	num = num - a * c;
	c /= 10;
	a = (int)(num / c);
	cout << "十位   : " << a << endl;
	num = num - a * c;
	c /= 10;
	a = (int)(num / c);
	cout << "圆     : " << a << endl;
	num = num - a * c;
	c /= 10;
	a = (int)(num / c);
	cout << "角     : " << a << endl;
	num = num - a * c;
	c /= 10;
	a = (int)(num / c);
	cout << "分     : " << a << endl;
	return 0;
}