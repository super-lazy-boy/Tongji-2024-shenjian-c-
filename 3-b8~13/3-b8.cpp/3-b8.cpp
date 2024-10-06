/*2352467 信08 赵阿强*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	int x;
	double  n = 1;
	double m=1;
	double num=1;
	while (1){

		cout << "请输入x的值[-10 ~ +65]" << endl;
	    cin >> x;
		if (x >= -10 && x <= 65)
			break;
		else
			cout << "输入非法，请重新输入" << endl;
	}
	while (fabs(pow(x, n) / m )>= 1e-6) {
		num += pow(x, n) / m;
		n++;
		m *= n;
	}
	
	cout << "e^" << x << "="<<setprecision(10) << num << endl;
	return 0;
}