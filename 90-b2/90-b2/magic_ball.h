#pragma once
#include<iostream>
#include<conio.h>
#include<iomanip>
#include<Windows.h>
#include<time.h>
#include<cstring>
using namespace std;

void menu(int* choice);
void to_be_continued(const char* prompt);
int input(int order);
void random_base(int row, int col, int base[][9]);//随机化数组
void showbase(int row, int col, int base[][9]);//打印数组
int find_can_delete(int row, int col, int base[][9]);//寻找可以消除的项
void to_be_end(const char* prompt);//输出结束语
void print0_can_delete(int row, int col, int base[][9]);//将可消除项转化为0
void move_0_up(int row, int col, int base[][9]);//把0移动到最上端
void print_rand_ch(int row, int col, int base[][9]);//将0转化为随机值
void back_base(int row, int col, int base[][9]);//将数组转变为全为1~9之间的数字
void find_can_switch(int row, int col, int base[][9]);//找到可以交换后消除的项
void print_graph(int row, int col, int choice,int*x,int*y);//打印图表
void print_ball(int row, int col, int choice, int x, int y, int base[][9],int order);//打印小球
void change_delete(int row, int col, int base[][9], int x, int y);//实现可消除项的动画消除操作(只考虑了有分隔线的情况）
void change_drop(int row, int col, int base[][9], int x, int y);//实现小球下落的动画显示
void change_input(int row, int col, int base[][9], int x, int y, int* count);//填充空位动画
void read_mouse(int row, int col, int base[][9], int x, int y, int order, int* count, int lines, int cols);//识别鼠标

void base_choice(int row, int col, int base[][9], int choice);
void graph_choice(int row, int col, int base[][9],int choice);
void graph_choice6(int row, int col, int base[][9]);
void graph_choice7(int row, int col, int base[][9]);
void graph_choice89(int row, int col, int base[][9], int choice);