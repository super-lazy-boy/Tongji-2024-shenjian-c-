/*2352467 ĞÅ08 ÕÔ°¢Ç¿*/
#include<iostream>
using namespace std;
int main()
{
	cout << "ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊı×Ö:" << endl;
	double num;
	cin>>num;
	int a, b, d, e, f, g, h, i, j, k, l, m;
	double c = 1e9;
	double num1 = 0;//´´½¨ÓÃÓÚ±È½ÏÇ°ÃæÊÇ·ñÓĞÁã
	num1 = num = num + 0.005;
	int count = 0;
	count = a = (int)(num / c);
	num = num - a * c;
	c /= 10;
	b = (int)(num / c);
	num = num - b * c;
	c /= 10;
	d = (int)(num / c);
	num = num - d * c;
	c /= 10;
	e = (int)(num / c);
	num = num - e * c;
	c /= 10;
	f = (int)(num / c);
	num = num - f * c;
	c /= 10;
	g = (int)(num / c);
	num = num - g * c;
	c /= 10;
	h = (int)(num / c);
	num = num - h * c;
	c /= 10;
	i = (int)(num / c);
	num = num - i * c;
	c /= 10;
	j = (int)(num / c);
	num = num - j * c;
	c /= 10;
	k = (int)(num / c);
	num = num - k * c;
	c /= 10;
	l = (int)(num / c);
	num = num - l * c;
	c /= 10;
	m = (int)(num / c);
	cout<<"´óĞ´½á¹ûÊÇ:" << endl;
	if (a != 0) {
		switch (a) {
		case 1:
			cout<<"Ò¼";
			break;
		case 2:
			cout<<"·¡";
			break;
		case 3:
			cout<<"Èş";
			break;
		case 4:
			cout<<"ËÁ";
			break;
		case 5:
			cout<<"Îé";
			break;
		case 6:
			cout<<"Â½";
			break;
		case 7:
			cout<<"Æâ";
			break;
		case 8:
			cout<<"°Æ";
			break;
		case 9:
			cout<<"¾Á";
			break;
		case 0:
			cout<<"Áã";
			break;
		}
		cout<<"Ê°";
	}
	if (b != 0) {
		switch (b) {
		case 1:
			cout << "Ò¼";
			break;
		case 2:
			cout << "·¡";
			break;
		case 3:
			cout << "Èş";
			break;
		case 4:
			cout << "ËÁ";
			break;
		case 5:
			cout << "Îé";
			break;
		case 6:
			cout << "Â½";
			break;
		case 7:
			cout << "Æâ";
			break;
		case 8:
			cout << "°Æ";
			break;
		case 9:
			cout << "¾Á";
			break;
		case 0:
			cout << "Áã";
			break;
		}
	}
	if (b != 0 || count != 0) {
		cout<<"ÒÚ";
	}

	switch (d) {
	case 1:
		cout<<"Ò¼Çª";
		break;
	case 2:
		cout<<"·¡Çª";
		break;
	case 3:
		cout<<"ÈşÇª";
		break;
	case 4:
		cout<<"ËÁÇª";
		break;
	case 5:
		cout<<"ÎéÇª";
		break;
	case 6:
		cout<<"Â½Çª";
		break;
	case 7:
		cout<<"ÆâÇª";
		break;
	case 8:
		cout<<"°ÆÇª";
		break;
	case 9:
		cout<<"¾ÁÇª";
		break;
	case 0:
		if (num1 >= 1e8 && (e != 0 || f != 0 || g != 0))
			cout<<"Áã";
		break;
	}
	switch (e) {
	case 1:
		cout<<"Ò¼°Û";
		break;
	case 2:
		cout<<"·¡°Û";
		break;
	case 3:
		cout<<"Èş°Û";
		break;
	case 4:
		cout<<"ËÁ°Û";
		break;
	case 5:
		cout<<"Îé°Û";
		break;
	case 6:
		cout<<"Â½°Û";
		break;
	case 7:
		cout<<"Æâ°Û";
		break;
	case 8:
		cout<<"°Æ°Û";
		break;
	case 9:
		cout<<"¾Á°Û";
		break;
	case 0:
		if (d != 0 &&( f != 0 || g != 0))
			cout<<"Áã";
		break;
	}
	switch (f) {
	case 1:
		cout<<"Ò¼Ê°";
		break;
	case 2:
		cout<<"·¡Ê°";
		break;
	case 3:
		cout<<"ÈşÊ°";
		break;
	case 4:
		cout<<"ËÁÊ°";
		break;
	case 5:
		cout<<"ÎéÊ°";
		break;
	case 6:
		cout<<"Â½Ê°";
		break;
	case 7:
		cout<<"ÆâÊ°";
		break;
	case 8:
		cout<<"°ÆÊ°";
		break;
	case 9:
		cout<<"¾ÁÊ°";
		break;
	case 0:
		if (e != 0 && g != 0)
			cout<<"Áã";
		break;
	}
	switch (g) {
	case 1:
		cout << "Ò¼";
		break;
	case 2:
		cout << "·¡";
		break;
	case 3:
		cout << "Èş";
		break;
	case 4:
		cout << "ËÁ";
		break;
	case 5:
		cout << "Îé";
		break;
	case 6:
		cout << "Â½";
		break;
	case 7:
		cout << "Æâ";
		break;
	case 8:
		cout << "°Æ";
		break;
	case 9:
		cout << "¾Á";
		break;
	case 0:
		break;
	}
	if (d != 0 || e != 0 || f != 0 || g != 0)
		cout<<"Íò";

	switch (h) {
	case 1:
		cout << "Ò¼Çª";
		break;
	case 2:
		cout << "·¡Çª";
		break;
	case 3:
		cout << "ÈşÇª";
		break;
	case 4:
		cout << "ËÁÇª";
		break;
	case 5:
		cout << "ÎéÇª";
		break;
	case 6:
		cout << "Â½Çª";
		break;
	case 7:
		cout << "ÆâÇª";
		break;
	case 8:
		cout << "°ÆÇª";
		break;
	case 9:
		cout << "¾ÁÇª";
		break;
	case 0:
		if ((num1 >= 10000) && (i != 0 || j != 0 || k != 0))
			cout<<"Áã";
		break;
	}
	switch (i) {
	case 1:
		cout << "Ò¼°Û";
		break;
	case 2:
		cout << "·¡°Û";
		break;
	case 3:
		cout << "Èş°Û";
		break;
	case 4:
		cout << "ËÁ°Û";
		break;
	case 5:
		cout << "Îé°Û";
		break;
	case 6:
		cout << "Â½°Û";
		break;
	case 7:
		cout << "Æâ°Û";
		break;
	case 8:
		cout << "°Æ°Û";
		break;
	case 9:
		cout << "¾Á°Û";
		break;
	case 0:
		if (h != 0 && (j != 0 || k != 0))
			cout<<"Áã";
		break;
	}
	switch (j) {
	case 1:
		cout << "Ò¼Ê°";
		break;
	case 2:
		cout << "·¡Ê°";
		break;
	case 3:
		cout << "ÈşÊ°";
		break;
	case 4:
		cout << "ËÁÊ°";
		break;
	case 5:
		cout << "ÎéÊ°";
		break;
	case 6:
		cout << "Â½Ê°";
		break;
	case 7:
		cout << "ÆâÊ°";
		break;
	case 8:
		cout << "°ÆÊ°";
		break;
	case 9:
		cout << "¾ÁÊ°";
		break;
	case 0:
		if (i != 0 && k != 0)
			cout<<"Áã";
		break;
	}
	switch (k) {
	case 1:
		cout<<"Ò¼";
		break;
	case 2:
		cout<<"·¡";
		break;
	case 3:
		cout<<"Èş";
		break;
	case 4:
		cout<<"ËÁ";
		break;
	case 5:
		cout<<"Îé";
		break;
	case 6:
		cout<<"Â½";
		break;
	case 7:
		cout<<"Æâ";
		break;
	case 8:
		cout<<"°Æ";
		break;
	case 9:
		cout<<"¾Á";
		break;
	case 0:
		break;
	}
	if (num1 >= 1)
		cout<<"Ô²";
	switch (l) {
	case 1:
		cout<<"Ò¼½Ç";
		break;
	case 2:
		cout<<"·¡½Ç";
		break;
	case 3:
		cout<<"Èş½Ç";
		break;
	case 4:
		cout<<"ËÁ½Ç";
		break;
	case 5:
		cout<<"Îé½Ç";
		break;
	case 6:
		cout<<"Â½½Ç";
		break;
	case 7:
		cout<<"Æâ½Ç";
		break;
	case 8:
		cout<<"°Æ½Ç";
		break;
	case 9:
		cout<<"¾Á½Ç";
		break;
	case 0:
		if (num1 >= 1 && m != 0)
			cout<<"Áã";
		break;
	}
	switch (m) {
	case 1:
		cout<<"Ò¼·Ö";
		break;
	case 2:
		cout<<"·¡·Ö";
		break;
	case 3:
		cout<<"Èş·Ö";
		break;
	case 4:
		cout<<"ËÁ·Ö";
		break;
	case 5:
		cout<<"Îé·Ö";
		break;
	case 6:
		cout<<"Â½·Ö";
		break;
	case 7:
		cout<<"Æâ·Ö";
		break;
	case 8:
		cout<<"°Æ·Ö";
		break;
	case 9:
		cout<<"¾Á·Ö";
		break;
	case 0:
		if (num1 >= 0.1 && m != 0)
			cout<<"Áã";
		break;
	}
	if (num1 - 0.005 == 0)
		cout<<"ÁãÔ²Õû";
	else if (m == 0 || (m == 0 && l == 0))
		cout<<"Õû";
	else;

	cout << endl;
	return 0;
}