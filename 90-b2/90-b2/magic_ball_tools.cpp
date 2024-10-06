#include"magic_ball.h"
#include"cmd_console_tools.h"
void to_be_continued(const char* prompt)
{
	cct_setcolor(); //恢复缺省颜色
	cout << prompt;
	/* 忽略除回车键外的所有输入（注意：_getch的回车是\r，而getchar是\n）*/
	while (_getch() != '\r')
		;
	cout << endl;
}
int input(int order)//通过order来调节输入的是行数还是列数
{
	int num = 0;
	while (1) {
		if (order)
			cout << "请输入行数（5-9）：" << endl;
		else 
			cout << "请输入列数（5-9）：" << endl;
		cin >> num;
		if (cin.fail() || num < 5 || num>9) {
			cin.clear();
			cin.ignore(21747483647, '\n');
			continue;
		}
		break;
	}
	return num;
}
void random_base(int row, int col, int base[][9])//随机化数组
{
	srand((int)time(NULL));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			base[i][j] = rand() % 9 + 1;
		}
	}
}
void showbase(int row, int col, int base[][9])//打印数组
{
	cout << "  |";
	for (int i = 0; i < row; i++) {
		cout << setw(2) << i + 1;
	}
	cout << endl << "--+" << setfill('-') << setw(2 * col + 1) << "-" << endl;
	int x = 0, y = 0;
	for (int i = 0; i < row; i++) {
		cout << char('A' + i) << " |";
		for (int j = 0; j < col; j++) {
			if(base[i][j]<10)
			cout << setfill(' ') << setw(2) << base[i][j];
			else {
				cout << ' ';
				cct_getxy(x, y);
				cct_showch(x, y, char(base[i][j]), 14, 0);
				cct_setcolor(); //恢复缺省颜色
			}
		}
		cout << endl;
	}
}
int find_can_delete(int row, int col, int base[][9])//寻找可以消除的项
{
	int background[13][13] = { 0 };//创建大一圈的数组，方便进行判断操作
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			background[i + 2][j + 2] = base[i][j];//(0,0)对应在背景板中的位置是(2,2)
		}
	}
	int nothing = 0;//判断是否一个初始可消除项都没有
	int nothing_each = 0;//判断数组单个项的周围是否一个可消除项都没有
	for (int i = 2; i < row + 2; i++) {
		for (int j = 2; j < 2 + col; j++) {
			for (int k = 0; k < 4; k++) {
				int count = 0;
				for (int l = 1; l < 10; l++) {
					//最多会有九个相同连在一起
					if (background[i + l][j] == background[i][j] && k == 0)
						count++;
					if (background[i - l][j] == background[i][j] && k == 1)
						count++;
					if (background[i][j + l] == background[i][j] && k == 2)
						count++;
					if (background[i][j - l] == background[i][j] && k == 3)
						count++;
					//上下左右进行判断
					if (l != count)//如果出现不相等的情况，则退出循环
						break;
				}
				if (count >= 2) {
					for (; count >= 0; count--) {
						if (k == 0 && base[i + count-2][j-2] < 10)
							base[i - 2 + count][j - 2] += 48;//base数组转化为对应字符的ASCII值
						if (k == 1 && base[i - count-2][j-2] < 10)
							base[i - 2 - count][j - 2] += 48;
						if (k == 2 && base[i-2][j + count-2] < 10)
							base[i - 2][j + count - 2] += 48;
						if (k == 3 && base[i-2][j - count-2] < 10)
							base[i - 2][j - count - 2] += 48;
					}
				}
				else
					nothing_each++;
			}
			if (nothing_each == 4) {
				nothing++;
				nothing_each = 0;
			}
		}
	}
	return nothing;
}
void to_be_end(const char* prompt)//输出结束语
{
	cct_setcolor(); //恢复缺省颜色
	cout << prompt;
	/* 忽略除回车键外的所有输入（注意：_getch的回车是\r，而getchar是\n）*/
	char end[100] = { 0 };
	char End[3] = {'E','n','d'};
	int cha = 0;
	int x = 0, y = 0;
	do {
		cct_getxy(x, y);
		cin >> end;
		for (int i = 0; i < 3; i++) {
			cha += end[i] - End[i];
		}
		if (cha){
			cct_gotoxy(x, y);
			for (unsigned int i = 0; i < strlen(end); i++) {
				cout << " ";//退格+空格
			}
			cout << endl << "输入错误，请重新输入";
			cct_gotoxy(x, y);
		}
		cin.clear();
		cin.ignore(2147483647, '\n');
	} while (cha != 0);
}
void print0_can_delete(int row, int col, int base[][9])//将可消除项转化为0
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (base[i][j] > 10)
				base[i][j] = 48;
		}
	}
}
void move_0_up(int row, int col, int base[][9]) //把0移动到最上端
{
	for (int j = 0; j < col; j++) {
		for (int i = 0; i < row; i++) {
			if (base[i][j] == 48) {//判断变为0的项
				for (int k = i; k>0; k--) {
					if (base[k - 1][j] < 10) {
						int t = 0;
						t = base[k][j];
						base[k][j] = base[k - 1][j];
						base[k - 1][j] = t;
						//如果是零则进行互换，让为0的项到达数组的顶端
					}
				}
			}
		}
	}
}
void print_rand_ch(int row, int col, int base[][9])//将0转化为随机值
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (base[i][j] == 48)
				base[i][j] = rand() % 9 + 1 + 48;//方便showbase函数打印
		}
	}
}
void back_base(int row, int col, int base[][9])//将数组转变为全为1~9之间的数字
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (base[i][j] > 9)
				base[i][j] -= 48;
		}
	}
}
void tool_plus48(int base[][9],int x,int y)//fin_can_switch配套工具
{
	if ( base[x][y]< 10)
		base[x][y] += 48;
}
void find_can_switch(int row, int col, int base[][9])//找到可以交换后消除的项
{
	int background[14][14] = { 0 };//创建大一圈的数组，方便进行判断操作
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			background[i + 3][j + 3] = base[i][j];//(0,0)对应在背景板中的位置是(2,2)
		}
	}
	for (int i = 3; i < row+3; i++) {
		for (int j = 3; j < col+3; j++) {
			//判断3*3内有没有中间插入型项
			if (background[i + 1][j + 1] == background[i][j] && background[i + 1][j - 1] == background[i][j]) {
				tool_plus48(base,i-3,j-3);
				tool_plus48(base, (i + 1) -3, j - 3);
			}
			if (background[i - 1][j + 1] == background[i][j] && background[i - 1][j - 1] == background[i][j]) {
				tool_plus48(base,i - 3,j - 3);
				tool_plus48(base, (i - 1) - 3, j - 3);
			}
			if (background[i + 1][j + 1] == background[i][j] && background[i - 1][j + 1] == background[i][j]) {
				tool_plus48(base,i - 3,j - 3);
				tool_plus48(base, i - 3, (j + 1) - 3);
			}
			if (background[i + 1][j - 1] == background[i][j] && background[i - 1][j - 1] == background[i][j]) {
				tool_plus48(base,i - 3,j - 3);
				tool_plus48(base, i - 3, (j - 1) - 3);
			}

			//判断5*5内有没有末端插入型项
			if (background[i + 1][j + 1] == background[i][j]) {
				if (background[i + 2][j + 1] == background[i][j]) {
					tool_plus48(base, i - 3, j - 3);
					tool_plus48(base, i - 3, j + 1 - 3);
				}
				if (background[i + 1][j + 2] == background[i][j]) {
					tool_plus48(base, i - 3, j - 3);  
					tool_plus48(base, i + 1 - 3, j - 3);
				}
			}
			if (background[i + 1][j - 1] == background[i][j]) {
				if (background[i + 2][j - 1] == background[i][j]) {
					tool_plus48(base, i - 3, j - 3);
					tool_plus48(base, i - 3, j - 1 - 3);
				}
				if (background[i + 1][j - 2] == background[i][j]) {
					tool_plus48(base, i - 3, j - 3);
					tool_plus48(base, i + 1 - 3, j - 3);
				}
			}
			if (background[i - 1][j + 1] == background[i][j]) {
				if (background[i - 2][j + 1] == background[i][j]) {
					tool_plus48(base, i - 3, j - 3);
					tool_plus48(base, i - 3, j + 1 - 3);
				}
				if (background[i - 1][j + 2] == background[i][j]) {
					tool_plus48(base, i - 3, j - 3);
					tool_plus48(base, i - 1 - 3, j - 3);
				}
			}
			if (background[i - 1][j - 1] == background[i][j]) {
				if (background[i - 2][j - 1] == background[i][j]) {
					tool_plus48(base, i - 3, j - 3);
					tool_plus48(base, i - 3, j - 1 - 3);
				}
				if (background[i - 1][j - 2] == background[i][j]) {
					tool_plus48(base, i - 3, j - 3);
					tool_plus48(base, i - 1 - 3, j - 3);
				}
			}

			//判断7*7内有没有末端插入型项
			if (background[i - 2][j] == background[i][j] && background[i - 3][j] == background[i][j]) {
				tool_plus48(base, i - 3, j - 3);
				tool_plus48(base, i - 1 - 3, j - 3);
			}
			if (background[i +2][j ] == background[i][j] && background[i +3][j] == background[i][j]) {
				tool_plus48(base, i - 3, j - 3);
				tool_plus48(base, i + 1 - 3, j - 3);
			}
			if (background[i][j + 2] == background[i][j] && background[i][j + 3] == background[i][j]) {
				tool_plus48(base, i - 3, j - 3);
				tool_plus48(base, i  - 3, j+1 - 3);
			}
			if (background[i][j - 2] == background[i][j] && background[i][j - 3] == background[i][j]) {
				tool_plus48(base, i - 3, j - 3);
				tool_plus48(base, i - 3, j - 1 - 3);
			}
		}
	}
}
void print_graph(int row, int col,int choice,int*x,int*y)//打印图表
{
	cct_setcolor(7, 0);
	cct_showstr(0, 1, "╔", 7, 0);
	for (int i = 0; i < col; i++) {
		if (choice == 4)
			cct_showstr(2 + 2*i, 1, "═", 7, 0);
			if (choice == 5) {
				cct_showstr(2 + 4*i, 1, "═", 7, 0);
				if (i < col - 1)
					cct_showstr(4 + 4 * i, 1, "╦", 7, 0);
			}
	}
	if(choice==4)
		cct_showstr(2*col+2, 1, "╗", 7, 0);
	if(choice==5)
		cct_showstr(4*col, 1, "╗", 7, 0);
	cout << endl;
	cct_getxy(*x, *y);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col+1; j++) {
			cct_showstr(0, 2 + i, "║", 7, 0);
			if (choice == 4 && j == 0) 
				cct_showstr(2+2*j, 2 +  i, "  ", 7, 0);
			if (choice == 5) {
				cct_showstr(4 * j, 2 + 2 * i, "║", 7, 0);
				if (j < col)
					cct_showstr(4 * j + 2, 2 + 2 * i, "  ", 7, 0);
			}
		}
		if (choice == 4)
			cct_showstr(2*col + 2, 2 + i, "║", 7, 0);
		if(choice==5)
			if (i < row - 1) {
					cct_showstr(0, 3 + 2 * i, "╠", 7, 0);
				for (int j = 0; j < col; j++) {
				cct_showstr(2+4 * j, 3 + 2 * i, "═", 7, 0);
				if (j < col - 1)
					cct_showstr(4 * j + 4, 3 + 2 * i, "╬", 7, 0);
				}
				cct_showstr(4 * col, 3 + 2 * i, "╣", 7, 0);
			}
	}
	if(choice==4)
		cct_showstr(0, 2 +  row, "╚", 7, 0);
