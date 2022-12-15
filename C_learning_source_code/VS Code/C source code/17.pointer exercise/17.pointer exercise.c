#include<stdio.h>
#include<math.h>
#include<string.h>
#include<assert.h>

// 1.1 求数位
int get_digit_capacity(int i)
{
    if(i/10)
        return get_digit_capacity(i/10)+1;
    else
        return 1;
}


// 1.2 实现n次幂数的寻找函数
int is_number(int n,int i)
{
    double sum = 0; //把sum先转成double类型，防止精度丢失
    int j=i;
    while(j)
    {
        sum+=pow(j%10,(double)n);
        j/=10;
    }
    if(i==sum)  //比较的时候是把int转换成double比较，没有问题
        return 1;
    else
        return 0;
}


// 3.1 实现移动奇偶数move函数
void move(int* arr1,int sz)
{
    assert(arr1 != NULL);
    int left=0;
    int right=sz-1;
    while (left<right)
    {
       // 从左边找偶数
        while((left<right) && (arr1[left]%2==1))
        {
            left++;
        }
        // 从右边找奇数
        while((left<right) && (arr1[right]%2==0))
        {
            right--;
        }
        // 左右交换
        if (left<right) // left在++的过程中最后一次在循环体内部一定是left>right，此处条件不能少
        {
            int tmp=arr1[left];
            arr1[left] = arr1[right];
            arr1[right] = tmp;
        }
    }
    
}


// 4.1 左旋转字符串法一
void left_move(char*arr2,int k,int size)
{
    assert(arr2);
    int i=0;
    for( i=0;i<k;i++)
    {
        //左旋一个字符
        //进行k次
        char tmp=*arr2; // 要旋转的首字符先存入临时变量，交换完成放在最后
        // 其余元素依次往前移动
        int j=0;
        for(j=0;j<size-1;j++)
        {
            *(arr2+j) = *(arr2+j+1);
        }
        // 插入首元素在最后位置
        *(arr2+size-1) = tmp;
    }
}


// 4.2 左旋字符串法二
void left_move2(char *arr3, int k,int size)
{
    assert(arr3);
    // 逆序函数reverse
    void reverse(char *left,char *right);   // 函数声明
    reverse(arr3,arr3+k-1);
    reverse(arr3+k,arr3+size-1);
    reverse(arr3,arr3+size-1);
}

// 4.2.1 逆序函数reverse实现
void reverse(char *left,char *right)  // 传入起始结束时的地址
{
    assert(left);
    assert(right);
    while(left++<right--)
    {
        char tmp = *left;
        *left = *right;
        *right = tmp;
    }
}






int main()
{
    {   
        // 1. 在100000以内求出n数位的n次自幂数
        int n=0;
        for (int i = 0; i < 100000; i++)
        {
            int n=get_digit_capacity(i);
            if(is_number(n,i)) 
            {
                 printf("%d ",i);   //最后再以%d输出，进行浮点截断
            }
        
        }
    }
    puts("\n-------------------------------");


    {
        //2、深度理解指针
        int a[5]={5,4,2,1,-3};
        char *ptr=(char*)(&a+1);
        printf("%d,%d,%X\n",*(a+2),*(ptr-1),*(ptr-4)); // ff ff ff fd,拿到字节ff
        // %d 输出时要进行整型提升，符号位为1进行补码补满（其余位补1），ff ff ff ff 最后%d打印出源码值-1
        // %X 实质上仍然是整型，进行整型提升 直接打印补码的十六进制
        int a1=0xfffffffb;
        printf("%d",a1);
    }
    puts("\n-------------------------------");


    {
        // 3. 有一个数组，左边要求全是奇数，右边全是偶数
        int arr1[]={5,4,6,7,3,12,7,13,17,25,14,15,18,16,23,24,32,21,30};
        int sz=sizeof(arr1)/sizeof(arr1[0]);
        for(int i=0; i<sz; i++)
        {
            move(arr1,sz);
            printf("%d ",*(arr1+i));
        }

    }

    puts("\n-------------------------------");

    {
        // 4. 左旋转字符串
        char arr2[]="swjtubuaa";
        int sz2=strlen(arr2);
        int k=0;            // 要左旋的字符串长度
        puts("请输入要左旋的长度：");
        again:
            scanf("%d",&k);
        while(k>sz2)
        {
            puts("请输入一个合法长度：");
            goto again;
        }

        // 4.1暴力交换法
        left_move(arr2,k,sz2);  
        printf("%s\n",arr2);

        puts("-------------------------------");

        // 4.2 三部翻转法
        //ab->ba, cdef->fedc,bafedc->cdefab;
        //只需要写一个逆序函数，传入不同的参数即可
        char arr3[]="zwjdashuaibi";
        int sz3=strlen(arr3);
        left_move2(arr3,k,sz3);  
        printf("%s\n",arr3);


    }
}



//size_t 是unsigned int W64的重命名，类型是unsigned int  strlen的返回值类型就是size_t




