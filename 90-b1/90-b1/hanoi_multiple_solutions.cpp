/* 信08 2352467 赵阿强 */


/* ----------------------------------------------------------------------------------

     本文件功能：
	1、存放被 hanoi_main.cpp 中根据菜单返回值调用的各菜单项对应的执行函数

     本文件要求：
	1、不允许定义外部全局变量（const及#define不在限制范围内）
	2、允许定义静态全局变量（具体需要的数量不要超过文档显示，全局变量的使用准则是：少用、慎用、能不用尽量不用）
	3、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	4、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */
#include<iostream>
#include<limits>
#include<iomanip>
#include<conio.h>
#include <windows.h>
#include"cmd_console_tools.h"
#include"hanoi.h"
#define base_x 12
#define base_y 12
#define base_hengcol_x 1
#define base_hengcol_y 15
#define base_zongcol_x 12
#define base_zongcol_y 14
using namespace std;
int col[3][10] = { 0 };
int top[3] = { 0 };

void print_heng()//横向打印内部过程
{
    int i = 0;
    int j = 0;
    for (j = 0; j < 3; j++) {
        cout << char(j + 65) << ": ";
        for (i = 0; i < 10; i++) {
            if (col[j][i] > 0 && i < top[j])
                cout << setw(2) << setiosflags(ios::left) << col[j][i];
            else
                cout << "  ";
        }
    }
}
void print_zong(int x,int y)
{
    int i = 0;
    int j = 10;
    cct_gotoxy(x-2, y+1);
    cout << setfill('=') << setw(25) << "=";
    for (i = 0; i < 3; i++) {
        cct_gotoxy(x + 10 * i, y+2);
        cout << char(65 + i);
    }
    cout << setfill(' ');
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 10; j++) {
            cct_gotoxy(x + 10 * i-1, y - j);
            if (col[i][j] > 0 && j < top[i])
                cout << setw(2) << setiosflags(ios::right) << col[i][j];
            else
                cout << "  ";
        }
    }
}
void delay(int delay)
{
    switch (delay)
    {
    case 0:
        while (1) {
            if (_getch() == 13)
                break;
        }
        break;
    case 1:
        Sleep(1000);
        break;
    case 2:
        Sleep(800);
        break;
    case 3:
        Sleep(600);
        break;
    case 4:
        Sleep(400);
        break;
    case 5:
        Sleep(200);
        break;
    }
}
const int bg_color = COLOR_HYELLOW;	//背景为亮黄色
const int fg_color = COLOR_HBLUE;		//前景为亮蓝色
const char ch = ' ';        //字符为*(注意：如果是空格，则前景色无法显示)
void to_be_continued(const char *prompt, const int X , const int Y )
{
    cct_setcolor(); //恢复缺省颜色
    cct_gotoxy(X, Y);
    cout << prompt;
    /* 忽略除回车键外的所有输入（注意：_getch的回车是\r，而getchar是\n）*/
    while (_getch() != '\r')
        ;
    cct_cls();
}
void draw_plate(char src,char dst,int n) 
{
    int i = 0;
    int j = 10;
    cct_setcolor(); //恢复缺省颜色
    cct_gotoxy(0, 0);
    cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层" << endl;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 10; j++) {
            if (col[i][j] != 0)
                cct_showch(base_zongcol_x + 32 * i - col[i][j], base_zongcol_y - j, ch, col[i][j], col[i][j], 2 * col[i][j] + 1);
        }
    }
}
void draw_col()
{
    int i = 0, j = 0;
    for (i = 0; i < 3; i++) {
            cct_showch(base_hengcol_x+32*i, base_hengcol_y, ch, bg_color, fg_color, 23);
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 12; j++) {
            cct_showch(base_zongcol_x + 32 * i, base_zongcol_y - j, ch, bg_color, fg_color, 1);
        }
    }
}
#define maxy 1
void move_lr(char src,char dst)
{
    double distance = 0;
    distance= fabs(32 * (src - dst)) + 1;
    int x = 0, y = 0;
    x = dst - 65;
    y = top[dst - 65] - 1;
    int i = 0;
    cct_setcolor();
    for (i = 0; i < distance; i++) {
        if (src<dst) /* 将一串字符从左向右移动 */
            cct_showch(base_zongcol_x + 32 * (src - 65) - col[x][y] + i, maxy, ch, col[x][y], col[x][y], 2 * col[x][y] + 1);
        else//右往左
            cct_showch(base_zongcol_x + 32 * (src - 65) - col[x][y] - i, maxy, ch, col[x][y], col[x][y], 2 * col[x][y] + 1);
        /* 延时0.1秒 */
        Sleep(100);
        if (i < distance - 1) {
            /* 清除显示(最后一次保留)，清除方法为用正常颜色+空格重画一遍刚才的位置 */
            if (src < dst)
                cct_showch(base_zongcol_x + 32 * (src - 65) - col[x][y] + i, maxy, ' ', COLOR_BLACK, COLOR_WHITE, 2 * col[x][y] + 1);
            else
                cct_showch(base_zongcol_x + 32 * (src - 65) - col[x][y] - i, maxy, ' ', COLOR_BLACK, COLOR_WHITE, 2 * col[x][y] + 1);
        }
    } //end of for
}
void move_ud(char src, char dst, int order)//1下0上
{
    double distance =0;
    cct_setcolor();
    int x = 0, y = 0;
    x = dst - 65;
    y = top[dst - 65] - 1;
    if (order)
        distance = fabs(base_zongcol_y - top[dst - 65] - maxy) +1+1;
    else
        distance = fabs(base_zongcol_y - maxy + 1 - top[src - 65]);
    int i = 0;
    for (i = 0; i < distance; i++) {
        /* 在坐标(x,2)位置处连续打印10个字符 */
        if (order)
            cct_showch(base_zongcol_x + 32 * (dst-65) - col[x][y], maxy+i, ch, col[x][y], col[x][y], 2 * col[x][y] + 1);
        else
            cct_showch(base_zongcol_x + 32 * (src-65) - col[x][y], base_zongcol_y - top[src-65]-i, ch, col[x][y], col[x][y], 2 * col[x][y] + 1);

        /* 延时0.3秒 */
        Sleep(300);

        if (i < distance - 1) {
            /* 清除显示(最后一次保留)，清除方法为用正常颜色+空格重画一遍刚才的位置 */
            if (order) {
                cct_showch(base_zongcol_x + 32 * (dst - 65) - col[x][y], maxy + i, ' ', COLOR_BLACK, COLOR_WHITE, 2 * col[x][y] + 1);
                if (maxy + i <= base_zongcol_y && maxy + i > base_zongcol_y - 12)
                    cct_showch(base_zongcol_x + 32 * (dst - 65) , maxy + i, ch, bg_color, fg_color, 1);
            }
            else {
                cct_showch(base_zongcol_x + 32 * (src - 65) - col[x][y], base_zongcol_y - top[src - 65] - i, ' ', COLOR_BLACK, COLOR_WHITE, 2 * col[x][y] + 1);
                if (base_zongcol_y - top[src - 65] - i  <= base_zongcol_y && base_zongcol_y - top[src - 65] - i  >= base_zongcol_y - 12+1)
                    cct_showch(base_zongcol_x + 32 * (src - 65) , base_zongcol_y - top[src - 65] - i, ch, bg_color, fg_color, 1);
            }
        }
    } //end of for
}
void move(char src,char dst)
{
    move_ud(src, dst, 0);
    move_lr(src, dst);
    move_ud(src, dst, 1);
}
void draw(char src,char tmp, char dst, int n,int delay_time,int choice)
{
    cct_gotoxy(0, 0);
    if(choice>5)
    cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层" ;
    if (choice == 8)
        cout << "，延时设置为" << delay_time;
    draw_col();
    if (choice >= 6)
        draw_plate(src, dst, n);
}
#define base8_y 25
#define base8_x 11

