#include <stdio.h>
int i ;//5. 全局变量不初始化，默认是0！！！！
int main()
{
    {
        //1.指针类型决定指针运算时的步长，step单位是Byte
        int a=0x11223344;
        int *pa=&a;
        char *pc=(char*)&a;
        printf("%p\n",pa);
        printf("%p\n",pa+1);
        printf("%p\n",pc);
        printf("%p\n",pc+1);
    }
    printf("\n1.-------------------\n");
    {
        //1.2
        int arr[10]={0};
        int *p=arr; //数组名，首元素地址
        int i=0;
        for (i=0;i<10;i++)
        {
            *(p+i)=1;  //通过指针移动，将数组内所有元素均加一
            //因为是整型的指针，所以一次移动4，对应int大小
        }
        printf("[");
        for ( i = 0; i < 10; i++)
        {
            printf("%d ",*p);
        }
        printf("]");
        
    }
    printf("\n1.2-------------------\n");

    {
        //2.野指针
        //指针未初始化，数组越界,指针指向的内存释放
        {
            //局部变量使用过后地址就销毁，无法指针访问
            // int*test();
            // int*p=test();
            // printf("%d\n",*p);
        }
            
        
    }
    {
        //3.short类型指针运算
        int arr[]={1,2,3,4,5}; 
        //倒着放入内存! 比如3 放到内存中是 0x 30 00 00 00,内存中的存储方式一般是16进制
        short*p=(short*)arr ; //强制转成短整型的指针，short类型是2B
        int i=0;
        for ( i = 0; i <5; i++)
        {
            *(p+i)=0;  //循环一次把两个字节变成0，int类型由四个字节，所以前两个数字变成0
        }
        for (i=0;i<5;i++)
        {
            printf("%d ",arr[i]);
        }
        
    }
        printf("\n3.-------------------\n");
    {
        //4. char类型指针
        int a=0x11223344;
        char *pc=(char*)&a;
        *pc=0;
        printf("%x\n",a); //十六进制打印
        printf("%d\n",a); //十进制打印
    }
      printf("\n4.-------------------\n");

    {
        //5. 负数与unsigned int 比较大小
        i--;
        if (i>sizeof(i)) //sizeof()计算变量/类型所占内存的大小>=0，返回无符号数unsigned int
        //当整型和无符号数进行比较时，均看做转化为无符号数，符号位成有效位，-1的最高位是1，所以这个数很大 
        //-1的无符号数是0xffffffff,负数的补码当成正数的源码使用
        {
            printf(">\n");
            printf("%x\n",(unsigned) i );
        }
        else
        {
            printf("<\n");
        }

    }
    printf("\n5.-------------------\n");
    {
        //6.1 运算符操作实例1
        int a,b,c;
        a=5;
        c=++a;
        b=++c,c++,++a,++a; //逗号表达式优先级低于赋值，故b=++c先算
        b+=a++ +c;
        printf("a=%d,b=%d,c=%d\n",a,b,c); //a=9,b=23,c=8

    }
     printf("\n6.-------------------\n");
    {
        //6.2 运算符操作实例2
        int a,b,c;
        a=5;
        c=++a;
        b=(++c,c++,++a,++a); //这里括号里的先算，取逗号表达式的最后一个赋值给b,b=8=++a
        b+=a++ +c;
        printf("a=%d,b=%d,c=%d\n",a,b,c); //a=9,b=24,c=8
    }

    
}

// int*test()
// {
//     int a=10;
//     return &a;
// }
