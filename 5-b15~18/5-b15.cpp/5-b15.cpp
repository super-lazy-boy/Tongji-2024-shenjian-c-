/*2352467 赵阿强 信08*/
#include<iostream>
using namespace std;
int main()
{
	char str[3][128] = { 0 };
	int big = 0, small = 0, num = 0, space = 0, others = 0;
	cout << "请输入第1行" << endl;
	cin.get(str[0], 128,'\n');
	getchar();
	cout << "请输入第2行" << endl;
	cin.get(str[1], 128,'\n');
	getchar();
	cout << "请输入第3行" << endl;
	cin.get(str[2], 128,'\n');
	getchar();
	int i=0,j = 0;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 128&&str[i][j]!='\0'; j++) {
			
			if (str[i][j] >= 'A' && str[i][j] <= 'Z')
				big++;
			else if (str[i][j] >= 'a' && str[i][j] <= 'z')
				small++;
			else if (str[i][j] >= '0' && str[i][j] <= '9')
				num++;
			else if (str[i][j] == ' ')
				space++;
			else
				others++;
		}
	}
	cout << "大写 : " << big << endl;
	cout << "小写 : " << small << endl;
	cout << "数字 : " << num << endl;
	cout << "空格 : " << space << endl;
	cout << "其它 : " << others << endl;
	return 0;
}