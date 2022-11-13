#include "11. functions announcement.h"


void InitBoard(char board[ROWS][COLS],int rows,int cols,char set)   //��ʼ�����溯����ʵ��
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
    //��ӡ�к�
    for (i=0;i<=col;i++)
    {
        printf("%d ",i);
    }
    printf("\n");
    for (i=1;i<=row;i++)
    {
        //��ӡ�к�
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
        int x=rand()%row+1; //����1-row�������
        int y=rand()%clo+1; //����1-col�������
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
        printf("������Ҫ�Ų������>");
        scanf("%d%d",&x,&y);
        if (x>=1 && x<=row && y>=1 && y<= col)
        {
            if (mine[x][y]=='1')
            {
                printf("���ź�,���ǿ���,��Ϸ����\n");
                break;

            }
            else 
            {
                //��ѯ��λ���ܱ��м����ף���ͨ��showֱ�۴�ӡ
                int count=surround_boom_count(mine,x,y);
                show[x][y]=(char) count+48;
                break;
            }

        }
        else
            printf("���������������������\n");
    }
}