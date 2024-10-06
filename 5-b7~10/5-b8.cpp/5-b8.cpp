/*2352467 赵阿强 信08*/
#include <iostream>
#include <iomanip>
#include <conio.h>
#include<limits>
using namespace std;

#define N_POW	112		//幂的次数
#define N_NUM	N_POW+1	//十进制形式的小数位数

/***************************************************************************
  函数名称：
  功    能：输出某一行的幂次（某个一维数组的内容）
  输入参数：
  返 回 值：
  说    明：pormpt为非空串则输出串内容
				  为空串则输出“2^-xxx”，具体见demo
***************************************************************************/
void output(const char prompt[],  int d[],int length)
{
    int i = 0, j = 0;
	if (strlen(prompt) == 0)
	{
		cout << "2^-" <<setw(3)<<d[0] << " : 0.";
		for (j = 1; j < length+1; j++) {
			cout << d[j];
		}
		cout << endl;

	}
	else {
		cout << prompt ;
		for (i = 0; i < length; i++) {
			cout << d[i];
		}
		cout << endl;
	}
}

/***************************************************************************
  函数名称：
  功    能：用二维数组第i行的值，计算第i+1行
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void calc_next(int d_cur[], int d_next[])
{
	int i = 0;
	int num = 0, num1 = 0, num2 = 0;
	for (i = 1; i <=N_NUM; i++) {
		/*num = d_cur[i] - 48;
		num1 = d_next[i] - 48;
		num1 += num * 10 / 2 / 10;
		num2= num * 10 / 2 % 10;
		d_next[i] = char(num1+48) ;
		if (i < N_NUM)
			d_next[i + 1] = char(num2 + 48);*/
		d_next[i] += d_cur[i] * 10 / 2 / 10;
		if (i < N_NUM)
			d_next[i+1]=d_cur[i] * 10 / 2 % 10;
	}
}

/***************************************************************************
  函数名称：
  功    能：根据幂次表，计算某个二进制小数的十进制值
  输入参数：char pure_decimal[] : 存放二进制小数的数组
            char out[] ：存放计算得到的十进制小数
		   char power_table[][N_NUM + 1]：幂次表
  返 回 值：
  说    明：
 ***************************************************************************/
void calc_num(int pure_decimal_int[], char out[], int power_table[][N_NUM + 1])
{
	unsigned int i = 0, j = 0;
	/*int calc[N_NUM + 1] = { 0 };*/
	//for (i = 1; i < strlen(pure_decimal)+1; i++) {
	//	calc[i] = pure_decimal[i] - 48;
	//}//将字符转化为整型数字
	//int table[N_POW + 1][N_NUM + 1] = { 0 };
	//for (i = 1; i <= N_POW; i++) {
	//	for (j = 1; j <= N_NUM; j++) {
	//		table[i][j] = power_table[i][j] - 48;
	//	}
	//}
	int output[N_NUM + 1] = { 0 };
	for (i = 1; i <= N_POW; i++) {
		for (j = 1; j <= N_NUM; j++) {
			power_table[i][j] *= pure_decimal_int[i-1];
		}
	}
	int num = 0;
	for (i = N_NUM; i >=1; i--) {
		for (j = 1; j <= N_POW; j++) {
			output[i] += power_table[j][i];
		}
		if (output[i] > 9&&i>1) {
			output[i - 1] = output[i] / 10;
			output[i] = output[i] % 10;
		}
		if (output[i] > 0)
			num++;
	}
	char out1[N_NUM + 1] = { 0 };

	for (i = 1; i <= num+1; i++) {
		out[i - 1] = char(output[i] + 48);
	}
	/*int calc[N_POW][N_NUM] = { 0 };
	for (i = 0; i < strlen(pure_decimal); i++) {
		for (j = 1; j < N_NUM; j++) {
			calc[i][j] = (pure_decimal[i] - 48) * (power_table[i][j]-48) ;
		}
	}
	int sum[N_POW] = { 0 };
	for (i = 0; i < N_POW; i++) {
		for (j = 1; j < N_NUM; j++) {
			sum[i] += calc[i][j];
		}
	}
	for (i = N_POW - 1; i > 0; i--) {
		sum[i] = sum[i] % 10;
		sum[i - 1] += sum[i] / 10;
	}
	for (i = 0; i < N_POW; i++) {
		out[i] = char(sum[i] + 48);
	}*/
}

/***************************************************************************
  函数名称：
  功    能：输入一个二进制纯小数
  输入参数：
  返 回 值：
  说    明：
 ***************************************************************************/
