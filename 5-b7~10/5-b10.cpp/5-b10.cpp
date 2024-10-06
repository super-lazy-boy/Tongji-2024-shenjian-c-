/*2352467 赵阿强 信08*/
#include <iostream>
#include<limits>
#include<iomanip>
using namespace std;

int zeller(int y, int m,int d)
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
		for (; w < 0; w += 7);
			w = w % 7;
	return w;
}
void print_days( int year,int season,int month_days[12])
{
	int i = 0, j = 0, w = 0, k = 0;
	int months[3] = { 0 };
	int days_count[3] = { 0 };
	for (i = 0; i < 3; i++) {
		months[i] = month_days[3 * (season - 1) + i];
	}
	int days[3][42] = { 0 };
	int month = 0;
	for (i = 0;i<3; i++) {
		month = 3 * season - 2 + i;
		w = zeller(year, month, 1);
		for (j = w, k = 0; j < w + months[i]; j++, k++) {
			days[i][j] = k + 1;
		}
	}
	for (i = 0; i < 6;i++) {
		for (j = 0; j < 3; j++) {
			for (k = 7 * i; k < 7 * (i + 1); k++) {
				if (days[j][k] == 0)
					cout << setfill(' ') << setw(4) << setiosflags(ios::left) << " ";
				else
					cout << setfill(' ') << setw(4) << setiosflags(ios::left) << days[j][k];
			}
			cout << "    ";
		}
		cout << endl;
	}
}
void print_month(int n)
{
	cout << endl;
	int i = 0;
	for (i =1+3*( n-1); i < 4 + 3 * (n - 1); i++) {
		cout << setfill(' ') << setw(12) << " ";
		cout << i << "月";
		cout << setfill(' ') << setw(17) << " ";
	}
	cout << endl;
	for (i = 0; i < 3; i++) {
		cout << "Sun Mon Tue Wed Thu Fri Sat     ";
	}
	cout << endl;
}
int main()
{
	cout << "请输入年份[1900-2100]" << endl;
	int year = 0;
	while (1) {
		cin >> year;
		if (year >= 1900 && year <= 2100)
			break;
		else {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
	}
	bool leap = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
	int month_leap[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	int month_noleap[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	cout << year << "年的日历:" << endl;
	int i = 0;
	for (i = 1; i < 5; i++) {
		print_month(i);
		if (leap)
			print_days(year, i, month_leap);
		else
			print_days(year, i, month_noleap);
	}
}