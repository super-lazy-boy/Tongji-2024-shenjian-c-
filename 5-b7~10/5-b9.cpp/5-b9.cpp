/*2352467 赵阿强 信08*/
#include <iostream>
#include<limits>
using namespace std;
int judge_hanglie(int shudu[])//判断行和列是否符合要求
{
	int row[9] = { 0 };
	int i = 0;
	for (i = 0; i < 9; i++) {
		row[shudu[i]-1] += 1;
	}
	int judge = 0;
	for (i = 0; i < 9; i++) {
		if (row[i] != 1)
			judge = 0;
		else
			judge = 1;
	}
	if (judge)
		return 1;
	else
		return 0;
}
int judge_9(int shudu[][9])
{
	int judge = 0;
	int ge[9] = { 0 };
	int i = 0, j = 0, k = 0, n = 0, l = 0;
	for (i = 1; i <= 3; i++) {
		for (l = 1; l <= 3; l++) {
			for (j = 3 * (i - 1); j < 3 * i; j++) {
				for (k = 3 * (l - 1); k < 3 * l; k++) {
					ge[shudu[j][k] - 1] += 1;
				}
			}
			for (n = 0; n < 9; n++) {
				if (ge[i] == 1)
					judge++;
			}
			if (judge != 9)
				break;
		}
	}
	if (judge == 81)
		return 1;
	else
		return 0;
}
int main() {
	cout << "请输入9*9的矩阵，值为1-9之间" << endl;
	int shudu[9][9] = { 0 };
	int i = 0, j = 0;
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			while (1) {
				cin >> shudu[i][j];
				if (cin.fail()) {
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "请重新输入第" << i+1 << "行" << j+1 << "列(行列均从1开始计数)的值" << endl;
					continue;
				}
				else if (cin.good() && shudu[i][j] < 1 || shudu[i][j]>9) {
					cout << "请重新输入第" << i+1 << "行" << j+1 << "列(行列均从1开始计数)的值" << endl;
					continue;
				}
				else
					break;
			}
		}
	}
	int shudu_change[9][9];
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			shudu_change[i][j] = shudu[j][i];
		}
	}
	int judge = 0;
	for (i = 0; i < 9; i++) {
		if (judge_hanglie(shudu[i])&&judge_hanglie(shudu_change[i]))
			judge = 1;
		else
			judge = 0;
	}
	if (judge && judge_9(shudu))
		cout << "是数独的解" << endl;
	else
		cout << "不是数独的解" << endl;
	return 0;
	
}