#include"magic_ball.h"
#include"cmd_console_tools.h"
void base_choice(int row, int col, int base[][9],int choice)
{
	int nothing = 0;//判断是否一个初始可消除项都没有
	random_base(row, col, base);
	cout << "初始数组为：" << endl;
	showbase(row, col, base);
	to_be_continued("按回车键进行寻找初始可消除项的操作...");
	while (1) {
		nothing = find_can_delete(row, col, base);
		if (nothing == row * col) {
			cout << "初始已无可消除项" << endl;
			break;
		}
		else {
			cout << "初始可消除项（不同色标识）：" << endl;
			showbase(row, col, base);
			if (choice == 1)
				break;
			if (choice > 1) {
				to_be_continued("按回车键进行数组下落除零操作...");
				cout << "下落除0后的数组（不同色标识）：" << endl;
				print0_can_delete(row, col, base);//变为0
				move_0_up(row, col, base);//移动到最上边
				showbase(row, col, base);//打印
				to_be_continued("按回车键进行新值填充...");
				cout << "新值填充后的数组（不同色标识）" << endl;
				print_rand_ch(row, col, base);
				showbase(row, col, base);
			}
		}
	}
	if (choice > 2) {
		cout << "可选择的消除提示（不同色标识）" << endl;
		back_base(row, col, base);
		find_can_switch(row, col, base);
		showbase(row, col, base);
	}
}