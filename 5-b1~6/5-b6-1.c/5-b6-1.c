/* 2352467 赵阿强 信08 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int top_a = 0;
int top_b = 0;
int top_c = 0;
int a[10], b[10], c[10];
int count = 0;
void printabc()
{
    printf("A: ");
    int i = 0;
    for (i = 0; i < 10; i++) {
        if (a[i] > 0 && i < top_a)
            printf("%-2d", a[i]);
        else
            printf("  ");
    }
    printf("B: ");
    for (i = 0; i < 10; i++) {
        if (b[i] > 0 && i < top_b)
            printf("%-2d", b[i]);
        else
            printf("  ");
    }
    printf("C: ");
    for (i = 0; i < 10; i++) {
        if (c[i] > 0 && i < top_c)
            printf("%-2d", c[i]);
        else
            printf("  ");
    }
    printf("\n");
}
void hanoi(int n, char src, char tmp, char dst)
{
    if (n >= 2)
        hanoi(n - 1, src, dst, tmp);

    count++;
    printf("第%4d 步(%2d): %c-->%c ", count, n, src, dst);
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
    printabc();

    if (n >= 2)
        hanoi(n - 1, tmp, src, dst);
}
int main()
{
    int n = 0;
    int ret = 0;
    char src, tmp, dst;
    while (1) {
        printf("请输入汉诺塔的层数(1-10)\n");
        ret = scanf("%d", &n);
        if (ret != 1)
        {
            scanf("%*[^\n]");
            getchar();
            continue;
        }
        if (n >= 1 && n <= 16)
        {
            scanf("%*[^\n]");
            getchar();
            break;
        }
    }
    while (1) {
        printf("请输入起始柱(A-C)\n");
        ret = scanf("%c", &src);
        scanf("%*[^\n]");
        getchar();
        if (ret != 1 || src < 'A' || (src > 'C' && src < 'a') || src > 'c')
        {
            continue;
        }
        if ((src >= 'A' && src <= 'C') || (src >= 'a' && src <= 'c'))
        {
            if (src >= 'a')
                src = (char)(src - 32);
            break;
        }
    }
    while (1) {
        printf("请输入目标柱(A-C)\n");
        ret = scanf("%c", &dst);
        scanf("%*[^\n]");
        getchar();
        if (ret != 1 || dst < 'A' || (dst > 'C' && dst < 'a') || dst > 'c')
        {
            continue;
        }
        if ((dst >= 'A' && dst <= 'C') || (dst >= 'a' && dst <= 'c'))
        {
            if (dst >= 'a')
                dst = (char)(dst - 32);
            if (dst == src) {
                if (dst == 'A')
                    printf("目标柱(A)不能与起始柱(A)相同\n");
                if (dst == 'B')
                    printf("目标柱(B)不能与起始柱(B)相同\n");
                if (dst == 'C')
                    printf("目标柱(C)不能与起始柱(C)相同\n");
                continue;
            }
            break;
        }
    }
    tmp = (char)(65 + 66 + 67 - src - dst);
    int i = 0;
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
    printf("初始:                ");
    printabc();
    hanoi(n, src, tmp, dst);

    return 0;
}