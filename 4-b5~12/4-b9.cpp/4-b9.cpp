/* 2352467 信08 赵阿强*/
#include <iostream>
#include <iomanip>
#include <Windows.h>
using namespace std;
static unsigned int sum = 0;
/***************************************************************************
  函数名称：
  功    能：返回fibonacci数列的第n项的值
  输入参数：
  返 回 值：
  说    明：不允许任何形式的循环出现
***************************************************************************/
int fibonacci(int n)
{
	/* 按要求完成本函数 */
	sum++;
	if (n == 1 || n == 2) {
	
		return 1;
	}
	else {
	
		return fibonacci(n - 1) + fibonacci(n - 2);

	}
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不允许修改
***************************************************************************/
int main()
{
	int n, f;
	cout << "请输入Fibonacci数列的项数[1-46]" << endl;
	

	LARGE_INTEGER tick, begin, end;
	QueryPerformanceFrequency(&tick);	//获得时钟频率
	QueryPerformanceCounter(&begin);	//获得初始硬件定时器计数

	cin >> n;
		f = fibonacci(n);
		
		cout << "第" << n << "项的";
		cout << "执行次数为：" << sum << endl;
	

	QueryPerformanceCounter(&end);//获得终止硬件定时器计数
	cout << "计数器频率 : " << tick.QuadPart << "Hz" << endl;
	cout << "计数器计数 : " << end.QuadPart - begin.QuadPart << endl;
	cout << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "秒" << endl;

	return 0;
}
