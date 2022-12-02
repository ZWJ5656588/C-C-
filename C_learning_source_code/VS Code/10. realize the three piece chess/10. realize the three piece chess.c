#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define Row 3
#define Column 3

void InitBoard(char board[Row][Column],int row,int(column))   //������ʽ char board[Row][Column]
{
    int i=0;
    int j=0;
    for ( i = 0; i < row; i++)
    {
        for(j=0;j<column;j++)
        {
            board[i][j]=' '; //��ʼ�����棬����Ԫ�����ÿո�����ӡ

        }
    }
    
}

void DisplayBoard(char board[Row][Column],int row,int column)
{
    int i=0;
    int j=0;
    for(i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
        {
            printf(" %c ",board[i][j]);
            if (j<column-1)
            {
                printf("|");
            }
        }
        printf("\n");
        if(i<row-1)
        {
            for(j=0;j<column;j++)
            {
                printf("--- ");
            }
            printf("\n");
        }
    }
}

void PlayerMove(char board[Row][Column],int row,int column)
{
    int x=0;
    int y=0;
    printf("�����:>\n");
    while (1)
    {
        printf("������Ҫ�µ�����:>");
        scanf("%d%d",&x,&y);
        if (x>=1 && x<=row && y>=1 && y<=column)
        {
            if (board[x-1][y-1]==' ')
            {
                board[x-1][y-1]='*';
                break;
            }
            else
            {
                printf("�����걻ռ��\n");
            }
        }
        else
        {
            printf("����Ƿ�����������\n");
        }
    }
    
}

void ComputerMove(char board[Row][Column],int row,int column)
{
    int x=0;
    int y=0;
    printf("������:>\n");
    //������ܻᱻռ�ã���һ���Ϸ�
    while(1)
    {     
        x=rand() % Row;      //����0-2�������
        y=rand() % Column;
        //������ܻᱻռ�ã���һ���Ϸ�
        if(board[x][y] == ' ')
        {
            board[x][y] ='#';
            break;
        }
    }
    
}
int Isfull(char board[Row][Column],int row,int column)
{
    int i=0;
    int j=0;
    int flag=1;
    for (i=0;i<Row;i++)
    {
        for(j=0;j<Column;j++)
        {
            if (board[i][j] ==' ')
            flag=0;
        }
    }
    return flag;
}

char Iswin(char board[Row][Column],int row,int column)
{
    int flag =Isfull(board,Row,column);
    char ch=0;
    int i=0;
    int j=0;
    for(i=0;i<Row;i++)
    {
        for (j=0;j<Column;j++)
        {
            if (board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][1]!=' ')
            {
                ch=board[i][0];
                return ch;
            } 
            else if (board[0][j]==board[1][j] && board[1][j]==board[2][j] && board[1][j]!=' ')
            {
                ch=board[0][j];
                return ch;
            }
            else if ((board[0][0]==board[1][1] && board[1][1]==board[2][2] || board[0][2]==board[1][1] && board[1][1]==board[2][0])
            && board[1][1]!=' ')
            {
                ch=board[1][1];
                return ch;
            }
        }
    }
    if (flag)
    {
        return 't';
    }
    ch='c';
    return ch;
}

void menu()  //�˵�
{
    printf("***********************************\n");
    printf("*********1*. play   0.exit*********\n");
    printf("***********************************\n");
}

void game() //��ʼ��Ϸ��������غ���
{
    char ret=0; //��Ӯ�ж�
    //������Ϣ
    char board [Row][Column]={0};   //�����������ݶ��ǿո�
    InitBoard(board,Row,Column) ;   //��ʼ������
    DisplayBoard(board,Row,Column); /*��ӡ����            
                                                         ---|---|---
                                                         ---|---|---
                                                         ---|---|---  */
    //������������                                        
    while(1)
    {
    //�������
        PlayerMove(board,Row,Column);
        DisplayBoard(board,Row,Column); 
    //�ж�����Ƿ�Ӯ
        ret=Iswin(board,Row,Column);
        if (ret=='*')
        {
            printf("��һ�ʤ\n");
            break;
        }
        else if (ret=='t')
        {
            printf("ƽ��\n ");
            break;
        }
        
    //��������
        ComputerMove(board,Row,Column);
        DisplayBoard(board,Row,Column); 
    //�жϵ����Ƿ�Ӯ
        ret=Iswin(board,Row,Column);
        if (ret=='#')
        {
            printf("���Ի�ʤ\n");
            break;
        }
        else if (ret=='c')
        {
           printf("������Ϸ\n");
        }
        

    //Iswin����Ҫ��֪Ӯ��Ϸ�ļ���״̬
    /*<1>���Ӯ��'*'
      <2>����Ӯ��'#'
      <3>ƽ��  ��'t'
      <4>����  ��'c''
    */
    }
}

void test()  //4. ʵ��������Ĺ��ܺ���
{
    //test()ֻ����һ�Σ���test������ʹ��ʱ���
    //srand��������ʱ�������
    srand((unsigned int)time(NULL));
    int input =0;
    do
    {
        menu();
        printf("��ѡ��:>");
        scanf("%d",&input);
        switch (input)
        {
        case 1:
            game();
            break;
        case 0:
            printf("�˳���Ϸ\n");
        default:
            printf("ѡ�����������ѡ��\n");
            break;
        }
    } while (input);
    
}


void main()
{

    
    //1.ʵ�������������������
    {
        test();
    }
}