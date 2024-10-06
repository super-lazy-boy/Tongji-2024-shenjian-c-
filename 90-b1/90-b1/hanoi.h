/* 信08 2352467 赵阿强 */
#pragma once

/* ------------------------------------------------------------------------------------------------------

     本文件功能：
	1、为了保证 hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp 能相互访问函数的函数声明
	2、一个以上的cpp中用到的宏定义（#define）或全局只读（const）变量，个数不限
	3、可以参考 cmd_console_tools.h 的写法（认真阅读并体会）
   ------------------------------------------------------------------------------------------------------ */
#include<iostream>
#include<conio.h>
using namespace std;
int menu();//打印初始选择菜单
void hanoi(int n, char src, char tmp, char dst, int delay_time, int choice);//实现汉诺塔递归
void input_choice(int* n, char* src, char* tmp, char* dst, int* delay_time, int choice);//输入塔数和起始目标柱
void print_heng();//横向打印内部过程
void print_zong(int x, int y);
void print_choice(int n, char src, char tmp, char dst, int dealy_time, int choice);
void draw_col();
void draw_plate(char src, char dst, int n);
void draw(char src, char tmp, char dst, int n, int delay_time, int choice);
void move_lr(char src, char dst);
void move_ud(char src, char dst, int order);//1下0上
void to_be_continued(const char* prompt, const int X , const int Y );
void game(char src, char tmp, char dst, int n, int delay_time, int choice);

