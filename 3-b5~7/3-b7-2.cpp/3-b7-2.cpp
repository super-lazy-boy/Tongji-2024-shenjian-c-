/*2352467 信08 赵阿强*/
#include<iostream>
using namespace std;
int main()
{
	cout << "请输入找零值：\n" << endl;
	double money = 0;
	cin >> money;
	int count = 0;
	int fifty = 0;
	int twenty = 0;
	int ten = 0;
	int five = 0;
	int one = 0;
	int wujiao = 0;
	int yijiao = 0;
	int wufen = 0;
	int liangfen = 0;
	int imoney = (int)(money * 100);
	switch (imoney / 5000) {
	case 1:
		count++;
		fifty++;
		imoney -= 5000;
		break;
	case 0:
		break;
	}
	switch (imoney / 2000) {
	case 2:
		count += 2;
		twenty += 2;
		imoney -= 2 * 2000;
		break;
	case 1:
		count++;
		twenty++;
		imoney -= 2000;
		break;
	case 0:
		break;
	}
	switch (imoney / 1000) {
	case 1:
		count++;
		ten++;
		imoney -= 1000;
		break;
	case 0:
		break;
	}
	switch (imoney / 500) {
	case 1:
		count++;
		five++;
		imoney -= 500;
		break;
	case 0:
		break;
	}
	switch (imoney / 100) {
	case 4:
		imoney -= 400;
		one += 4;
		count += 4;
		break;
	case 3:
		imoney -= 300;
		one += 3;
		count += 3;
		break;
	case 2:
		imoney -= 200;
		one += 2;
		count += 2;
		break;
	case 1:
		imoney -= 100;
		one += 1;
		count += 1;
		break;
	case 0:
		break;
	}
	switch (imoney / 50) {
	case 1:
		count++;
		imoney -= 50;
		wujiao++;
		break;
	case 0:
		break;
	}
	switch (imoney / 10) {
	case 4:
		count += 4;
		imoney -= 40;
		yijiao += 4;
		break;
	case 3:
		count += 3;
		imoney -= 30;
		yijiao += 3;
		break;
	case 2:
		count += 2;
		imoney -= 20;
		yijiao += 2;
		break;
	case 1:
		count += 1;
		imoney -= 10;
		yijiao += 1;
		break;
	case 0:
		break;
	}
	switch (imoney / 5) {
	case 1:
		imoney -= 5;
		count++;
		wufen++;
		break;
	case 0:
		break;
	}
	switch (imoney / 2) {
	case 2:
		imoney -= 4;
		count += 2;
		liangfen += 2;
		break;
	case 1:
		imoney -= 2;
		count++;
		liangfen++;
		break;
	case 0:
		break;
	}
	count += imoney;
	cout << "共" << count << "张找零，具体如下：" << endl;
	if (fifty != 0)
		cout << "50元 : " << fifty << "张" << endl;
	if (twenty != 0)
		cout << "20元 : " << twenty << "张" << endl;
	if (ten != 0)
		cout << "10元 : " << ten << "张" << endl;
	if (five != 0)
		cout << "5元  : " << five << "张" << endl;
	if (one != 0)
		cout << "1元  : " << one << "张" << endl;
	if (wujiao != 0)
		cout << "5角  : " << wujiao  << "张" << endl;
	if (yijiao != 0)
		cout << "1角  : " << yijiao << "张" << endl;
	if (wufen != 0)
		cout << "5分  : " << wufen << "张" << endl;
	if (liangfen != 0)
		cout << "2分  : " << liangfen << "张" << endl;
	if (imoney != 0)
		cout << "1分  : " << imoney << "张" << endl;
	return 0;
}