void input_pure_decimal(char pure_decimal[])
{
	int i = 0;
	int num = 0;
	cout << "请输入一个二进制纯小数，小数点开头，小数点后不超过112位(例：.101101)" << endl;
	cin >> pure_decimal;
	/*for (i = 0;; i++) {
		cin>>pure_decimal;
		if (pure_decimal[i] == 13) {
			pure_decimal[i] = 0;
			num = i + 1;
			break;
		}
	}*/
	if (pure_decimal[0] != '.') {
		cout << "不是以.开头，请重输" << endl;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		input_pure_decimal(pure_decimal);
	}
	
	for (i = 1;i<num; i++) {
		if (pure_decimal[i] != 1 && pure_decimal[i] != 0) {
			cout << "输入的不是0/1，请重输" << endl;
			for (i = 0; i < num; i++) {
				pure_decimal[i] = '\0';
			}
			input_pure_decimal(pure_decimal);
		}
	}
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：is_upper ：1 - 上标尺
						 0 - 下标尺
  返 回 值：
  说    明：
***************************************************************************/
void output_rod(const bool is_upper)
{
	if (is_upper) { //上标尺
		cout << "-----------------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "----------- 上标尺  1         2         3         4         5         6         7         8         9         A         B         C" << endl;
		cout << "-----------123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890" << endl;
		cout << "-----------------------------------------------------------------------------------------------------------------------------------" << endl;
	}
	else {//下标尺
		cout << "-----------------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "-----------123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890" << endl;
		cout << "----------- 下标尺  1         2         3         4         5         6         7         8         9         A         B         C" << endl;
		cout << "-----------------------------------------------------------------------------------------------------------------------------------" << endl;
	}
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	/* 说明：首先定义 power_table[113][114]，输出为全0，再进行初始化
	*
	*  1、第[0]行整个不用，[1]~[112] 与2^-1 ~ 2^-112 对应，因此需要113行
	*  2、第[0]列存放幂次，[1]~[112]列依次存放十分位、百分位、千分位、...  （2^-i次方的十进制小数，最多i位），[113]预留，用于某些特殊要求，比如\0
	*  2、每行的第0列存放幂次，[1]~开始存放十进制的每一位，从而达到高精度存放的目的
	*     例：        第[0]列  第[1]列  第[2]列  第[3]列  第[4]列 ...
	*		第[1]行   -1     5        0        0        0		//表示0.5
	*		第[2]行   -2     2        5        0        0		//表示0.25
	*		第[3]行   -3     1        2        5        0		//表示0.125
	*		第[4]行   -4     0        6        2        5		//表示0.0625
	*			...
	*		第[112]行 -112   ...
	*
	注：1、本二维数组的类型，既可以是int，也可以是char，因为计算时，每个元素的值都在0-9之间，用char足够了（char型输出时注意数字0-9和字符0-9的问题即可）
		2、因为如此，本题放在数组综合训练中，而没有放在字符数组中
	*/
	int power_table[N_POW + 1][N_NUM + 1] = { 0 }; //先全部初始化为0
	int i = 0;

	/* 初始化，[0]里面存放幂次，初始化后的结果为：
	   行|列  [0]   [1]   [2]
	   [0]     0     0     0  //本行不用
	   [1]     1     5     0  // 2^-1 初始化为0.5
	   [2]     2     0     0
	   ...
	   [112]   -112  0     0
	*/
	for (i = 1; i <= N_POW; i++) {
		power_table[i][0] = i; //幂次 -1 ~ -112
	}
	power_table[1][1] = {5}; // 2^-1 = 0.5，先置[1][1]为5

	/* 循环方式计算幂表：
	   1、二维数组带一个下标，表示一个大小为114的一维数组
	   2、2^-1为已知的0.5，power_table[1]的内容为 -1 5 0 0 0 ... 0
	*/
	for (i = 1; i < N_POW; i++)
		calc_next(power_table[i], power_table[i+1]); //已知2^-i，求2^-(i+1)

	/* 上标尺 */
	output_rod(1);

	/* 输出 */
	for (i = 1; i <= N_POW; i++)
		output("", power_table[i],i);

	/* 下标尺 */
	output_rod(0);
	cout << endl;

	/* 输入一个二进制纯小数 */
	unsigned int j = 0;
	char pure_decimal[N_NUM + 1] = { 0 };
	int pure_decimal_int[N_NUM + 1] = { 0 };
	input_pure_decimal(pure_decimal);
	for (j = 0; j < strlen(pure_decimal); j++) {
		if(pure_decimal[j+1]!=0)
		pure_decimal_int[j] = pure_decimal[j + 1] - 48;
	}
	int length = strlen(pure_decimal) - 1;
	/* 上标尺 */
	output_rod(1);

	output("输入数据 : ", pure_decimal_int,length);
	char out[N_NUM + 1] = { 0 };
	int outnum[N_NUM + 1] = { 0 };
	calc_num(pure_decimal_int, out, power_table);
	for (j = 0; j < strlen(out); j++) {
		outnum[j] = out[j] - 48;
	}
	length = strlen(out);
	output("计算值 : 0.", outnum, length);
	/* 下标尺 */
	output_rod(0);

	cout << endl;

	return 0;
}

/*
PPT例题的测试数据
.00110011001100110011010
*/
