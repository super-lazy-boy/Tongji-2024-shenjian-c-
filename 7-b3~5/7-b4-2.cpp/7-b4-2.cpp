/* 2352467 赵阿强 信08 */
#include <iostream>
#include <cmath>
using namespace std;

class triangle;  //类的提前声明，思考一下，放在这里的目的是为什么
class point {
private:
	int x;
	int y;
public:
	/* 仅允许在此添加一个成员函数【仅限1个】,要求体内实现 */
	void set(int px, int py)
	{
		x = px;
		y = py;
	}
	/* 除上面允许的那个成员函数外，不再允许添加任何的数据成员和成员函数，但可以根据需要添加其它内容 */
	friend int get_x(point &p);
	friend int get_y(point& p);
};

int get_x(point& p)
{
	return p.x;
}
int get_y(point& p)
{
	return p.y;
}

class triangle {
private:
	point p1;
	point p2;
	point p3;
public:
	/* 根据需要补充相应的语句后完成area函数(形参为空，不准改)，要求：如果三点能构成三角形，则返回面积，否则返回 -1 */
	double area()
	{
		double s1 = 0, s2 = 0, s3 = 0;
		s1 = sqrt((get_x(p1) - get_x(p2)) * (get_x(p1) - get_x(p2)) + (get_y(p1) - get_y(p2)) * (get_y(p1) - get_y(p2)));
		s2 = sqrt((get_x(p1) - get_x(p3)) * (get_x(p1) - get_x(p3)) + (get_y(p1) - get_y(p3)) * (get_y(p1) - get_y(p3)));
		s3 = sqrt((get_x(p2) - get_x(p3)) * (get_x(p2) - get_x(p3)) + (get_y(p2) - get_y(p3)) * (get_y(p2) - get_y(p3)));
		double maxs = s1 > s2 ? s1 : s2;
		maxs = maxs > s3 ? maxs : s3;
		double p = (s1 + s2 + s3) / 2;
		if (s1 + s2 + s3 > 2 * maxs)
			return sqrt(p * (p - s1) * (p - s2) * (p - s3));
		else
			return -1;
	}
	/* 构造函数 */
	triangle(int p1_x, int p1_y, int p2_x, int p2_y, int p3_x, int p3_y)
	{
		/* 给p1/p2/p3三个点分别赋x,y坐标值 */
		p1.set(p1_x, p1_y);
		p2.set(p2_x, p2_y);
		p3.set(p3_x, p3_y);
	}
	/* 可以定义需要的成员函数，数量不限，并以体内方式实现，不允许添加数据成员 */

};

/* -- 替换标记行 -- 本行不要做任何改动 -- 本行不要删除 -- 在本行的下面不要加入任何自己的语句，作业提交后从本行开始会被替换 -- 替换标记行 -- */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准动
***************************************************************************/
int main()
{
	if (1) {
		triangle tr(0, 0, 0, 1, 1, 0);  //三角形为(0,0) (0,1) (1,0)三点组成
		cout << "三角形面积应该是：0.5，实际是：" << tr.area() << endl;
	}

	if (1) {
		triangle tr(0, 2, -1, -1, 1, -1);  //三角形为(0,2) (-1,-1) (1,-1)三点组成
		cout << "三角形面积应该是：3，  实际是：" << tr.area() << endl;
		}

	if (1) {
		triangle tr(5, 5, -3, 1, 9, -2);  //三角形为(5,5) (-3,1) (9,-2)三点组成
		cout << "三角形面积应该是：36， 实际是：" << tr.area() << endl;
		}

	if (1) {
		triangle tr(0, 0, 1, 1, 2, 2);  //三点共线
		cout << "三角形面积应该是：-1， 实际是：" << tr.area() << endl;
		}

	return 0;
}

