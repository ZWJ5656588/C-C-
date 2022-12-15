#include "game.h"
#include<stdio.h>
void InitBoard(char board[Row][Colum],int row,int(colum))
{
    int i=0;
    int j=0;
    for ( i = 0; i < row; i++)
    {
        for(j=0;j<colum;j++)
        {
            board[i][j]=' ';

        }
    }
    
}
void DisplayBoard(char board[Row][Colum],int row,int colum)
{
    int i=0;
    for(i=0;i<row;i++)
    {
        //打印一行数据
        printf(" %c | %c | %c |\n");
        //打印分割行
    }
}