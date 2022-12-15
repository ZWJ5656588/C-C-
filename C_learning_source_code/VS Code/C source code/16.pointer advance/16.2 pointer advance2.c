# include <stdio.h>
# include <string.h>
# include <stdlib.h>

// 1. strstr库函数的应用
char str[] =    "rown";
char string[] = "The quick brown dog jumps over the lazy fox";
char fmt1[] =   "         1         2         3         4         5";
char fmt2[] =   "12345678901234567890123456789012345678901234567890";

//3.1手写的冒泡排序
void bubble_sort(int*arr,int sz)
{
    int i=0;
    int j=0;
    int count=0;
    for( i=0;i<sz;i++)
    {
        for ( j=0;j<sz-i-1;j++)  //j从0开始
        {
            if (arr[j] > arr[j+1])
            {
                int temp=0;
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                count++;
            }
        }
        if (count==0)
            break;
    }
}

// 3.2结构体排序
struct Stu
{
    char name [20];
    int age;
};

// 3.3.1qsort函数中的比较方法函数,比较整型数组
int cmp_int(const void *a, const void *b)
{
    //比较两个整型值
    return *((int*)a)-*((int*)b);
}

// 3.3.2 qsort比较结构体中age
int cmp_stu_struct_by_age(const void *a, const void *b)
{
    // 参数转化为结构体指针类型
    return ((struct Stu*)a)->age - ((struct Stu*)b)->age;

}


// 3.3.3 qsort 比较结构体中的
int cmp_stu_struct_by_name(const void *a, const void *b)
{
    return strcmp(((struct Stu*)a)->name,((struct Stu*)b)->name);
}

//------------------------------------------------------------------------------
 

void main( void )
{
    //1.strstr库函数的应用
    {
        char *pdest;
        int  result;
        printf( "String to be searched:\n\t%s\n", string );
        printf( "\t%s\n\t%s\n\n", fmt1, fmt2 );
        pdest = strstr( string, str ); // strstr的作用是在str1内查找是否有子串与str2一致，有的话返回第一次查找到的字符首地址
        result = pdest - string + 1;  //获取str首元素在string数组中的位置，从1开始
        if ( pdest != NULL )
        {
            printf( "%s found at position %d\n\n", str, result );
            printf("%s\n",pdest);
        }
        else 
           printf( "%s not found\n", str );
    }

    {
        //2.函数指针进阶应用
        int arr[10];
        int(*p)[10]=&arr; //取出数组的地址

        int (*pfarr[4])(int,int); // 函数指针的数组
        int (*(*ppfarr)[4])(int,int)=&pfarr; // ppfarr是一个数组指针 指向函数指针数组的指针     
    }

    {
        //3.回调函数的使用场景
        // C语言标准库qsort用来排序
        int arr[10]={9,8,6,7,5,4,2,3,1,0};
        int sz=sizeof(arr)/sizeof(arr[0]);
        // 3.1 手写的冒泡排序
        bubble_sort(arr,sz);
        int i=0;
        for ( i = 0; i < sz; i++)
        {
            printf("%d ",arr[i]);
        }
        
        //3.2 排序一个结构体中的元素
        // 创建一个结构体数组,此时自定义的冒泡排序数组不可用
        struct Stu s[3]={{"zhagsan",20},{"lisi",30},{"wnagwu",10}};
        
        //3.3 qsort快速排序函数
        void qsort( void *base, size_t num, size_t width, int (__cdecl *compare )(const void *elem1, const void *elem2 ) );

        //3.3.1 排序一个整形数组
        // 第一个参数是数组起始地址，第二个是数组长度，第三个是数组元素字节数，第四个参数是函数指针,实现排序的比较方法
        int arr1[10]={45,75,52,47,36,40,44,75,61,45};
        qsort(arr1,sz,sizeof(arr[0]),cmp_int); //无返回值
        printf("\n使用qsort函数排序结果如下\n");
        for ( i = 0; i < sz; i++)
        {
            printf("%d ",arr[i]);
        }

        puts("\n--------------------------------");

        // 3.3.2 按照年龄排序结构体
        qsort(s,3,sizeof(s[0]),cmp_stu_struct_by_age);
        for ( i = 0; i < 3; i++)
        {
            printf("%s,%d ",s[i].name,s[i].age);
        }

        puts("\n--------------------------------");

        //3.3.4 按照姓名排序结构体
        qsort(s,3,sizeof(s[0]),cmp_stu_struct_by_name);
        for ( i = 0; i < 3; i++)
        {
            printf("%s,%d ",s[i].name,s[i].age);
        }



    }


}




