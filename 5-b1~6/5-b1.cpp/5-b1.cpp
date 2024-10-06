/*2352467 赵阿强 信08*/
#include<iostream>
#include<limits>
using namespace std;
int main()
{
	int str[21];
	int num = 0;
	int i = 0, j = 0;
	cout << "请输入任意个正整数（升序，最多20个），0或负数结束输入" << endl;
	for (i = 0; i < 20; i++)
	{
		cin >> str[i];
		if (str[i] <= 0) {
			str[i] = 0;
			if (i == 0)
				cout << "无有效输入" << endl;
			break;
		}
	}
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cout << "原数组为：" << endl;
	for (i = 0; i < 20; i++)
	{
		if (str[i] == 0)
			break;
		cout << str[i]<<" ";
	}
	cout << endl;
	cout << "请输入要插入的正整数" << endl;
	cin >> num;
	cout << "插入后的数组为：" << endl;
	str[20] = num;
	int mid = 0;
	for (i = 20; i >= 0; i--)
	{
		if (str[i] < str[i - 1]) {
			mid = str[i];
			str[i] = str[i - 1];
			str[i - 1] = mid;
		}
	}
	for (i = 0; i < 21; i++)
	{
		if (str[i] == 0)
			break;
		cout << str[i]<<" ";
	}
	cout << endl;
	return 0;
}