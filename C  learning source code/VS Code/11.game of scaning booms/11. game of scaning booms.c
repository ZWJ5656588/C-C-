#include "11. functions announcement.h"
#include "11.functions acheivement.c"    //ͬʱҪ�����ⲿ������.h,.c�ļ�

void menu()
{
    printf("*****************************\n");
    printf("*******  1. play  ***********\n");
    printf("*******  0. exit  ***********\n");
    printf("*****************************\n");
}

void game()
{
    //�׵���Ϣ�洢
    //1.���ú��׵���Ϣ
    char mine[ROWS][COLS]={0};  //11*11������Ϣ��'0'���ף�'1'����
    //2.�Ų��׵���Ϣ
    char show[ROWS][COLS]={0};  //��ʾ���û��Ľ��棬��'*'��ʼ��
    //3.��ʼ��
    InitBoard(mine,ROWS,COLS,'0');  //��Ϊ��ӳ����������ʾ���û�����������ʼ����ͬ������Ҫ����ʼ�������ݴ��룡��
    InitBoard(show,ROWS,COLS,'*'); 
    //4.��ӡ����
    DisplayBoard(mine,ROW,COL); //���ٴ�ӡ��Ȧ������Ķ�������
    printf("\n");
    DisplayBoard(show,ROW,COL);
    printf("ϵͳ����ը�����\n");
    //������,������꽫'1'����mine����
    SetMine(mine,ROW,COL);
    DisplayBoard(mine,ROW,COL);  
    //�Ų���
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
        printf("��ѡ��>");
        scanf("%d",&input);
        switch (input)
        {
        case 1:
            game();
            break;       
        case 0:
            printf("�˳���Ϸ\n");
            break;
        default:
            printf("ѡ���������������>");
            break;
        }
    } while (input);
    
}


void main()
{
    test();
}