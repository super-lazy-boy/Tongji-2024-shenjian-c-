/*2352467 �԰�ǿ ��08*/
#include<iostream>
#include<cmath> 
using namespace std;
void a_0(double a,double b,double c)
{
	cout << "����һԪ���η���" << endl;
}
void two_different_shigen(double a, double b, double c)
{
	double x1 = 0;
	double x2 = 0;
	cout << "����������ʵ����" << endl;
	x1 = ((-b) + sqrt(b * b - 4 * a * c)) / (2 * a);
	x2 = ((-b) - sqrt(b * b - 4 * a * c)) / (2 * a);
	if (fabs(x1) <= 1e-6)
		x1 = 0;
	if (fabs(x2) <= 1e-6)
		x2 = 0;
	cout << "x1=" << x1 << endl;
	cout << "x2=" << x2 << endl;
}
void two_same_shigen(double a, double b, double c)
{
	double x1 = 0;
	double x2 = 0;
	x1 = x2 = (-b) / (2 * a);
	if (fabs(x1) <= 1e-6)
		x1 = 0;
	if (fabs(x2) <= 1e-6)
		x2 = 0;
	cout << "���������ʵ����" << endl;
	cout << "x1=x2=" << x1 << endl;
}
void xugen(double a, double b, double c)
{
	double shi = 0;//ʵ������
	double xu = 0;//��������
	cout << "�����������" << endl;
	shi = (-b) / (2 * a);
	xu = sqrt(4 * a * c - b * b) / (2 * a);
	if (fabs(shi) < 1e-6) {
		if (fabs(xu - 1) >= 1e-6 && xu >= 1e-6) {
			cout << "x1=" << "+" << xu << 'i' << endl;
			cout << "x2=" << "-" << xu << 'i' << endl;
		}
		else if(fabs(xu + 1) >= 1e-6 && xu <= -1e-6) {
			cout << "x1=" << -xu << 'i' << endl;
			cout << "x2=" << xu << 'i' << endl;
		}
		else if (fabs(xu - 1)< 1e-6|| fabs(xu + 1) < 1e-6) {
			cout << "x1="  << 'i' << endl;
			cout << "x2="  << "-i" << endl;
		}
	}
	else {
		if (fabs(xu - 1) >= 1e-6 && xu >= 1e-6) {
			cout << "x1=" << shi << "+" << xu << 'i' << endl;
			cout << "x2=" << shi << "-" << xu << 'i' << endl;
		}
		else if(fabs(xu + 1) >= 1e-6 && xu <= -1e-6) {
			cout << "x1=" << shi << "+" << -xu << 'i' << endl;
			cout << "x2=" << shi << xu << 'i' << endl;
		}
		else if (fabs(xu - 1) < 1e-6 || fabs(xu + 1) < 1e-6) {
			cout << "x1=" << shi << "+i" << endl;
			cout << "x2=" << shi << "-i" << endl;
		}
	}
}
int main()
{
	double a = 0;
	double b = 0;
	double c = 0;
	cout << "������һԪ���η��̵�����ϵ��a,b,c:" << endl;
	cin >> a >> b >> c;
	if (fabs(a) <= 1e-6)
		a_0(a, b, c);
	else {
		if (fabs(b * b - 4 * a * c) <= 1e-6)
			two_same_shigen(a, b, c);
		else if ((b * b - 4 * a * c) > 1e-6)
			two_different_shigen(a, b, c);
		else
			xugen(a, b, c);
	}
	return 0;
}