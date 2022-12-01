#include <stdio.h>
#include <string.h>

struct S
{
    int a;
    char c;
    char arr[20];
    double d;
};

struct T
{
    char ch[10];
    struct S s;
    char*pc;
};

struct Person // 2.
{
    char name[20];
    int count;
}leader[3]={"Li",0,"Zhang",0, "Sun",0};

struct Student  // 3.
{
    int num;
    char name [20];
    float score;
};

void Swap_stu(struct Student* stu,int i,int j)
{
    struct Student temp;
    temp=stu[i];
    *(stu+i)=*(stu+j);
    stu[j]=temp;
        
};




int main()
{
    {
        //1. 结构体初始化
    char arr[]="hello world";
    struct T t=
    {
        "hehe",{100,'w',"hello,world",3.14},arr
    };  //结构体初始化
    printf("%s\n",t.ch);//hehe
    printf("%s\n",t.s.arr);
    }

    printf("\n=======================================\n");

    {
        // //2.结构体数组
        // int i,j;
        // char leader_name[20];
        // for (i=0;i<=10;i++)
        // {
        //     scanf("%s",leader_name);
        //     for (j=0;j<3;j++)
        //     {
        //         if(strcmp(leader_name,leader[j].name)==0 )
        //         {
        //             leader[j].count++;
        //         }
        //     }
        // }
        // printf("\nResult:\n");
        // for (i = 0; i < 3; i++)
        // {
        //     printf("%5s:%d\n",leader[i].name,leader[i].count);
        // }
        
    }

    {
        //3. 结构体数组中的值可以整体交换
        struct Student stu[5]=
        {
            {10101,"Zhang",78},
            {10103,"Wang",98.5},
            {10106,"Li",86},
            {10108,"Ling",73.5},
            {10110,"Sun",100},     
        }; // 定义结构体数组并初始化
        const int n=5;
        int i,j,k;
        printf("The order is :\n");
        for (i=0;i<n-1;i++)
        {
            for (j=i+1;j<n;j++)
            {
                if(stu[i].score<stu[j].score)
                {
                    Swap_stu(&stu[0],i,j);
                }
            }
        } 
        for (i=0;i<n;i++) 
        {
            printf("%6d %8s %6.2f\n",stu[i].num,(*(stu+i)).name,(stu+i)->score);
        } 
        
         printf("\n=======================================\n");     
    }

}
