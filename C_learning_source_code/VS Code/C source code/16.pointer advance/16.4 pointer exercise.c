# include<stdio.h>

//. 指针笔面试题
int main()
{
    {
        // 1. 计算大小
        long long int a[]={1,2,3,4,5,6,7,8,9,10};
        printf("%ld\n",sizeof(a)); //80
        printf("%ld\n",sizeof(*a));//8 首元素地址解引用，是首元素
        printf("%ld\n",sizeof(a+1)); //4 这个是首元素地址的大小，地址大小是4
        printf("%ld\n",sizeof(&a)); //4  数组的地址也是地址，大小是4个字节
        printf("%ld\n",sizeof(*&a)); //80 数组大小，一个指针指向数组时，解引用访问一个数组

        puts("----------------------------------------------------------------");

        // 1.2.strlen 求数组长度
        // 从首元素地址开始，向后找到\0终止
        // char arr[]={'a','b','c','d','e','f','g','h'};


        // 1.3.二维数组 sizeof strlen
        int arr1[3][4]={0,7,2,9,5};
        printf("%d\n",sizeof(arr1));// 48
        printf("%d\n",sizeof(arr1[0][0]));// 4 
        printf("%d\n",sizeof(arr1[0])); //实际上是一维数组的大小
        printf("%d\n",sizeof(arr1[0]+1)); // 4 数组名没有单独在sizeof内 实际上是计算地址的大小
        // a[0]+1是第二个元素的地址而不是第二行数组的地址！！
        printf("%d\n",*(arr1[0]+1)); // 7 第二个元素
        printf("%d\n",sizeof(arr1+1));  // arr1不在sizeof中，二维数组首元素表示首地址，其实是第一行一维数组的地址
        // 所以arr1+1是第二行的一维数组的地址
        
        // 1.4二维数组的首元素是第一行的一维数组地址
        printf("%d\n",sizeof(*(arr1+1)));  // 计算第二行的一维数组大小
        printf("%d\n",sizeof(&arr1[0]+1));  // 计算第二行数组地址的大小，&arr1[0]是第一行数组的地址
        printf("%d\n",sizeof(*(&arr1[0]+1))); //计算第二行数组的大小 16
        printf("%d\n",sizeof(arr1[3])); // sizeof不参与真实运算，知识根据类型
    }

    {

        //2.写出计算结果
        int a1[5]={1,2,3,4,5};
        int *ptr=(int*)(&a1+1);   //&a1+1是数组指针类型int(*)[]类型，要进行强制类型转换
        printf("%d\n",*a1);
        printf("%d,%d\n",*(a1+1),*(ptr-1));
        puts("----------------------------------------------------------------");



    }


    {
        // 3.结构体指针运算
        //%p和%x都可以表达十六进制数的占位符,不够八位用0补位
        char c='\x41';
        char b='\101';
        int aa=20;
        printf("%c\n",c);//输出 ASCII码对应的字符  A
        printf("%c\n",b);//输出 ASCII码对应的字符  A 
        printf("%p\n",c); // 按十六进制输出
        printf("%p\n",aa); //按十六进制输出，不满8位补0
        printf("%x\n",aa); // 十六进制输出，不补0


    }

        puts("----------------------------------------------------------------");

    {   // 4. 理解小端存储和16进制、指针解引用访问的字节数
        int a2[4]={1,2,3,4};
        // 存储方式   |01 00 00 00|02 00 00 00|0. 00 00 00|04 00 00 00|
        int *ptr1=(int*)(&a2+1);
        int *ptr2=(int*)((int)a2+1);//地址运算+1
        printf("%x  ,  %p\n",ptr1[-1],*ptr2);  //解引用向后访问四个字节 
        // *ptr2 访问内存中的形式为小端(00 00 00 02),16进制 0x 02000000

    }   puts("----------------------------------------------------------------");



    {
        // 5. 逗号表达式混入数组注意区分！
        // 逗号表达式的优先级最低，以逗号最左边的值作为逗号表达式的返回值
        int a[3][2]={(0,1),(2,3),(4,5)};
        int *p;
        p=a[0];
        printf("%d\n",p[4]);
    }
        puts("----------------------------------------------------------------");

    {
        //6.
        int a[5][5];
        int(*p)[4];
        p=a;  //p的类型int(*)[4],a的类型int(*)[5]
        printf("%p , %n\n",&p[4][2]-&a[4][2],(int)&p[4][2]-(int)&a[4][2]);
        //p+1一次性要过4个元素的地址,(p+4)跳过4*4,解引用一次表示从指向一维数组地址
        //改变为指向数组元素地址,*(p+4)+2挪动2个元素的地址
        //整型指针(地址)相减，表示中间间隔的元素个数
        //如果转化为int型数字相减，则表示的就是十进制运算，要考虑一个元素的字节大小
        //%d输出为-4，十六进制内存中显示补码，FF FF FF FC

    }
        puts("----------------------------------------------------------------");
    {
        //7.
        int aa[2][5]={1,2,3,4,5,6,7,8,9,10}; //两行五列
        int (*ptr1)[4]=(&aa+1);   //转换为一个普通的整形指针
        int (*ptr2)[3]=(*(aa+1));  //转换为一个数组指针
        printf("%d,%d\n",*(*(ptr1-2)+3),*(ptr2[1])); //输出 10,3
    }
        puts("----------------------------------------------------------------");
    {
        char* a[]={"work","at","alibaba"};
        char**pa=a;
        pa=pa+2;
        (*pa)++;
        printf("%s\n",*pa);

    }
        puts("----------------------------------------------------------------");
    {
        //8.
        char *c[]={"ENTER","NEW","PIONT","FIRST"};
        char**cp[]={c+3,c+2,c+1,c};
        char***cpp=cp;
        printf("%s\n",**++cpp); //POINT
        printf("%s\n",*--*++cpp+3);//ER
        //先算++cpp,此时cpp在第一个基础上再加1,cpp是char**cp[2]的地址,*cpp实际上拿到c+1的内容，又有前置--，所以char**cp[2]=c
        //在解引用拿到"ENTER"数组首元素地址，再加3是"E"地址
        printf("%s\n",*cpp[-2]+3);//ST，分析如前
        printf("%s\n",cpp[-1][-1]+1);//EW
        //相当于*（*（cpp-1）-1）+1，*(cpp-1)拿到c+2，c+2-1=c+1，*(c+1)拿到"NEW"首元素地址，再加1拿到“NEW”数组中的"E"地址
    }

}