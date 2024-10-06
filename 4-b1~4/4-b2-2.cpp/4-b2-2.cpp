/* 2352467 赵阿强 信08 */
#include<iostream>
#include<limits> 
using namespace std;
int day_max( int y,int m)
{
	bool leap = ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0));
	int days = 0;
	switch (m)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		days = 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		days = 30;
		break;
	case 2:
		if (leap) {
			days = 29;
			break;
		}
		else {
			days = 28;
			break;
		}
	}
	return days;
}
int zeller( int y, int m, int d)
{
	int c = 0;
	if (m <= 2)
	{
		m += 12;
		y--;
		c = y / 100;
		y = y % 100;
	}
	else {
		c = y / 100;
		y = y % 100;
	}
	int w = 0;
	w = y + y / 4 + c / 4 - 2 * c + 13 * (m + 1) / 5 + d - 1;
	if (w < 0)
		for (; w < 0; w += 7)
			w = w % 7;
	return w;
}

int main()
{
	int w = 0, c = 0, y = 0, m = 0, d = 0,days=0;
	while (1) {
		cout << "请输入年[1900-2100]、月、日：" << endl;
		cin >> y >> m >> d;
		days = day_max(y, m);
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "输入错误，请重新输入" << endl;
			continue;
		}
		else {
			if (y < 1900 || y>2100) {
				cout << "年份不正确，请重新输入" << endl;
				continue;
			}
			if (m < 1 || m>12) {
				cout << "月份不正确，请重新输入" << endl;
				continue;
			}
			if (d<1 || d>days) {
				cout << "日不正确，请重新输入" << endl;
				continue;
			}
		}
		break;
	}
	w = zeller( y, m, d);
	switch (w) {
	case 1:
		cout << "星期一" << endl;
		break;
	case 2:
		cout << "星期二" << endl;
		break;
	case 3:
		cout << "星期三" << endl;
		break;
	case 4:
		cout << "星期四" << endl;
		break;
	case 5:
		cout << "星期五" << endl;
		break;
	case 6:
		cout << "星期六" << endl;
		break;
	case 0:
		cout << "星期日" << endl;
		break;
	}
	return 0;
}
