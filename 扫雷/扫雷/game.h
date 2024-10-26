#pragma once

#include <stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define easycount 10
 
void InitBoard(char arr[ROWS][COLS], int rows, int cols, char set);

void printboard(char arr[ROWS][COLS], int row, int col);

void setmine(char arr[ROWS][COLS], int row, int col);

void findmine(char arr[ROWS][COLS], char arr2[ROWS][COLS], int row, int col);
