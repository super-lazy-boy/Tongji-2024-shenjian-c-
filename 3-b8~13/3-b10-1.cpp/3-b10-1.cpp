/* 信08 2352467 赵阿强*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <windows.h> //取系统时间
using namespace std;

int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//获得计数器频率
	QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数

	/* 此处是你的程序开始 */
	int num1 = 123;
	int total = 0;
	int a, b, c;
	int d = 0;
	int e = 0;
	int f = 0;
	int g = 0;
	int h = 0;
	int i = 0;
	int num2 =0;
	int num3 =0 ;
	
	for(num1;num1<=987;num1++)
	{
        a = num1 / 100;
	    b = num1 / 10 % 10;
	    c = num1 % 10;
		if (a!=b&&b!=c&&a!=c&&a!=0&&b!=0&&c!=0)
		{
			for (num2=1953-987-num1; num2 <= 987; num2++)
			{
				d = num2 / 100;
				e = num2 / 10 % 10;
				f = num2 % 10;
				if (d != e && e != f && d != f&&(num1+num2)>=(1953-987)&&d!=0&&e!=0&&f!=0)
				{
					num3 = 1953 - num1 - num2;
					g = num3 / 100;
					h = num3 / 10 % 10;
					i = num3 % 10;
					if (!(a == d || a == e || a == f || a == g || a == h || a == i
						|| b == d || b == e || b == f || b == g || b == h || b == i
						|| c == d || c == e || c == f || c == g || c == h || c == i
						|| d == e || d == f || d == g || d == h || d == i
						|| e == f || e == g || e == h || e == i
						|| f == g || f == h || f == i
						|| g == h || g == i
						|| h == i || num3 < num2 || num2 < num1 || num3 < num1
						|| num2 < 123 || num2>987 || num3 < 123 || num3>987
						||g==0||h==0||i==0))
					{
						total++;
						cout << "No." << setw(3) << setiosflags(ios::right) << total << " : " << num1 << "+" << num2 << "+" << num3 << "=1953" << endl;
					}
				}	
					
			}
			
		}
		
	}
      cout << "total=" << total << endl;

	
	
	/* 此处是你的程序结束 */

	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数

	cout << "计数器频率 : " << tick.QuadPart << "Hz" << endl;
	cout << "计数器计数 : " << end.QuadPart - begin.QuadPart << endl;
	cout << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "秒" << endl;

	return 0;
}