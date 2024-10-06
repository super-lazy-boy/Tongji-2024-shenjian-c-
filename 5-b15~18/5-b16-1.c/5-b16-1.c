/*2352467 赵阿强 信08*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <conio.h>
void paixu(char num[][8], char name[][10],int score[10])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int cha = 0;
    int max = 0;
    int i = 0;
    for (int a = 0; a < 9; a++) {
        for (i = 0; i < 9-a; i++) {
            for (int j = 0; j < 8; j++) {
                cha = num[i][j] - num[i + 1][j];
                if (cha != 0)
                    break;
            }
            char change1[8] = { 0 };
            char change2[10] = { 0 };
            int t = 0;
            if (cha < 0) {
                int k = 0;
                for (k = 0; k < 8; k++)
                    change1[k] = num[i][k];
                for (k = 0; k < 8; k++)
                    num[i][k] = num[i + 1][k];
                for (k = 0; k < 8; k++)
                    num[i + 1][k] = change1[k];

                for (k = 0; k < 10; k++)
                    change2[k] = name[i][k];
                for (k = 0; k < 10; k++)
                    name[i][k] = name[i + 1][k];
                for (k = 0; k < 10; k++)
                    name[i + 1][k] = change2[k];

                t = score[i];
                score[i] = score[i + 1];
                score[i + 1] = t;
            }
        }
    }
}

void output(char num[10][8],char name [10][10],int score[10])
{
    for (int i = 0; i < 10-1; i++) {
        paixu(num, name,score);
    }
    for (int i = 0; i < 10 ; i++) {
        if (score[i] >= 60) {
            printf("%s %s %d\n", name[i], num[i], score[i]);
        }
    }
}
void input(char num[10][8], char name[10][10], int score[10])
{
	int i = 0, j = 0;
	for (i = 0; i < 10; i++) {
		printf("请输入第%d个人的学号、姓名、成绩\n", i+1);
		scanf("%s %s %d", &num[i], &name[i], &score[i]);
	}
}
int main()
{
	char num[10][8] = { 0 };
	char name[10][10] = { 0 };
	int score[10] = { 0 };
    input(num, name, score);
    printf("\n");
    printf("及格名单(学号降序):\n");
    output(num, name, score);
	return 0;
}
