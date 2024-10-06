/* 2352467 赵阿强 信08 */
#include <iostream>
#include <iomanip>
using namespace std;

/* ----具体要求----
   1、不允许添加其它头文件
   2、不允许定义全局变量、仅允许hanoi中定义一个静态局部变量
   3、不允许添加其它函数
   4、main函数处理输入，允许循环
   --------------------------------------------------------------------- */

   /***************************************************************************
     函数名称：
     功    能：打印n层汉诺塔的移动顺序
     输入参数：int n：层数
               char src：起始柱
               char tmp：中间柱
               char dst：目标柱
     返 回 值：
     说    明：1、函数名、形参、返回类型均不准动
               2、本函数不允许出现任何形式的循环
               3、允许定义一个静态局部变量
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    if (n >= 2)
        hanoi(n - 1, src, dst, tmp);
    static int count = 0;
    count++;
    cout << setw(5) << setiosflags(ios::right) << count << ":";
    cout << setw(3) << n << "# " << src << "-->" << dst << endl;
    if (n >= 2)
        hanoi(n - 1, tmp, src, dst);
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：1、完成输入、调用递归函数
            2、处理输入错误时，允许使用循环
            3、为了统一检查，不再允许添加其它函数（输入起始/目标柱的代码不要求统一函数处理，均直接放在main中）
***************************************************************************/
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
            cin.ignore(1410065408, '\n');
            continue;
        }
        if (n >= 1 && n <= 16)
        {
            cin.clear();
            cin.ignore(1410065408, '\n');
            break;
        }
    }
    while (1) {
        cout << "请输入起始柱(A-C)" << endl;
        cin >> src;
        cin.clear();
        cin.ignore(1410065408, '\n');
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
        cin.ignore(1410065408, '\n');
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
    tmp = char(65 + 66 + 67 - src - dst);
    cout << "移动步骤为:" << endl;
    hanoi(n, src, tmp, dst);
    return 0;
}
