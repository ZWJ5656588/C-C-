#include "11. functions announcement.h"
#include "11.functions acheivement.c"    //同时要引用外部函数的.h,.c文件

void menu()
{
    printf("*****************************\n");
    printf("*******  1. play  ***********\n");
    printf("*******  0. exit  ***********\n");
    printf("*****************************\n");
}

void game()
{
    //雷的信息存储
    //1.布置好雷的信息
    char mine[ROWS][COLS]={0};  //11*11，雷信息，'0'无雷，'1'有雷
    //2.排查雷的信息
    char show[ROWS][COLS]={0};  //显示给用户的界面，用'*'初始化
    //3.初始化
    InitBoard(mine,ROWS,COLS,'0');  //因为反映雷数组与显示给用户界面的数组初始化不同，所以要将初始化的内容传入！！
    InitBoard(show,ROWS,COLS,'*'); 
    //4.打印棋盘
    DisplayBoard(mine,ROW,COL); //不再打印外圈防溢出的多余数组
    printf("\n");
    DisplayBoard(show,ROW,COL);
    printf("系统布置炸弹完成\n");
    //布置雷,随机坐标将'1'放入mine数组
    SetMine(mine,ROW,COL);
    DisplayBoard(mine,ROW,COL);  
    //排查雷
    FindMine(mine,show,ROW,COL);
    DisplayBoard(show,ROW,COL);


}

void test()
{
    srand((unsigned int)time(NULL));
    int input=0;
    do
    {
        menu();
        printf("请选择>");
        scanf("%d",&input);
        switch (input)
        {
        case 1:
            game();
            break;       
        case 0:
            printf("退出游戏\n");
            break;
        default:
            printf("选择错误，请重新输入>");
            break;
        }
    } while (input);
    
}


void main()
{
    test();
}