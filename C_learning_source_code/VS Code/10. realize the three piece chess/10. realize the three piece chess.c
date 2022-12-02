#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define Row 3
#define Column 3

void InitBoard(char board[Row][Column],int row,int(column))   //数组形式 char board[Row][Column]
{
    int i=0;
    int j=0;
    for ( i = 0; i < row; i++)
    {
        for(j=0;j<column;j++)
        {
            board[i][j]=' '; //初始化界面，数组元素先用空格代替打印

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
    printf("玩家走:>\n");
    while (1)
    {
        printf("请输入要下的坐标:>");
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
                printf("该坐标被占用\n");
            }
        }
        else
        {
            printf("坐标非法，重新输入\n");
        }
    }
    
}

void ComputerMove(char board[Row][Column],int row,int column)
{
    int x=0;
    int y=0;
    printf("电脑走:>\n");
    //坐标可能会被占用，但一定合法
    while(1)
    {     
        x=rand() % Row;      //产生0-2的随机数
        y=rand() % Column;
        //坐标可能会被占用，但一定合法
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

void menu()  //菜单
{
    printf("***********************************\n");
    printf("*********1*. play   0.exit*********\n");
    printf("***********************************\n");
}

void game() //开始游戏，调用相关函数
{
    char ret=0; //输赢判断
    //棋盘信息
    char board [Row][Column]={0};   //数组里面内容都是空格
    InitBoard(board,Row,Column) ;   //初始化棋盘
    DisplayBoard(board,Row,Column); /*打印棋盘            
                                                         ---|---|---
                                                         ---|---|---
                                                         ---|---|---  */
    //玩家与电脑下棋                                        
    while(1)
    {
    //玩家下棋
        PlayerMove(board,Row,Column);
        DisplayBoard(board,Row,Column); 
    //判断玩家是否赢
        ret=Iswin(board,Row,Column);
        if (ret=='*')
        {
            printf("玩家获胜\n");
            break;
        }
        else if (ret=='t')
        {
            printf("平局\n ");
            break;
        }
        
    //电脑下棋
        ComputerMove(board,Row,Column);
        DisplayBoard(board,Row,Column); 
    //判断电脑是否赢
        ret=Iswin(board,Row,Column);
        if (ret=='#')
        {
            printf("电脑获胜\n");
            break;
        }
        else if (ret=='c')
        {
           printf("继续游戏\n");
        }
        

    //Iswin函数要告知赢游戏的几种状态
    /*<1>玩家赢：'*'
      <2>电脑赢：'#'
      <3>平局  ：'t'
      <4>继续  ：'c''
    */
    }
}

void test()  //4. 实现三子棋的功能函数
{
    //test()只运行一次，在test函数内使用时间戳
    //srand函数申请时间戳！！
    srand((unsigned int)time(NULL));
    int input =0;
    do
    {
        menu();
        printf("请选择:>");
        scanf("%d",&input);
        switch (input)
        {
        case 1:
            game();
            break;
        case 0:
            printf("退出游戏\n");
        default:
            printf("选择错误，请重新选择\n");
            break;
        }
    } while (input);
    
}


void main()
{

    
    //1.实现三子棋主函数，入口
    {
        test();
    }
}