/* 2352467 赵阿强 信08 */
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

const int MAX_X = 69;	//定义*组成的边框的宽度
const int MAX_Y = 17;	//定义*组成的边框的高度

/***************************************************************************
  函数名称：
  功    能：完成与system("cls")一样的功能，但效率高
  输入参数：
  返 回 值：
  说    明：清除整个屏幕缓冲区，不仅仅是可见窗口区域(使用当前颜色)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* 取当前缓冲区信息 */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* 填充字符 */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* 填充属性 */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* 光标回到(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  函数名称：gotoxy
  功    能：将光标移动到指定位置
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  函数名称：showch
  功    能：在指定位置处打印一个指定的字符
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
			char ch     ：要打印的字符
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  函数名称：init_border
  功    能：显示初始的边框及随机字符
  输入参数：HANDLE hout：输出设备句柄
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//光标移回左上角(0,0)
	cout << "***********************************************************************" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "***********************************************************************" << endl;

	/* 随机显示20个大写字母，字母的值、XY坐标都随机显示
	   rand()函数的功能：随机生成一个在 0-32767 之间的整数
	   思考：在什么情况下，下面这个循环执行生成后，你看到的实际字母个数不足20个？ */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- 按需增加的若干函数可以放在此处 --*/

void move_by_ijkl(const HANDLE hout, int x, int y, bool judge)
{
	int input = 0;
	while (1) {

		input = _getch();
		if (input == 73 || input == 73 + 32)//I
			y--;
		if (input == 74 || input == 74 + 32)//J
			x--;
		if (input == 75 || input == 75 + 32)//K
			y++;
		if (input == 76 || input == 76 + 32)//L
			x++;
		if (input == 81 || input == 81 + 32) {
			gotoxy(hout, 0, MAX_Y + 2);
			int i;
			for (i = 0; i < 4; i++)
				cout << endl;
			cout << "游戏结束，按回车键返回菜单.";
			break;
		}
		if (judge == 1 && x == MAX_X + 1)
			x = 1;
		else if (judge == 1 && x == 0)
			x = MAX_X - 1;
		if (judge == 1 && y == MAX_Y + 1)
			y = 1;
		else if (judge == 1 && y == 0)
			y = MAX_Y - 1;
		//边界回绕
		if (judge == 0 && x == MAX_X + 1)
			x--;
		else if (judge == 0 && x == 0)
			x++;
		if (judge == 0 && y == MAX_Y + 1)
			y--;
		else if (judge == 0 && y == 0)
			y++;
		//边界停止
		if (input == 32)
			putchar(' ');
		gotoxy(hout, x, y);
	}
	while (1) {
		input = _getch();
		if (input == 13) {
			cls(hout);
			break;
		}
	}
}

int menu()
{
	cout << "1.用I、J、K、L键控制上下左右(大小写均可，边界停止)" << endl;
	cout << "2.用I、J、K、L键控制上下左右(大小写均可，边界回绕)" << endl;
	cout << "3.用箭头键控制上下左右，边界停止" << endl;
	cout << "4.用箭头键控制上下左右，边界回绕" << endl;
	cout << "0.退出" << endl;
	cout << "[请选择0-6]";
	int num = 0;
	num = _getch();
	return num;
}

void move_by_arrow(const HANDLE hout, int x, int y, bool judge)
{
	int input = 0;
	while (1) {
		input = _getch();
		if (input == 224)
		{
			input = _getch();
			if (input == 75)
				x--;
			if (input == 72)
				y--;
			if (input == 77)
				x++;
			if (input == 80)
				y++;
			if (judge == 1 && x == MAX_X + 1)
				x = 1;
			else if (judge == 1 && x == 0)
				x = MAX_X - 1;
			if (judge == 1 && y == MAX_Y + 1)
				y = 1;
			else if (judge == 1 && y == 0)
				y = MAX_Y - 1;
			//边界回绕
			if (judge == 0 && x == MAX_X + 1)
				x--;
			else if (judge == 0 && x == 0)
				x++;
			if (judge == 0 && y == MAX_Y + 1)
				y--;
			else if (judge == 0 && y == 0)
				y++;
			//边界停止
			gotoxy(hout, x, y);
		}
		if (input == 32)
			putchar(' ');
		if (input == 81 || input == 81 + 32) {
			gotoxy(hout, 0, MAX_Y + 2);
			int i;
			for (i = 0; i < 4; i++)
				cout << endl;
			cout << "游戏结束，按回车键返回菜单.";
			break;
		}
	}
	while (1) {
		input = _getch();
		if (input == 13) {
			cls(hout);
			break;
		}
	}
}

int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	srand((unsigned int)(time(0)));
	int num = 1;
	while (1) {
		num = menu();
		if (num == 48)
			break;
		cls(hout);
		init_border(hout);
		gotoxy(hout, 34, 8);
		int x = 34, y = 8;
		bool judge = 0;
		switch (num) {
		case 49:
			judge = 0;
			move_by_ijkl(hout, x, y, judge);
			break;
		case 50:
			judge = 1;
			move_by_ijkl(hout, x, y, judge);
			break;
		case 51:
			judge = 0;
			move_by_arrow(hout, x, y, judge);
			break;
		case 52:
			judge = 1;
			move_by_arrow(hout, x, y, judge);
			break;
		}//49-51是1到4的ASCII

	}
	return 0;
}