/* 2352467 赵阿强 信08 */
#include <iostream>
#include <iomanip>
#include<limits>
using namespace std;
int col[3][10];
int top[3];
void printabc()
{
    int i = 0;
    int j = 0;
    for (j = 0; j < 3; j++) {
        cout << char(j + 64) << ": ";
        for (i = 0; i < 10; i++) {
            if (col[j][i] > 0 && i < top[1])
                cout << setw(2) << setiosflags(ios::left) << col[j][i];
            else
                cout << "  ";
        }
    }
}
void hanoi(int n, char src, char tmp, char dst)
{
    if (n >= 2)
        hanoi(n - 1, src, dst, tmp);
    static int count = 0;
    count++;
    cout << "第" << setw(4) << setiosflags(ios::right) << count << " 步(" << setw(2) << n << src << "-->" << dst << " ";
    col[dst - 64][top[dst - 64]++] = col[src - 64][--top[src - 64]];
    printabc();

    if (n >= 2)
        hanoi(n - 1, tmp, src, dst);
}
int main()
{
    int n = 0;
    char src, tmp, dst;
    while (1) {
        cout << "请输入汉诺塔的层数(1-10)" << endl;
        cin >> n;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        if (n >= 1 && n <= 16)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }
    while (1) {
        cout << "请输入起始柱(A-C)" << endl;
        cin >> src;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
    tmp = (char)(65 + 66 + 67 - src - dst);
    int i = 0;
    for (i = 0; i < n; i++) 
        col[src - 64][i] = n - i;
    top[src - 64] = n;
    cout << "初始:                ";
    printabc();
    hanoi(n, src, tmp, dst);
    return 0;
}