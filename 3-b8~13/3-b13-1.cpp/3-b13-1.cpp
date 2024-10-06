/* 信08 2352467 赵阿强*/
#include<iostream>
#include<limits>
#include<iomanip>
using namespace std;
int main()
{
	int year = 0;
	int month = 0;
	int week = 0;
	while (1) {
		cout << "请输入年份(2000-2030)和月份(1-12) : ";
		cin >> year >> month ;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "输入非法，请重新输入" << endl;
			continue;
		}
		if (month < 1 || month>12 || year < 2000 || year>2030)
		{
			cin.clear();
			cout << "输入非法，请重新输入" << endl;
			continue;
		}
		break;
	}
	while (1)
	{
		cout << "请输入" << year << "年" << month << "月1日的星期(0-6表示星期日-星期六) : ";
		cin >> week;
		if (cin.fail()||week<0||week>6)
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "输入非法，请重新输入" << endl;
			continue;
		}
		break;
	}
	cout << endl;
	cout << year << "年" << month << "月的月历为:" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
	int row = 0;
	while(week>0)
	{
		cout << "        ";
		row += 8;
		week--;
	}
	bool leap = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
	int days=0;
	switch (month)
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
	int count = 1;
	for (count; count <= days; count++)
	{
		cout << "  " << setw(2) << setiosflags(ios::right) << count << "  ";
		cout << "  ";
		row += 8;
		if (row == 56) {
			row -= 56;
			cout << endl;
		}
	}
	
}