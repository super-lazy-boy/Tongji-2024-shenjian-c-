/*2352467 信08 赵阿强*/
#include<iostream>
using namespace std;
int main()
{
	cout << "请输入年，月，日" << endl;
	int year, month, day;
	cin >> year >> month >> day;
	bool leap = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
	switch (month) {
	case 1:
		if (day > 31 || day <= 0)
			cout << "输出错误-日与月的关系非法" << endl;
		else
			cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day << "天" << endl;
		break;
	case 3:
	case 5:
	case 7:
		if (day > 31 || day <= 0)
			cout << "输出错误-日与月的关系非法" << endl;
		else {
			if (leap)
				cout << year << "-" << month << "-" << day << "是" << year << "年的第" << 60 + (month - 3) * 61 / 2 + day << "天" << endl;
			else
				cout << year << "-" << month << "-" << day << "是" << year << "年的第" << 59 + (month - 3) * 61 / 2 + day << "天" << endl;
		}
		break;
	case 8:
	case 10:
	case 12:
		if (day > 31 || day <= 0)
			cout << "输出错误-日与月的关系非法" << endl;
		else {
			if (leap)
				cout << year << "-" << month << "-" << day << "是" << year << "年的第" << 213 + (month / 2 - 4) * 61 + day << "天" << endl;
			else
				cout << year << "-" << month << "-" << day << "是" << year << "年的第" << 212 + (month / 2 - 4) * 61 + day << "天" << endl;
		}
		break;
	case 4:
	case 6:
		if (day <= 0 || day > 30)
			cout << "输出错误-日与月的关系非法" << endl;
		else {
			if (leap)
				cout << year << "-" << month << "-" << day << "是" << year << "年的第" << 91 + (month / 2 - 2) * 61 + day << "天" << endl;
			else
				cout << year << "-" << month << "-" << day << "是" << year << "年的第" << 90 + (month / 2 - 2) * 61 + day << "天" << endl;
		}
		break;
	case 9:
	case 11:
		if (day <= 0 || day > 30)
			cout << "输出错误-日与月的关系非法" << endl;
		else {
			if (leap)
				cout << year << "-" << month << "-" << day << "是" << year << "年的第" << 244 + (month - 9) * 61 / 2 + day << "天" << endl;
			else
				cout << year << "-" << month << "-" << day << "是" << year << "年的第" << 243 + (month - 9) * 61 / 2 + day << "天" << endl;
		}
		break;
	case 2:
		if (leap && (day < 0 || day>29))
			cout << "输出错误-日与月的关系非法" << endl;
		else if (day > 28 || day < 0)
			cout << "输出错误-日与月的关系非法" << endl;
		else
			cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day+31 << "天" << endl;
		break;
	default:
		cout << "输入错误-月份不正确" << endl;
		break;
	}
	return 0;
}