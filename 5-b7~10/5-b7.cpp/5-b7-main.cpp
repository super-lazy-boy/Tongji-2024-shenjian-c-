/*2352467 赵阿强 信08*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <conio.h>
#include <windows.h>
#include "5-b7.h"
using namespace std;


int top_a = 0;
int top_b = 0;
int top_c = 0;
int a[10], b[10], c[10];
int delay = 0;
bool show = 0;

void printabc_zong()
{
    cct_gotoxy(10, 11);
    cout << setfill('=') << setw(25) << "=";
    cct_gotoxy(13, 12);
    cout << 'A';
    cct_gotoxy(23, 12);
    cout << 'B';
    cct_gotoxy(33, 12);
    cout << 'C';

    int i = 0;
    int j = 10;
    cout << setfill(' ');
    cct_gotoxy(13, 10);
    for (i = 0, j = 10; i < 10; i++) {
        if (a[i] > 0 && i < top_a)
            cout << setw(2) << setiosflags(ios::right) << a[i];
        else
            cout << "  ";
        j--;
        cct_gotoxy(13, j);
    }
    cct_gotoxy(23, 10);
    for (i = 0, j = 10; i < 10; i++) {
        if (b[i] > 0 && i < top_b)
            cout << setw(2) << setiosflags(ios::right) << b[i];
        else
            cout << "  ";
        j--;
        cct_gotoxy(23, j);
    }
    cct_gotoxy(33,10);
    for (i = 0, j = 10; i < 10; i++) {
        if (c[i] > 0 && i < top_c)
            cout << setw(2) << setiosflags(ios::right) << c[i];
        else
            cout << "  ";
        j--;
        cct_gotoxy(33, j);
    }
}
void printabc_heng()
{
    cout<<"A: ";
    int i = 0;
    for (i = 0; i < 10; i++) {
        if (a[i] > 0 && i < top_a)
            cout << setw(2) << setiosflags(ios::right) << a[i];
        else
            cout << "  ";
    }
    cout << "B: ";
    for (i = 0; i < 10; i++) {
        if (b[i] > 0 && i < top_b)
            cout << setw(2) << setiosflags(ios::right) << b[i];
        else
            cout << "  ";
    }
    cout << "C: ";
    for (i = 0; i < 10; i++) {
        if (c[i] > 0 && i < top_c)
            cout << setw(2) << setiosflags(ios::right) << c[i];
        else
            cout << "  ";
    }
}
void delay_time(int delay)
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
void hanoi(int n, char src, char tmp, char dst)
{
    if (n >= 2)
        hanoi(n - 1, src, dst, tmp);


    static int count = 0;
    count++;
    cct_gotoxy(16,22);
    cout << "第" <<setfill(' ') << setw(4) << setiosflags(ios::right) << count << " 步(" << setw(2) << n << "#: " << src << "-->" << dst << ")  ";
    int change = 0;
    switch ((int)src)
    {
    case 65:
        change = a[--top_a];
        break;
    case 66:
        change = b[--top_b];
        break;
    case 67:
        change = c[--top_c];
        break;
    }
    switch ((int)dst)
    {
    case 65:
        a[top_a++] = change;
        break;
    case 66:
        b[top_b++] = change;
        break;
    case 67:
        c[top_c++] = change;
        break;
    }
    if (show)
        printabc_heng();
    printabc_zong();
    delay_time(delay);

    if (n >= 2)
        hanoi(n - 1, tmp, src, dst);
}
int main()
{
    int n = 0;
    char src, tmp, dst;
    while (1) {
        cout << "请输入汉诺塔的层数(1-16)" << endl;
        cin >> n;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(27147483647, '\n');
            continue;
        }
        if (n >= 1 && n <= 16)
        {
            cin.clear();
            cin.ignore(27147483647, '\n');
            break;
        }
    }
    while (1) {
        cout << "请输入起始柱(A-C)" << endl;
        cin >> src;
        cin.clear();
        cin.ignore(27147483647, '\n');
        if (cin.fail() || src < 'A' || (src > 'C' && src < 'a') || src > 'c')
        {
            continue;
        }
        if ((src >= 'A' && src <= 'C') || (src >= 'a' && src <= 'c'))
        {
            if (src >= 'a')
                src = char(src - 32);
            break;
        }
    }
    while (1) {
        cout << "请输入目标柱(A-C)" << endl;
        cin >> dst;
        cin.clear();
        cin.ignore(27147483647, '\n');
        if (cin.fail() || dst < 'A' || (dst > 'C' && dst < 'a') || dst > 'c')
        {
            continue;
        }
        if ((dst >= 'A' && dst <= 'C') || (dst >= 'a' && dst <= 'c'))
        {
            if (dst >= 'a')
                dst = char(dst - 32);
            if (dst == src) {
                if (dst == 'A')
                    cout << "目标柱(A)不能与起始柱(A)相同" << endl;
                if (dst == 'B')
                    cout << "目标柱(B)不能与起始柱(B)相同" << endl;
                if (dst == 'C')
                    cout << "目标柱(C)不能与起始柱(C)相同" << endl;
                continue;
            }
            break;
        }
    }
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
    while (1) {
        cout << "请输入是否显示内部数组值(0-不显示 1-显示)" << endl;
        cin >> show;
        cin.clear();
        cin.ignore(27147483647, '\n');
        if (show != 0 && show != 1 || cin.fail())
            continue;
        else
            break;
    }
    int i = 0;
    tmp = (char)(65 + 66 + 67 - src - dst);
    switch ((int)src)
    {
    case 65:
        for (i = 0; i < n; i++) {
            a[i] = n - i;
        }
        top_a = n;
        break;
    case 66:
        for (i = 0; i < n; i++) {
            b[i] = n - i;
        }
        top_b = n;
        break;
    case 67:
        for (i = 0; i < n; i++) {
            c[i] = n - i;
        }
        top_c = n;
        break;
    }//初始化起始柱
    cct_cls();
    cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层，延时设置为 " << delay << "，";
    if (show)
        cout << "显示内部数组值";
    else
        cout << "不显示内部数组值";
    cct_gotoxy(16,22);
    cout << "初始:                ";
    printabc_heng();
    delay_time(delay);
    printabc_zong();
    hanoi(n,src,tmp,dst);
    cct_gotoxy(30, 30);
	system("pause"); //最后用这句表示暂停（注意：只适合于特定程序，无特别声明的程序加此句则得分为0）
	return 0;
}
