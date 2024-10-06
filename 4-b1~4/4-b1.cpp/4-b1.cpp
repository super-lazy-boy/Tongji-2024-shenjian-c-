/* 2352467 赵阿强 信08 */
#include <iostream>
using namespace std;

/* 可根据需要添加相应的内容 */

/***************************************************************************
  函数名称：
  功    能：输出大写的0~9
  输入参数：num flag_of_zero
  返 回 值：
  说    明：除本函数外，不允许任何函数中输出“零”-“玖”!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* 不允许对本函数做任何修改 */
	switch (num) {
	case 0:
		if (flag_of_zero)	//此标记什么意思请自行思考
			cout << "零";
		break;
	case 1:
		cout << "壹";
		break;
	case 2:
		cout << "贰";
		break;
	case 3:
		cout << "叁";
		break;
	case 4:
		cout << "肆";
		break;
	case 5:
		cout << "伍";
		break;
	case 6:
		cout << "陆";
		break;
	case 7:
		cout << "柒";
		break;
	case 8:
		cout << "捌";
		break;
	case 9:
		cout << "玖";
		break;
	default:
		cout << "error";
		break;
	}
}


/* 可根据需要自定义其它函数(也可以不定义) */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	/* 按需完成 */
	cout << "请输入[0-100亿)之间的数字:" << endl;
	double num;
	cin >> num;
	int a=0, b, d, e, f, g, h, i, j, k, l, m=0;
	double c = 1e9;
	double num1 = 0;//创建用于比较前面是否有零
	num1 = num =num+0.005;
	a = (int)(num / c);
	num = num - a * c;
	c /= 10;
	b = (int)(num / c);
	num = num - b * c;
	c /= 10;
	d = (int)(num / c);
	num = num - d * c;
	c /= 10;
	e = (int)(num / c);
	num = num - e * c;
	c /= 10;
	f = (int)(num / c);
	num = num - f * c;
	c /= 10;
	g = (int)(num / c);
	num = num - g * c;
	c /= 10;
	h = (int)(num / c);
	num = num - h * c;
	c /= 10;
	i = (int)(num / c);
	num = num - i * c;
	c /= 10;
	j = (int)(num / c);
	num = num - j * c;
	c /= 10;
	k = (int)(num / c);
	num = num - k * c;
	c /= 10;
	l = (int)(num / c);
	num = num - l * c;
	c /= 10;
	m = (int)(num / c);
	cout << "大写结果是:" << endl;
	daxie(a, 0);
	if (a != 0)
		cout << "拾";
	daxie(b, 0);
	if (num1 > 1e8)
		cout << "亿";

	daxie(d, (a+b)*e);
	if (d != 0)
		cout << "仟";
	daxie(e, (a+b+d)*f);
	if (e != 0)
		cout << "佰";
	daxie(f,(a+b+d+e)*g);
	if (f != 0)
		cout << "拾";
	daxie(g, 0);
	if (g+d+f+e>0)
		cout << "万";
		
	daxie(h, (a+b+d+e+f+g)*i);
	if (h != 0)
		cout << "仟";
	daxie(i, (a+b+d+e+f+g+h)*j);
	if (i != 0)
		cout << "佰";
	daxie(j, (a+b+d+e+f+g+h+i)*k);
	if (j != 0)
		cout << "拾";
	daxie(k, num1-0.005==0);
	if (num1>1||num1-0.005==0)
		cout << "圆";

	daxie(l, (a+b+d+e+f+g+h+i+j+k)*m);
	if (l != 0)
		cout << "角";
	daxie(m, 0);
	if (m != 0)
		cout << "分";

	if (m == 0 || (m == 0 && l == 0))
		cout << "整";
	cout << endl;
	return 0;
}