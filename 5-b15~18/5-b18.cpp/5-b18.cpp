/*2352467 赵阿强 信08*/
#include<iostream>
using namespace std;
int main() {
	while (cin.get() != '\n');
	int len = 0, big = 0, small = 0, num = 0, others = 0;
	cin >> len >> big >> small >> num >> others;
	getchar();//解决换行符
	if (cin.fail()) {
		cin.clear();
		cin.ignore(2147483647, '\n');
		cout << "输入非法" << endl;
		return 0;
	}
	if (len < 12 || len>16) {
		cout << "密码长度[" << len << "]不正确" << endl;
		return 0;
	}
	if (big<2 || big>len) {
		cout << "大写字母个数[" << big << "]不正确" << endl;
		return 0;
	}
	if (small<2 || small>len) {
		cout << "小写字母个数[" << small << "]不正确" << endl;
		return 0;
	}
	if (num<2 || num>len) {
		cout << "数字个数[" << num << "]不正确" << endl;
		return 0;
	}
	if (others<2 || others>len) {
		cout << "其他符号个数[" << others << "]不正确" << endl;
		return 0;
	}
	if (big + small + num + others > len)
	{
		cout << "所有字符类型之和[" << big << "+" << small << "+" << num << "+" << others << "]大于总密码长度[" << len << "]" << endl;
		return 0;
	}
	char key[10][17] = { 0 };
	int i = 0, j = 0;
	for (i = 0; i < 10; i++) {
		cin >> key[i];
	}
	int t = 0;
	for (i = 0; i < 10; i++) {
		int a = len;
		int b = big;
		int c = small;
		int d = num;
		int e = others;
		int leave = len - big - small - num - others;
		for (j = 0; j < len; j++) {
			if (key[i][j] >= 'A' && key[i][j] <= 'Z')
				b--;
			else if (key[i][j] >= 'a' && key[i][j] <= 'z')
				c--;
			else if (key[i][j] >= '0' && key[i][j] <= '9')
				d--;
			else
				for (int k = 0; k < 15; k++) {
					const char other[] = "!@#$%^&*-_=+,.?";
					if (key[i][j] == other[k])
						e--;
				}
		}
		if (b + c + d + e + leave != 0||b>0||c>0||d>0||e>0) {
			cout << "错误" << endl;
			t++;
			break;
		}
	}
	if(t==0)
	cout << "正确" << endl;
	return 0;
}