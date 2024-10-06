/* 信08 2352467 赵阿强 */

/* ----------------------------------------------------------------------------------

     本文件功能：
	1、放main函数
	2、初始化屏幕
	3、调用菜单函数（hanoi_menu.cpp中）并返回选项
	4、根据选项调用菜单各项对应的执行函数（hanoi_multiple_solutions.cpp中）

     本文件要求：
	1、不允许定义全局变量（含外部全局和静态全局，const及#define不在限制范围内）
	2、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	3、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */

#include"cmd_console_tools.h"
#include"hanoi.h"
int count = 0;
int main()
{
    /* demo中首先执行此句，将cmd窗口设置为40行x120列（缓冲区宽度120列，行数9000行，即cmd窗口右侧带有垂直滚动杆）*/
	cct_setconsoleborder(120, 40, 120, 9000);
	int choice = 0;
	char src = 0, tmp = 0, dst = 0;
	int n = 0;
	int delay_time = 0;
	extern int count;
	extern int col[3][10];
	extern int top[3];
	while (1) {
		choice = menu();
		if (choice == 0)
			break;
		if (choice != 5) {
			input_choice(&n, &src, &tmp, &dst, &delay_time, choice);
		}
		if (choice > 3)
			cct_cls();
		if (choice > 4) {
			draw(src, tmp, dst, n, delay_time, choice);
			cct_setcolor();
		}
		if (choice == 5||choice==6) {
			to_be_continued("按回车键继续", 0, 30);
		}
		if (choice < 5 || choice == 7 || choice == 8) {
			count = 0;
			hanoi(n, src, tmp, dst, delay_time, choice);
			if (choice == 7 || choice == 8)
				to_be_continued("按回车键继续", 0, 35);
			else {
				int x = 0, y = 0;
				cct_getxy(x, y);
				to_be_continued("按回车键继续", 0, y + 1);
			}
		}
		if (choice == 9) {
			count = 0;
			game(src, tmp, dst, n, delay_time, choice);
			int x = 0, y = 0;
			cct_getxy(x, y);
			to_be_continued("按回车键继续", 0, y+1);
		}
	}
	return 0;
}
