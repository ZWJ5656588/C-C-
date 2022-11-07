#include <stdio.h>
#include <string.h>
#define count 10

void bubble_sort(int arr[],int sz)  //3.2 冒泡排序
{
    //确定冒泡排序的趟数
    int i=0;
    for (i;i<sz-1;i++)              
    {
        int flag=1;//假设这一趟要排序的数据已经有序
        //每一趟冒泡排序
        int j=0;
        for(j=0;j<sz-i;j++)         //一趟的次数
        {
            if(arr[j] > arr[j+1])   //交换值
            {
                int tmp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tmp;
                flag=0;             //不完全有序
            }

        }
        if (flag==1)
             break;
    }
        
}

void main()
{
    //1. 统计各个数字，空白符
    {
    int c,i,nwhite,nother;
    int ndigit[10];

    nwhite=nother=0;
    for (i=0;i<10;i++)
        ndigit[i]=0;

    while ((c=getchar())!=EOF)
    {
        if(c>='0' && c <='9')
            ++ndigit[c-'0'];
        else if(c==' '||c=='\n'||c=='\t')
            ++nwhite;
        else
            ++nother;
    }
    
    printf("digits=");
    for ( i = 0; i < count; i++)
        printf(" %d",ndigit[i]);
    printf(",white space = %d,other = %d\n",nwhite,nother);

    printf("\n--------------------------------\n");
  
    }
    //2. sizeof 与 strlen
    {
           char arr4[]="abcdrf";
           printf("%d\n",sizeof(arr4));  //结果是7，包括\0，求arr4所占空间的字节数
           printf("%d\n",strlen(arr4));  //结果是6，不包括\0,求\0之前的字符串长度
           //strlen与sizeof本身没什么联系
           //strlen只能做用于字符串，是库函数，使用要引头文件
           //sizefo计算变量、数组类型的大小，单位是字节，是操作符，不用头文件
           char arr1[]="abc";
           char arr2[]={'a','b','c'};
           printf("%d\n",sizeof(arr1));
           printf("%d\n",sizeof(arr2));
           printf("%d\n",strlen(arr1));
           printf("%d\n",strlen(arr2));  //输出一个随机值，因为要找\0来结束长度读取

    }    
       printf("\n--------------------------------\n");

       //3.二维数组
    // {
    //     int arr_0[3][4]={1,2,3,4,5,6};      //三行四列，不完全初始化
    //     int arr_1[3][4]={{1,2,3},4,5,6}; 
    //     int arr_2[][3]={{1,2,3},{4,5,6}};   //二维数组的列不能省略，行可以省略
    // }
    
    // 3.1 打印二维数组的所有元素
     {
        int arr_1[][3]={{1,2,3},{4,5,6},{7,8,9}};
        for (int i=0;i<3;i++)
        {
            for (int j=0;j<3;j++)
            {
                printf("arr_1[%d][%d]=%d    ",i,j,arr_1[i][j]);
            }
            printf("\n");
        }
     }
     
    printf("\n--------------------------------\n");


    //3. 2  实现一个冒泡排序，数组作为函数参数,打印出升序后的序列
    {
        int arr[]={6,5,8,2,1,9,19,4,11,10,17,15,13};
        int i=0;
        int sz=sizeof(arr)/sizeof(arr[0]);
        //对arr排序，升序
        //对数组arr进行传参，真正传递过去的是第一个数组元素的地址！！！
        //在外部先算好数组大小sz
        bubble_sort(arr,sz); //冒泡排序
        for (i=0;i<sz;i++)
        {
            printf("%d ",arr[i]);
        }
    }
    printf("\n--------------------------------\n");


}