void print_choice(int n, char src, char tmp, char dst, int delay_time ,int choice)//12348公用的打印函数
{
    extern int count;
    switch (choice) {
    case 1:
        cout <<  n << "# " << src << "-->" << dst << endl;
        break;
    case 2:
        count++;
        cout << "第 " << setw(3) << setiosflags(ios::right) << count << " 步(" << setw(2) << n << "#: " << src << "-->" << dst << ")" << endl;
        break;
    case 3:
        count++;
        cout << "第 " << setw(3) << setiosflags(ios::right) << count << " 步(" << setw(2) << n << "#: " << src << "-->" << dst << ")" ;
        col[dst - 65][top[dst - 65]++] = col[src - 65][--top[src - 65]];
        print_heng();
        cout << endl;
        break;
    case 4:
        if (count == 0) {
            print_zong(base_x, base_y);
            cct_gotoxy(0, base_y + 6);
            cout << "初始:";
            count++;
            print_heng();
            delay(delay_time);
        }
        col[dst - 65][top[dst - 65]++] = col[src - 65][--top[src - 65]];
        print_zong(base_x,base_y);
        cct_gotoxy(0, base_y + 6);
        cout << "第 " << setw(3) << setiosflags(ios::right) << count << " 步(" << setw(2) << n << "#: " << src << "-->" << dst << ")";
        count++;
        print_heng();
        delay(delay_time);
        break;
    case 7:
        count++;
        if (count == 1) {
            col[dst - 65][top[dst - 65]++] = col[src - 65][--top[src - 65]];
            move(src, dst);
        }
        break;
    case 8:
        if (count == 0) {
            print_zong(base8_x, base8_y);
            cct_gotoxy(0, base8_y + 6);
            cout << "初始:";
            count++;
            print_heng();
            delay(delay_time);
        }
        col[dst - 65][top[dst - 65]++] = col[src - 65][--top[src - 65]];
        print_zong(base8_x, base8_y);
        cct_gotoxy(0, base8_y + 6);
        cout << "第 " << setw(3) << setiosflags(ios::right) << count << " 步(" << setw(2) << n << "#: " << src << "-->" << dst << ")";
        count++;
        print_heng();
        move(src, dst);
        cct_setcolor();
        delay(delay_time);
        break;
    }
}
void hanoi(int n, char src, char tmp, char dst,int delay_time, int choice)
{
    if (n >= 2)
        hanoi(n - 1, src, dst, tmp,delay_time, choice);
    if(choice)
    print_choice(n, src, tmp, dst, delay_time,choice);
    if (n >= 2)
        hanoi(n - 1, tmp, src, dst,delay_time, choice);
}
void input_choice( int *n,char *src,char *tmp,char *dst,int *delay_time,int choice)
{
    char s = 0, t = 0, d = 0;
    int num = 0,  delay = 0;
    while (1) {
        cout << "请输入汉诺塔的层数(1-10)" << endl;
        cin >> num;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(27147483647, '\n');
            continue;
        }
        if (num >= 1 && num <= 16)
        {
            cin.clear();
            cin.ignore(27147483647, '\n');
            break;
        }
    }
    while (1) {
        cout << "请输入起始柱(A-C)" << endl;
        cin >> s;
        cin.clear();
        cin.ignore(27147483647, '\n');
        if (cin.fail() || s < 'A' || (s > 'C' && s < 'a') || s > 'c')
        {
            continue;
        }
        if ((s >= 'A' && s <= 'C') || (s >= 'a' && s <= 'c'))
        {
            if (s >= 'a')
                s = char(s - 32);
            break;
        }
    }
    while (1) {
        cout << "请输入目标柱(A-C)" << endl;
        cin >> d;
        cin.clear();
        cin.ignore(27147483647, '\n');
        if (cin.fail() || d < 'A' || (d > 'C' && d < 'a') || d > 'c')
        {
            continue;
        }
        if ((d >= 'A' && d <= 'C') || (d >= 'a' && d <= 'c'))
        {
            if (d >= 'a')
                d = char(d - 32);
            if (d == s) {
                if (d == 'A')
                    cout << "目标柱(A)不能与起始柱(A)相同" << endl;
                if (d == 'B')
                    cout << "目标柱(B)不能与起始柱(B)相同" << endl;
                if (d == 'C')
                    cout << "目标柱(C)不能与起始柱(C)相同" << endl;
                continue;
            }
            break;
        }
    }
    if (choice == 4||choice==8) {
        while (1) {
            cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)" << endl;
            cin >> delay;
            cin.clear();
            cin.ignore(27147483647, '\n');
            if (delay < 0 || delay>5 || cin.fail())
                continue;
            else
                break;
        }
    }
    *src = s;
    *dst = d;
    *tmp = char(65 + 66 + 67 - s - d);
    *n = num;
    *delay_time = delay;
    int i = 0, j = 0;
    for (i = 0; i < 3; i++) {
        	for (j = 0; j < 10; j++) {
        		col[i][j] = { 0 };
        	}
    }
        for (i = 0; i < 3; i++) {
        	top[i] = { 0 };
        }
    for (i = 0; i < num; i++)
        col[s - 65][i] = num - i;
    top[s - 65] = num;
}
void delete_abc(int x,int y,char abc[20])
{
    unsigned int i = 0;
    cct_gotoxy(x - strlen(abc), y);
    for (i = 0; i < strlen(abc); i++) {
        cout << "\b ";
    }
}
void input_judge(char*src,char*dst)
{
    char s = 0, d = 0;
    char abc[20] = { 0 };
    while (1) {
        cct_gotoxy(0, 32);
        cout << "请输入移动的柱号(命令形式：AC=A顶端的盘子移动到C，Q=退出) ：";
        unsigned int i = 0;
        for (i = 0; i < 10; i++) {
            cout << " ";
        } 
        int x = 0, y = 0;
        cct_getxy(x, y);
        cct_gotoxy(x - 10, y);
        cin >> abc;
        if (strlen(abc) == 1&&(abc[0] == 'Q' || abc[0] == 'q')) {
            s = abc[0];
            break;
        }
        if (strlen(abc) != 2) {
            cin.clear();
            cin.ignore(2147483647,'\n');
            continue;
        }
        s = abc[0];
        d = abc[1];
        if (s >= 'a')
            s = char(s - 32);
        if (d >= 'a')
            d = char(d - 32);
        if (s < 65 || s>67 || d < 65 || d>67) {
            cin.clear();
            cin.ignore(2147483647, '\n');
            s = 0, d = 0;
            continue;
        }
        if (top[s - 65] == 0 || col[d - 65][top[d - 65]] < col[s - 65][top[s - 65]]) {
            if (top[s - 65] == 0) {
                cout << "源柱为空！";
                Sleep(1000);
                cct_getxy(x, y);
                cct_gotoxy(x - strlen("源柱为空！"), y);
                for (i = 0; i < strlen("源柱为空！"); i++) {
                    cout << " ";
                }
            }
            else if (col[d - 65][top[d - 65]] < col[s - 65][top[s - 65]]) {
                cout << "大盘压小盘";
                Sleep(1000);
                cct_getxy(x, y);
                cct_gotoxy(x - strlen("大盘压小盘"), y);
                for (i = 0; i < strlen("大盘压小盘"); i++) {
                    cout << " ";
                }
            }
            cin.clear();
            cin.ignore(2147483647, '\n');
            s = 0, d = 0;
            continue;
        }
        break;
    }
    *src = s;
    *dst = d;
}
void game(char src,char tmp,char dst,int n,int delay_time,int choice)
{
    extern int count;
    draw(src, tmp, dst, n, delay_time, choice);
    cct_setcolor();
    print_zong(base8_x, base8_y);
    cct_gotoxy(0, base8_y + 6);
    cout << "初始:";
    count++;
    print_heng();//初始打印状态
    char src_change = 0, dst_change = 0;
    while (1) {
        input_judge(&src_change, &dst_change);
        if (src_change == 'Q' || src_change == 'q')
            break;
        col[dst_change - 65][top[dst_change - 65]++] = col[src_change - 65][--top[src_change - 65]];
        print_zong(base8_x, base8_y);
        cct_gotoxy(0, base8_y + 6);
        cout << "第 " << setw(3) << setiosflags(ios::right) << count << " 步(" << setw(2) << col[src_change-65][top[src_change-65]]<< "#: " << src_change << "-->" << dst_change << ")";
        count++;
        print_heng();
        move(src_change, dst_change);
        cct_setcolor();
        if (top[dst - 65]==n) {
            cct_gotoxy(0, 35);
            cout  << "游戏结束！！！";
            break;
        }
    }
}
