/* 2352467 �԰�ǿ ��08*/
#define _CRT_SECURE_NO_WARNINGS		//ʹ����VS��Ϊunsafe�ĺ���
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <ctime>
#include <conio.h>	//��getch����˲���Ҫ֧��Linux
#include <string.h>	//Dev/CB��strlen��Ҫ
using namespace std;

struct tj_time {
	int tj_year;	//��ʾ���
	int tj_month;	//��ʾ��(1-12)
	int tj_day;	//��ʾ��(1-28/29/30/31)
	int tj_hour;	//��ʾСʱ(0-23)
	int tj_minute;	//��ʾ��(0-59)
	int tj_second;	//��ʾ��(0-59)
};

/* �����ڴ˶���������Ҫ�ĺ��� */



/***************************************************************************
  �������ƣ�
  ��    �ܣ�������ʾ���ȴ��س���
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void wait_for_enter(const char *const prompt = NULL)
{
	if ((prompt == NULL) || (strlen(prompt) == 0)) //˼��һ�£�||���������������ܷ񻥻�
		cout << endl << "���س�������";
	else
		cout << endl << prompt << "�����س�������";

	while (_getch() != '\r')
		;
	cout << endl << endl;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�����ϵͳ��ת��������������ֵת��Ϊ�뱾�����ƵĽṹ�岢���
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void system_time_output(const time_t input_time)  //time_t�ı�����64λ�޷�������
{
    struct tm *tt;	//struct tm Ϊϵͳ����Ľṹ��

    tt = localtime(&input_time);	//localtimeΪϵͳ����

    /* tm_*** Ϊstruct tm�еĳ�Ա���ͱ����struct tj_time��������ݲ���ȫ���ϣ����庬���Լ������������ */
    cout << setfill('0') << setw(4) << tt->tm_year+1900 << '-' 
						<< setw(2) << tt->tm_mon + 1 << '-' 
						<< setw(2) << tt->tm_mday << ' ' 
						<< setw(2) << tt->tm_hour << ':' 
						<< setw(2) << tt->tm_min << ':' 
						<< setw(2) << tt->tm_sec << endl;

    return;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ��Զ���ת������������
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void tj_time_output(const struct tj_time *const tp)
{
    /* ʵ���Զ���ṹ������������ʽ��system_time_output��ͬ */
    cout << setfill('0') << setw(4) << tp->tj_year << '-' 
						<< setw(2) << tp->tj_month << '-' 
						<< setw(2) << tp->tj_day << ' '
						<< setw(2) << tp->tj_hour << ':' 
						<< setw(2) << tp->tj_minute << ':'
						<< setw(2) << tp->tj_second << endl;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ��Զ���ת������
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
struct tj_time *tj_time_convert(int input_time)
{
    static struct tj_time result;	//���徲̬�ֲ���������׼��

    /* ʵ�ֹ��̿�ʼ��������������Ӧ�Ķ��弰ִ����伴�� */
	result.tj_year = 1970;
	result.tj_month = 1;
	result.tj_day = 1;
	result.tj_hour = 0;
	result.tj_minute = 0;
	result.tj_second = 0;
	input_time += 8 * 3600;
	int leap = (result.tj_year % 4 == 0 && result.tj_year % 100 != 0) || (result.tj_year % 400 == 0);
	while ((leap == 1 && input_time >= 366 * 24 * 3600) || (leap == 0 && input_time >= 365 * 24 * 3600)) {
		result.tj_year++;
		if (leap)
			input_time -= 366 * 24 * 3600;
		else
			input_time -= 365 * 24 * 3600;
		leap = (result.tj_year % 4 == 0 && result.tj_year % 100 != 0) || (result.tj_year % 400 == 0);
	}
	int judge_month = 0;
	switch (result.tj_month) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		judge_month = 1;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		judge_month = 2;
		break;
	case 2:
		judge_month = 3;
		break;
	}
	while((judge_month == 1 && input_time >= 31 * 24 * 3600) || (judge_month == 2 && input_time >= 30 * 24 * 3600) || (judge_month == 3 && input_time >= (28 + leap) * 24 * 3600)){
		result.tj_month++;
		if (judge_month == 1)
			input_time -= 31 * 24 * 3600;
		else if (judge_month == 2)
			input_time -= 30 * 24 * 3600;
		else
			input_time -= (28 + leap) * 24 * 3600;
		switch (result.tj_month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			judge_month = 1;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			judge_month = 2;
			break;
		case 2:
			judge_month = 3;
			break;
		}
	}
	while (input_time >= 24 * 3600) {
		result.tj_day++;
		input_time -= 24 * 3600;
	}
	while (input_time >= 3600) {
		result.tj_hour++;
		input_time -= 3600;
	}
	while (input_time >= 60) {
		result.tj_minute++;
		input_time -= 60;
	}
	result.tj_second += input_time;
    /* ʵ�ֹ��̽��� */

    return &result;	//ע�⣬���ص��Ǿ�̬�ֲ������ĵ�ַ������䲻׼��
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
	int read_time;
	struct tj_time *tp;

	for (;;) {
		cin >> read_time; //��Ϊ���������ض��򣬴˴������κ���ʾ

		/* ��������<0���˳�ѭ�� */
		if (cin.good() == 0 || read_time < 0)
			break;

		cout << "����             : " << read_time << endl;
		cout << "ϵͳת���Ľ��   : ";
		system_time_output(read_time);
	
		cout << "�Զ���ת���Ľ�� : ";
		tp = tj_time_convert(read_time);
		tj_time_output(tp);

		wait_for_enter();
		}

	if (1) {
		struct tj_time *tp;
		int t=(int)time(0);		//ϵͳ������ȡ��ǰϵͳʱ�䣨��1970-01-01 00:00:00��ʼ��������

		cout << "��ǰϵͳʱ��     : " << t << endl;
		cout << "ϵͳת���Ľ��   : ";
		system_time_output(t);
	
		cout << "�Զ���ת���Ľ�� : ";
		tp = tj_time_convert(t);
		tj_time_output(tp);

		wait_for_enter();
		}

	return 0;
}