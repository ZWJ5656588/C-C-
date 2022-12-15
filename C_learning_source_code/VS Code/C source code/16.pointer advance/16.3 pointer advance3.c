# include <stdio.h>

// 1.2 Struct


// 1.交换函数
void Swap(char*buf1,char*buf2,int width)  //char*解引用交换一个字节，width控制类型，假如是8个字节的double类型交换要交换8次
{
    for(int i=0;i<width;i++)
    {
        char temp=*buf1;
        *(buf1++)=*buf2;
        *(buf2++)=temp;
        
    }
}

//1.用户写的比较函数
int cmp_double(void *a, void *b)
{
    return (*(double*)a)-(*(double*)b);
}



//1.  改造冒泡排序，让其可以排序任意类型
void bubble_sort(void*start,int sz,int width,int(*cmp)(void*e1,void*e2))  //传入元素宽度（字节大小）可以确定强制类型转换的类型
{
    int i=0; //趟数
    for (int i=0;i<sz;i++)
    {
        int j=0;
        for(j=0;j<sz-i-1;j++)
        {
            // 两个元素的比较，未知的类型，需要一个比较函数
            if (cmp((char*)start+j*width,(char*)start+(j+1)*width)>0)    //找到相邻两个元素，拿到cmp函数的结果
            {
                //交换，未知类型，利用char*类型一次跳过一个字节的性质
                //比较函数由调用冒泡排序函数的用户写，传入比较的类型与结果
                //cmp(base,(char*)base+width)

                // 交换操作,传入两个函数的地址还有宽度
                Swap((char*)start+j*width,(char*)start+(j+1)*width,width);                
            }
            

        }
    }

}

int main()
{
    // 1. 改造冒泡排序，让其可以排序任意类型
    // 1.1 排序double
    double arr1[]={32.0,25.6,12.3,3.1415926,4.564,28.5,13.0,15.8};
    int sz=sizeof(arr1)/sizeof(arr1[0]);
    bubble_sort(arr1,sz,sizeof(arr1[0]),cmp_double);
    // 打印输出
    for (int i = 0; i <sz;i++)
    {
        printf("%.8f   ",arr1[i]);
    }

}