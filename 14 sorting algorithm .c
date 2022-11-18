#include <stdio.h>
#define Len 18
#define Max 77
int arr1[Len]={39,23,65,4,26,8,9,47,35,21,46,19,13,4,26,23,23,77};


//定义一个交换数组两元素的函数
void Swap(int arr[],int i,int j)
{
    int temp=0;
    temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}


//排序算法主函数
void main()
{
    //1. Conuting Sort 计数排序
    // 创建原数组中最大的数为索引最大值的数组
    int sorting[Max+1]={0};
    int index=0;
    for (int i=0;i<18;i++)
    {
        index=arr1[i];
        sorting[index]++;
    }
    //得到新的数组sorting，打印出来即可
    for (int j=0;j<Max+1;j++)
    {
        for (int i=0;i<sorting[j];i++)
        {
            printf("%d ",j);
        }
    }
    printf("\n\n1.----------------------------------------------\n\n");
    
    {
        //2. Selection Sort  选择排序
        for(int i=0;i<Len;i++)
        {
            // j<Len-1,避免数组溢出，最后一位也无需比较
            for (int j = i+1; j < Len-1; j++)
            {
                if (arr1[i]>arr1[j])
                {
                    Swap(arr1,i,j);
                }
            }
            
        }
        for ( int i = 0; i < Len; i++)
        {
               printf("%d ",arr1[i]);
        }
        
        
    }
            
    printf("\n\n3.----------------------------------------------\n\n");

    {
        //3.Bubble Sort 冒泡排序
        // i计要冒泡的趟数，i从1开始
        for (int i = 1; i < Len; i++)
        {
            //优化算法，如果已经有序，则计数器为0，退出，若无序，进入某一趟冒泡前仍赋值为0
            int count=0;
            // j计每一趟要比较的次数
            for (int  j = 0; j< Len-i; j++)
            {
                if(arr1[j]>arr1[j+1])
                {
                    Swap(arr1,j,j+1);
                    count++;
                }
            }
            if (count!=0)
            {
                break;
            }
                   
            
            
        }
        for ( int i = 0; i < Len; i++)
        {
               printf("%d ",arr1[i]);
        }
        
        
    printf("\n\n3.----------------------------------------------\n\n")  ;

    } 

    {
        //4. Insert Sort 插入排序
        //从第一个元素开始依次取出用于比较的元素,注意i的初始下标是1
        for(int i=1;i<Len;i++)
        {
            //取出用于比较的元素
            int temp=arr1[i];
            int j=i;
            while (j>0)
            {
                if (temp<arr1[j-1])
                {
                    arr1[j]=arr1[j-1];
                }
                else 
                {
                    break;
                }
                j--;
            }
        
            //将元素插入空出来的位置，j=i是空出来的位置
            arr1[j]=temp;
        }
        for ( int i = 0; i < Len; i++)
        {
               printf("%d ",arr1[i]);
        }
        
    
    printf("\n\n4.----------------------------------------------\n\n") ; 
        
    }
    {
        //4. Hill Sort 希尔排序
        
    }
        

    }
        

