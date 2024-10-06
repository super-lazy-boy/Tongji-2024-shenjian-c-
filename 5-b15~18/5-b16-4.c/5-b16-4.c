/*2352467 赵阿强 信08*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <conio.h>
void paixu(char num[][8], char name[][10], int score[10])
{
	for (int a = 0; a < 9; a++) {
		for (int i = 0; i < 9 - a; i++) {
            char change1[8] = { 0 };
            char change2[10] = { 0 };
            int t = 0;
            if (score[i] < score[i + 1]) {
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
void output(char num[10][8], char name[10][10], int score[10])
{
    for (int i = 0; i < 10 - 1; i++) {
        paixu(num, name, score);
    }
    for (int i = 0; i < 10; i++) {
            printf("%s %s %d\n", name[i], num[i], score[i]);
    }
}
void input(char num[10][8], char name[10][10], int score[10])
{
    for (int i = 0; i < 10; i++) {
        printf("请输入第%d个人的学号、姓名、成绩\n", i + 1);
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
    printf("全部学生(成绩降序):\n");
    output(num, name, score);
}