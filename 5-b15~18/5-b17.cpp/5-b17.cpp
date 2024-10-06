/*2352467 赵阿强 信08*/
#include<iostream>
#include<time.h>
using namespace std;
void keys(const int a, int b, int c, int d, int e)
{
	char key[10][16] = { 0 };
	int place = 0;

	for (int i = 0; i < 10; i++) {
		int len = a;
		int big = b;
		int small = c;
		int num = d;
		int others = e;
		int leave = len - big - small - num - others;
		while (big) {
			place = rand() % len;
			if (key[i][place] == 0) {
				key[i][place] = char(rand() % 26 + 65);
				big--;
			}
		}
		while (small) {
			place = rand() % len;
			if (key[i][place] == 0) {
				key[i][place] = char(rand() % 26 + 97);
				small--;
			}
		}
		while (num) {
			place = rand() % len;
			if (key[i][place] == 0) {
				key[i][place] = char(rand() % 10 + 48);
				num--;
			}
		}
		const char other[] = "!@#$%^&*-_=+,.?";
		while (others) {
			place = rand() % len;
			if (key[i][place] == 0) {
				key[i][place] = other[rand() % 15];
				others--;
			}
		}
		while (leave) {
			place = rand() % len;
			if (key[i][place] == 0) {
				key[i][place] = char(rand() % 94 + 33);
				leave--;
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < a; j++) {
			cout << key[i][j];
		}
		cout << endl;
	}
}
int main()
{
	srand((unsigned)time(NULL));
	cout << "请输入密码长度(12-16)，大写字母个数(≥2)，小写字母个数(≥2)，数字个数(≥2)，其它符号个数(≥2)" << endl;
	int len=0, big=0, small=0, num=0, others=0;
	cin >> len >>big >> small >> num >> others;
	int t = 0;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(2147483647, '\n');
		cout << "输入非法" << endl;
		return 0;
	}
	else {
		if (len < 12 || len>16) {
			cout << "密码长度[" << len << "]不正确" << endl;
			return 0;
		}
		else if (big<2 || big>len) {
			cout << "大写字母个数[" << big << "]不正确" << endl;
			return 0;
		}
		else if (small<2 || small>len) {
			cout << "小写字母个数[" << small << "]不正确" << endl;
			return 0;
		}
		else if (num<2 || num>len) {
			cout << "数字个数[" << num << "]不正确" << endl;
			return 0;
		}
		else if (others<2 || others>len) {
			cout << "其他符号个数[" << others << "]不正确" << endl;
			return 0;
		}
		else if (big + small + num + others > len)
		{
			cout << "所有字符类型之和[" << big << "+" << small << "+" << num << "+" << others << "]大于总密码长度[" << len << "]" << endl;
			return 0;
		}
		else {
			cout << len << " " << big << " " << small << " " << num << " " << others << endl;
			keys(len, big, small, num, others);
			return 0;
		}
	}

}