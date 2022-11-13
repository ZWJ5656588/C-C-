#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 9
#define COL 9
#define ROWS ROW+2   //防止扫到边缘造成数组下标溢出
#define COLS COL+2
#define EASY_COUNT 10 //定义雷的个数

void InitBoard(char board[ROWS][COLS],int rows,int cols,char set);
void DisplayBoard(char board[ROWS][COLS],int row,int col);  //这里传参时形参数组大小应与实参mine数组大小一致 ROWS，CLOS
void SetMine(char board[ROWS][COLS],int row,int clo);
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col);
int  surround_boom_count(char mine[ROWS][COLS],int x,int y);