if(choice==5)
 cct_showstr(0, 1 + 2 * row, "╚", 7, 0);
	for (int i = 0; i < col; i++) {
		if (choice == 4)
			cct_showstr(2 + 2*i, 2 + row, "═", 7, 0);
		if (choice == 5) {
			cct_showstr(2 + 4* i, 1 + 2 * row, "═", 7, 0);
			if (i < col - 1)
				cct_showstr(4 + 4 * i, 1 + 2 * row, "╩", 7, 0);
		}
	}
 if (choice == 4)
	 cct_showstr(2 * col+2, 2 + row, "╝", 7, 0);
 if (choice == 5)
	 cct_showstr(4 * col, 1 + 2 * row, "╝", 7, 0);
}
void print_ball(int row, int col, int choice,int x,int y,int base[][9],int order)//打印小球
{
	x += 2;		
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (choice == 4) {
				if (base[i][j] < 10)
					cct_showstr(x + 2 * j, y + i, "〇", base[i][j], 0);
				else if (base[i][j] > 48 && order == 0) 
					cct_showstr(x + 2 * j, y + i, "●", base[i][j] - 48, 0);
				else
					cct_showstr(x + 2 * j, y + i, "◎", base[i][j] - 48, 0);
			}
			if (choice == 5) {
				if (base[i][j] < 10) 
					cct_showstr(x + 4 * j, y + 2 * i, "〇", base[i][j], 0);
				else if (base[i][j] > 48 && order == 0) 
					cct_showstr(x + 4 * j, y + 2 * i, "●", base[i][j] - 48, 0);
				else
					cct_showstr(x + 4 * j, y + 2 * i, "◎", base[i][j] - 48, 0);
			}
		}
	}
}
void change_delete(int row, int col, int base[][9],int x,int y)//实现可消除项的动画消除操作(只考虑了有分隔线的情况）
{
	x += 2;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (base[i][j] > 10) {
				for (int k = 0; k < 3; k++) {
					cct_showstr(x + 4 * j, y + 2 * i, "¤", base[i][j], 0);
					Sleep(200);
					cct_showstr(x + 4 * j, y + 2 * i, "〇", base[i][j], 0);
				}
				cct_showstr(x + 4 * j, y + 2 * i, "  ", 7, 0);
			}
		}
	}
}
void change_drop(int row, int col, int base[][9],int x,int y) //实现小球下落的动画显示
{
	x += 2;
	for (int j = 0; j < col; j++) {
		for (int i = row-1; i>=0; i--) {
			if (base[i][j] <10) {//判断非0的项
				for (int k = i; k <row; k++) {
					if (base[k + 1][j] ==48) {
						int t = 0;
						t = base[k][j];
						base[k][j] = base[k + 1][j];
						base[k + 1][j] = t;
						//如果是零则进行互换，让小球到达最底部
						cct_showstr(x + 4 * j, y + 2 * (k+1), "〇", base[k+1][j], 0);
						cct_showstr(x + 4 * j, y + 2 * k , "  ", 7,0);
						Sleep(200);
					}
				}
			}
		}
	}
}
void change_input(int row, int col, int base[][9], int x, int y,int *count)//填充空位动画
{
	x += 2;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (base[i][j] == 48) {
				base[i][j] = rand() % 9 + 1;
				cct_showstr(x + 4 * j, y + 2 * i, "〇", base[i][j], 0);
				*count+=1;
				Sleep(50);
			}
		}
	}
}
void show_place(int mx, int my, int* i, int* j, int row, int col, int base[][9])
{
	cct_setcolor();
	if (my >= 2 && mx >= 3) {
		if (mx % 2 == 1)
			*j = (mx - 3) / 4;
		else
			*j = (mx - 2) / 4;
		*i = (my - 2) / 2;
		if (base[*i][*j] > 10 && *i < row && *j < col) 
			cout << "[当前光标]   " << char(65 + *i) << "行" << *j + 1 << "列         ";
		else
			cout << "[当前光标] " << "位置非法         ";
	}
	else
		cout << "[当前光标] " << "位置非法          ";
}
void read_mouse(int row, int col, int base[][9], int x, int y, int order, int* count, int lines, int cols)//识别鼠标
{
	int act = 0;
	int mx = 0, my = 0, maction = 0, keycode1 = 0, keycode2 = 0;
	cct_enable_mouse();
			int i = 0, j = 0;
	if(order==0)
		while (1) {
			cct_setcolor();
			act = cct_read_keyboard_and_mouse(mx, my, maction, keycode1, keycode2);
			if (act == CCT_MOUSE_EVENT) {
				cct_gotoxy(x, y + 2 * row + 1);
				show_place(mx, my, &i, &j, row, col, base);
			}
			if (act == CCT_MOUSE_EVENT)
				if (maction == MOUSE_RIGHT_BUTTON_CLICK)
					break;
		}
	if (order) {
		while (1) {
			do {
				act = cct_read_keyboard_and_mouse(mx, my, maction, keycode1, keycode2);
				cct_gotoxy(x, y + 2 * row + 1);
				show_place(mx, my, &i, &j, row, col, base);
				if (act == CCT_MOUSE_EVENT&&maction == MOUSE_RIGHT_BUTTON_CLICK)
						break;
			} while (maction != MOUSE_LEFT_BUTTON_CLICK || act != CCT_MOUSE_EVENT);
			if (act == CCT_MOUSE_EVENT && maction == MOUSE_RIGHT_BUTTON_CLICK)
				break;
			int nothing = 0;
			while (1) {
				int m = 0, n = 0;
				if (act == CCT_MOUSE_EVENT)
					if (maction == MOUSE_LEFT_BUTTON_CLICK && base[i][j] > 10 && i < row && j < col) {
						cct_showstr(x + 4 * j + 2, y + 2 * i, "〇", base[i][j], 7);
						cct_setcolor();
						cct_gotoxy(x, y + 2 * row + 1);
						cout << "当前选择" << char(65 + i) << "行" << j + 1 << "列               ";
						m = i;
						n = j;
						do {
							act = cct_read_keyboard_and_mouse(mx, my, maction, keycode1, keycode2);
							cct_gotoxy(x, y + 2 * row + 1);
							show_place(mx, my, &i, &j, row, col, base);
						} while (maction != MOUSE_LEFT_BUTTON_CLICK || act != CCT_MOUSE_EVENT);
						if (act == CCT_MOUSE_EVENT) {
							if (maction == MOUSE_LEFT_BUTTON_CLICK) {
								cct_gotoxy(x, y + 2 * row + 1);
								show_place(mx, my, &i, &j, row, col, base);
								if (base[i][j] > 10 && i < row && j < col && fabs(i - m) <= 1 && fabs(j - n) <= 1) {
									cct_gotoxy(x, y + 2 * row + 1);
									cout << "当前选择" << char(65 + i) << "行" << j + 1 << "列                  ";
									int t = 0;
									t = base[i][j];
									base[i][j] = base[m][n];
									base[m][n] = t;
									back_base(row, col, base);
									nothing = find_can_delete(row, col, base);
									if (nothing == row * col) {
										cct_gotoxy(x, y + 2 * row + 1);
										cct_setcolor();
										cout << "不能交换" << char(65 + m) << "行" << n << "列<=>" << char(65 + i) << "行" << j << "列";
										t = base[i][j];
										base[i][j] = base[m][n];
										base[m][n] = t;
										find_can_switch(row, col, base);
										print_ball(row, col, 5, x, y, base, 1);
										continue;
									}
									break;
								}
								else {
									cct_gotoxy(x, y + 2 * row + 1);
									cout << "当前不能选择" << char(65 + i) << "行" << j + 1 << "列              ";
									continue;
								}
							}
						}
					}
					else
						break;
			}
			while (1) {
				back_base(row, col, base);
				nothing = find_can_delete(row, col, base);
				cct_setcolor();
				if (nothing == row * col) {
					find_can_switch(row, col, base);
					print_ball(row, col, 5, x, y, base, 1);
					break;
				}
				else {
					print_ball(row, col, 5, x, y, base, 0);
					change_delete(row, col, base, x, y);
					print0_can_delete(row, col, base);//变为0
					change_drop(row, col, base, x, y);
					change_input(row, col, base, x, y, count);
					back_base(row, col, base);
					cct_setcolor();
					cct_gotoxy(0, 0);
					cout << "屏幕：" << lines << "行" << cols << "列（当前分数：" << *count << "右键退出）" << endl;
				}
			}
			int a = 0;
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					if (base[i][j] > 10)
						a++;
				}
			}
			if (a == 0)
				break;
		}
	}
}