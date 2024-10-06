#include"magic_ball.h"
#include"cmd_console_tools.h"
int main()
{
	int choice = 0;
	int row = 0, col = 0;
	int base[9][9] = { 0 };
	int x = 0, y = 0;
	while (1) {
		cct_setconsoleborder(120 ,30,120,30);
		cct_setfontsize("新宋体", 16, 16);
		cct_cls();
		menu(&choice);
		if (choice == 0)
			break;
		cct_cls();
		row = input(1);
		col = input(0);
		switch (choice) {
		case 1:
		case 2:
		case 3:
			base_choice(row, col, base,choice);
			break;
		case 4:
		case 5:
			graph_choice(row, col, base,choice);
			break;
		case 6:
			graph_choice6(row, col, base);
			break;
		case 7:
			graph_choice7(row, col, base);
			break;
		case 8:
		case 9:
			graph_choice89(row, col, base,choice);
			break;
		case 0:
			break;
		}
		if (choice == 0)
			break;
		to_be_end("本小题结束，请输入End继续...");
	}
	return 0;
}