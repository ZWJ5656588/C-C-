#include "11. functions announcement.h"


void InitBoard(char board[ROWS][COLS],int rows,int cols,char set)   //初始化界面函数的实现
{
    int i=0;
    int j=0;
    for ( i = 0; i < rows; i++)
    {
        for (j= 0; j <cols; j++)
        {
            board[i][j]=set;
        }
    }
    
}

void DisplayBoard(char board[ROWS][COLS],int row,int col)
{
    int i=0;
    int j=0;
    //打印列号
    for (i=0;i<=col;i++)
    {
        printf("%d ",i);
    }
    printf("\n");
    for (i=1;i<=row;i++)
    {
        //打印行号
        printf("%d ",i);
        for (j=1;j<=col;j++)
        {
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }

}

void SetMine(char board[ROWS][COLS],int row,int clo)
{
    int count =EASY_COUNT;
    while(count)
    {
        int x=rand()%row+1; //产生1-row的随机数
        int y=rand()%clo+1; //产生1-col的随机数
        if (board[x][y]=='0')
        {
            board[x][y]='1';
            count--;
        }
    }
}

int surround_boom_count(char mine[ROWS][COLS],int x,int y)
{
    return (
            mine[x-1][y-1]+mine[x-1][y]+
            mine[x-1][y+1]+mine[x][y-1]+
            mine[x][y+1]+mine[x+1][y-1]+
            mine[x+1][y]+mine[x+1][y+1]-8*'0'

    );
}

void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col)
{
    int x=0;
    int y=0;
    while(1)
    {
        printf("请输入要排查的坐标>");
        scanf("%d%d",&x,&y);
        if (x>=1 && x<=row && y>=1 && y<= col)
        {
            if (mine[x][y]=='1')
            {
                printf("很遗憾,这是颗雷,游戏结束\n");
                break;

            }
            else 
            {
                //查询该位置周边有几颗雷，并通过show直观打印
                int count=surround_boom_count(mine,x,y);
                show[x][y]=(char) count+48;
                break;
            }

        }
        else
            printf("坐标输入错误，请重新输入\n");
    }
}