#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 9
#define COL 9
#define ROWS ROW+2   //��ֹɨ����Ե��������±����
#define COLS COL+2
#define EASY_COUNT 10 //�����׵ĸ���

void InitBoard(char board[ROWS][COLS],int rows,int cols,char set);
void DisplayBoard(char board[ROWS][COLS],int row,int col);  //���ﴫ��ʱ�β������СӦ��ʵ��mine�����Сһ�� ROWS��CLOS
void SetMine(char board[ROWS][COLS],int row,int clo);
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col);
int  surround_boom_count(char mine[ROWS][COLS],int x,int y);