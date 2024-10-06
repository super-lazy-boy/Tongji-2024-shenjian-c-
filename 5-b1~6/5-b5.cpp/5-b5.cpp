/*2352467 赵阿强 信08*/
#include<iostream>
using namespace std;
int main()
{
	cout << "请输入成绩（最多1000个），负数结束输入" << endl;
	int score[1000];
	int i = 0;
	for (i = 0; i < 1000; i++)//初始化为-1
		score[i] = -1;
	for (i = 0; i < 1000; i++)//输入数据
	{
		cin>>score[i];
		if (score[i] < 0)
			break;
	}
	cout << "输入的数组为:" << endl;
	int mid = 0;
	int j = 0;
	int row = 0;
	for (i = 0; i < 1000; i++)//打印
	{
		if (score[i] >= 0) {
			row++;
			if (row % 10 == 0 && row != 0)
				cout << endl;
			cout<<score[i]<<" ";
		}
		else
			break;
	}
	for (i = 0; i < 999; i++)//排序
	{
		for (j = 0; j <= 1000 - (i + 1); j++)
			if (score[j] < score[j + 1]) {
				mid = score[j];
				score[j] = score[j + 1];
				score[j + 1] = mid;
			}
	}
	
	cout << endl;
	cout << "分数与名次的对应关系为:" << endl;
	int count = 0;
	for (i = 0; i < 1000; i++)
	{
		if (score[i] >= 0)
		{
			if (score[i] == score[i - 1]) {
				cout << score[i] << " " << count << endl;
				count++;
			}
			else {
				count++;
				cout << score[i] << " " << count << endl;
				continue;
			}
		}
		else
			break;
	}

	return 0;
}