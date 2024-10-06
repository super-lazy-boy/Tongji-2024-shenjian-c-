/* ÐÅ08 2352467 ÕÔ°¢Ç¿ */
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<iomanip>
using namespace std;
#define row 10
#define col 26

int main()
{
	char mine[row + 1][col + 1] = { 0 };
	char show[row+1][col+1] = { 0 };
	srand(time(NULL));
	//ÂñÀ×
	int count = 50;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] != '*')
		{
			mine[x][y] = '*';
			count--;
		}
	}
	int i = 0, j = 0;
	int x = 0, y = 0;
	for (i = 1; i < row+1; i++) {
		for (j = 1; j < col+1; j++) {
			if (mine[i][j] == '*')
				show[i][j] = '*';
			else {
				int num = 0;
				for (x = 0; x < 3; x++) {
					for (y = 0; y < 3; y++) {
						if (mine[i - 1 + x][j - 1 + y] == '*')
							num++;
					}
				}
				show[i][j] = char(num  + 48);
			}
		}
	}
	for (i = 1; i < row+1; i++) {
		for (j = 1; j < col+1; j++) {
			cout <<setw(2)<<setiosflags(ios::left)<< show[i][j];
		}
		cout << endl;
	}
	return 0;
}