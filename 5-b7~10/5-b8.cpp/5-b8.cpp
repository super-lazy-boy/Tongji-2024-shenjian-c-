/*2352467 �԰�ǿ ��08*/
#include <iostream>
#include <iomanip>
#include <conio.h>
#include<limits>
using namespace std;

#define N_POW	112		//�ݵĴ���
#define N_NUM	N_POW+1	//ʮ������ʽ��С��λ��

/***************************************************************************
  �������ƣ�
  ��    �ܣ����ĳһ�е��ݴΣ�ĳ��һά��������ݣ�
  ���������
  �� �� ֵ��
  ˵    ����pormptΪ�ǿմ������������
				  Ϊ�մ��������2^-xxx���������demo
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
  �������ƣ�
  ��    �ܣ��ö�ά�����i�е�ֵ�������i+1��
  ���������
  �� �� ֵ��
  ˵    ����
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
  �������ƣ�
  ��    �ܣ������ݴα�������ĳ��������С����ʮ����ֵ
  ���������char pure_decimal[] : ��Ŷ�����С��������
            char out[] ����ż���õ���ʮ����С��
		   char power_table[][N_NUM + 1]���ݴα�
  �� �� ֵ��
  ˵    ����
 ***************************************************************************/
void calc_num(int pure_decimal_int[], char out[], int power_table[][N_NUM + 1])
{
	unsigned int i = 0, j = 0;
	/*int calc[N_NUM + 1] = { 0 };*/
	//for (i = 1; i < strlen(pure_decimal)+1; i++) {
	//	calc[i] = pure_decimal[i] - 48;
	//}//���ַ�ת��Ϊ��������
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
  �������ƣ�
  ��    �ܣ�����һ�������ƴ�С��
  ���������
  �� �� ֵ��
  ˵    ����
 ***************************************************************************/
void input_pure_decimal(char pure_decimal[])
{
	int i = 0;
	int num = 0;
	cout << "������һ�������ƴ�С����С���㿪ͷ��С����󲻳���112λ(����.101101)" << endl;
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
		cout << "������.��ͷ��������" << endl;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		input_pure_decimal(pure_decimal);
	}
	
	for (i = 1;i<num; i++) {
		if (pure_decimal[i] != 1 && pure_decimal[i] != 0) {
			cout << "����Ĳ���0/1��������" << endl;
			for (i = 0; i < num; i++) {
				pure_decimal[i] = '\0';
			}
			input_pure_decimal(pure_decimal);
		}
	}
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������is_upper ��1 - �ϱ��
						 0 - �±��
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void output_rod(const bool is_upper)
{
	if (is_upper) { //�ϱ��
		cout << "-----------------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "----------- �ϱ��  1         2         3         4         5         6         7         8         9         A         B         C" << endl;
		cout << "-----------123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890" << endl;
		cout << "-----------------------------------------------------------------------------------------------------------------------------------" << endl;
	}
	else {//�±��
		cout << "-----------------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "-----------123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890" << endl;
		cout << "----------- �±��  1         2         3         4         5         6         7         8         9         A         B         C" << endl;
		cout << "-----------------------------------------------------------------------------------------------------------------------------------" << endl;
	}
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
	/* ˵�������ȶ��� power_table[113][114]�����Ϊȫ0���ٽ��г�ʼ��
	*
	*  1����[0]���������ã�[1]~[112] ��2^-1 ~ 2^-112 ��Ӧ�������Ҫ113��
	*  2����[0]�д���ݴΣ�[1]~[112]�����δ��ʮ��λ���ٷ�λ��ǧ��λ��...  ��2^-i�η���ʮ����С�������iλ����[113]Ԥ��������ĳЩ����Ҫ�󣬱���\0
	*  2��ÿ�еĵ�0�д���ݴΣ�[1]~��ʼ���ʮ���Ƶ�ÿһλ���Ӷ��ﵽ�߾��ȴ�ŵ�Ŀ��
	*     ����        ��[0]��  ��[1]��  ��[2]��  ��[3]��  ��[4]�� ...
	*		��[1]��   -1     5        0        0        0		//��ʾ0.5
	*		��[2]��   -2     2        5        0        0		//��ʾ0.25
	*		��[3]��   -3     1        2        5        0		//��ʾ0.125
	*		��[4]��   -4     0        6        2        5		//��ʾ0.0625
	*			...
	*		��[112]�� -112   ...
	*
	ע��1������ά��������ͣ��ȿ�����int��Ҳ������char����Ϊ����ʱ��ÿ��Ԫ�ص�ֵ����0-9֮�䣬��char�㹻�ˣ�char�����ʱע������0-9���ַ�0-9�����⼴�ɣ�
		2����Ϊ��ˣ�������������ۺ�ѵ���У���û�з����ַ�������
	*/
	int power_table[N_POW + 1][N_NUM + 1] = { 0 }; //��ȫ����ʼ��Ϊ0
	int i = 0;

	/* ��ʼ����[0]�������ݴΣ���ʼ����Ľ��Ϊ��
	   ��|��  [0]   [1]   [2]
	   [0]     0     0     0  //���в���
	   [1]     1     5     0  // 2^-1 ��ʼ��Ϊ0.5
	   [2]     2     0     0
	   ...
	   [112]   -112  0     0
	*/
	for (i = 1; i <= N_POW; i++) {
		power_table[i][0] = i; //�ݴ� -1 ~ -112
	}
	power_table[1][1] = {5}; // 2^-1 = 0.5������[1][1]Ϊ5

	/* ѭ����ʽ�����ݱ���
	   1����ά�����һ���±꣬��ʾһ����СΪ114��һά����
	   2��2^-1Ϊ��֪��0.5��power_table[1]������Ϊ -1 5 0 0 0 ... 0
	*/
	for (i = 1; i < N_POW; i++)
		calc_next(power_table[i], power_table[i+1]); //��֪2^-i����2^-(i+1)

	/* �ϱ�� */
	output_rod(1);

	/* ��� */
	for (i = 1; i <= N_POW; i++)
		output("", power_table[i],i);

	/* �±�� */
	output_rod(0);
	cout << endl;

	/* ����һ�������ƴ�С�� */
	unsigned int j = 0;
	char pure_decimal[N_NUM + 1] = { 0 };
	int pure_decimal_int[N_NUM + 1] = { 0 };
	input_pure_decimal(pure_decimal);
	for (j = 0; j < strlen(pure_decimal); j++) {
		if(pure_decimal[j+1]!=0)
		pure_decimal_int[j] = pure_decimal[j + 1] - 48;
	}
	int length = strlen(pure_decimal) - 1;
	/* �ϱ�� */
	output_rod(1);

	output("�������� : ", pure_decimal_int,length);
	char out[N_NUM + 1] = { 0 };
	int outnum[N_NUM + 1] = { 0 };
	calc_num(pure_decimal_int, out, power_table);
	for (j = 0; j < strlen(out); j++) {
		outnum[j] = out[j] - 48;
	}
	length = strlen(out);
	output("����ֵ : 0.", outnum, length);
	/* �±�� */
	output_rod(0);

	cout << endl;

	return 0;
}

/*
PPT����Ĳ�������
.00110011001100110011010
*/