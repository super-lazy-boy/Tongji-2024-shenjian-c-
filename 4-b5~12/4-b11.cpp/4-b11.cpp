/* 2352467 信08 赵阿强 */
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		允许   ：1、按需增加一个或多个函数（包括递归函数），但是所有增加的函数中不允许任何形式的循环
				 2、定义符号常量
				 3、定义const型变量

		不允许 ：1、定义全局变量
				 2、除print_tower之外的其他函数中不允许定义静态局部变量
   ----------------------------------------------------------------------------------- */
void print_row(char start_char,char end_ch,int count)
{
	if (count<(end_ch-'A'+1) ){
		cout << char(start_char);
		count++;
		if (count < (end_ch - 'A' + 1))
			print_row(char(start_char - 1), end_ch, count);
		else
			print_row(char(start_char + 1), end_ch, count);
	}
	else {
		if (count <= (2 * (end_ch - 'A'))) {
			cout  << char(start_char);
			count++;
			print_row(char(start_char + 1), end_ch, count);
		}
	}
}
   /***************************************************************************
	 函数名称：
	 功    能：打印字母塔
	 输入参数：
	 返 回 值：
	 说    明：形参按需设置
			   提示：有一个参数order，指定正序/倒序
   ***************************************************************************/
void print_tower(char start_ch,bool order,char end_ch,char maintain)
{
	/* 允许按需定义最多一个静态局部变量（也可以不定义） */
    /* 按需实现，函数中不允许任何形式的循环，函数允许调用其它函数 */
	if (order)
	{
		if((int)start_ch>(int)end_ch)
		print_tower(char(start_ch - 1), 1,end_ch,maintain);
		if (maintain != start_ch) 
			cout << setw(maintain - start_ch) << setfill(' ') << " ";
		print_row(start_ch, start_ch, 0);
		if (maintain != start_ch)
			cout << setw(maintain - start_ch) << setfill(' ') << " ";
		
			cout << endl;
	}
	else {
		if (maintain != start_ch)
			cout << setw(maintain - start_ch) << setfill(' ') << " ";
		print_row(start_ch, start_ch, 0);
		if (maintain != start_ch)
			cout << setw(maintain - start_ch) << setfill(' ') << " ";
		cout << endl;
		if((int)start_ch>(int)end_ch)
		print_tower(char(start_ch - 1), 0,end_ch,maintain);
	}
}



/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数中的...允许修改，其余位置不准修改
***************************************************************************/
int main()
{
	char end_ch;

	/* 键盘输入结束字符(仅大写有效，为避免循环出现，不处理输入错误) */
	cout << "请输入结束字符(A~Z)" << endl;
	end_ch = getchar();			//读缓冲区第一个字符
	if (end_ch < 'A' || end_ch > 'Z') {
		cout << "结束字符不是大写字母" << endl;
		return -1;
	}

	/* 正三角字母塔(中间为A) */
	cout <<setfill('=') << setw(2 * (end_ch - 'A') + 1)<<'=' << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	cout << "正三角字母塔(" << end_ch << "->A)" << endl;
	cout << setfill('=') << setw(2 * (end_ch - 'A') + 1) << '=' << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	print_tower(end_ch,1,'A',end_ch); //正序打印 A~结束字符 
	cout << endl;

	/* 倒三角字母塔(中间为A) */
	cout << setfill('=') << setw(2 * (end_ch - 'A') + 1) << '=' << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	cout << "倒三角字母塔(" << end_ch << "->A)" << endl;
	cout << setfill('=') << setw(2 * (end_ch - 'A') + 1) << '=' << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	print_tower(end_ch,0,'A',end_ch); //逆序打印 A~结束字符 
	cout << endl;

	/* 合起来就是漂亮的菱形（中间为A） */
	cout << setfill('=') << setw(2 * (end_ch - 'A') + 1) << '=' << endl;/* 按字母塔最大宽度输出= */
	cout << "菱形(" << end_ch << "->A)" << endl;
	cout << setfill('=') << setw(2 * (end_ch - 'A') + 1) << '=' << endl;/* 按字母塔最大宽度输出= */
	print_tower(end_ch,1,'A',end_ch);   //打印 A~结束字符的正三角 
	print_tower(char(end_ch-1),0,'A',end_ch);   //打印 A~结束字符-1的倒三角 
	cout << endl;

	return 0;
}
