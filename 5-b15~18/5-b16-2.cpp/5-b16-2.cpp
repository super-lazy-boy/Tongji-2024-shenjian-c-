/*2352467 赵阿强 信08*/
#include<iostream>
using namespace std;

void paixu(string num[10], string name[10], int score[10])
{
	string mid;
	for (int j = 0; j < 9; j++) {
		for (int i = 0; i < 9-j; i++) {

			if (score[i] > score[i + 1]) {
				mid = num[i];
				num[i] = num[i + 1];
				num[i + 1] = mid;

				mid = name[i];
				name[i] = name[i + 1];
				name[i + 1] = mid;

				int t = 0;
				t = score[i];
				score[i] = score[i + 1];
				score[i + 1] = t;
			}
		}
	}
}
void output(string num[10], string name[10], int score[10])
{
	cout <<endl<< "不及格名单(成绩升序):" << endl;
	for (int i = 0; i < 10; i++) {
		if (score[i]< 60) {
			cout << name[i] << " " << num[i] << " " << score[i] << endl;
		}
	}
}
void input(string num[10], string name[10], int score[10])
{
	for (int i = 0; i < 10; i++) {
		cout << "请输入第" << i + 1 << "个人的学号、姓名、成绩" << endl;
		cin >> num[i] >> name[i] >> score[i];
	}
}
int main()
{
	string num[10] ;
	string name[10] ;
	int score[10] = { 0 };
	input(num, name, score);
	paixu(num, name, score);
	output(num, name, score);
	return 0;
}