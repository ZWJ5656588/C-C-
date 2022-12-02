# include <string.h>
# include <stdio.h>


//5.字符串排序函数实现
void sort(char*name[],int n)
{
    char*temp;
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n-1;j++)
        {
            if(strcmp(name[i],name[j])>0)  // 注意，strcmp函数的参数就是字符数组的首元素地址
            {
                temp=name[i];
                name[i]=name[j];
                name[j]=temp;
            }
        }
    }
}
void print(char*name[],int n)
{
    int i;
    for ( i = 0; i < n; i++)
    {
        printf("%s\n",name[i]);
    }
    
}

void print1(int (*p)[5],int x,int y ) //7.  用一维数组的地址接收传过来的首元素地址,存放于指针变量
{
    int i=0;
    int j=0;
    for(i=0;i<x;i++)
    {
        //*(p+i)相当于拿到了该行的数组名
        for (j=0;j<y;j++)
        {
            printf("%d ",*(*(p+i) + j)); //等效于*(p[i]+j)等效于*(*(p+i)+j) 等效于*(p+i)[j]等效于p[i][j]
        }
        printf("\n");
    }
}


int main()
{
    {
    //1.数组指针，指针用来存放数组的地址
    // arr-首元素地址
    // &arr 数组的地址
    // &arr[0] 数组首元素的地址
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    int (*p)[10]=&arr; //[]表示指向元素个数，优先级高于*  (*p)表示他是一个指针，指向一个数组
    // int *p1[10]      指针数组，一个数组存放指针变量
    // int (*p2)[10]    数组指针，一个指针指向数组地址
    }

    {
        // 2. 指针类型数组指针的表达
        char c[]="sxcasdc";
        char b='w';
        char*arr[7]={"acc","se5","des5","84sdw","udi",&c[0],&b};
        char*(*pa)[7]=&arr; //pa是一个指针，指向一个大小为5的数组，该数组存放char类型的指针
        char arr1[6]={1,2,3,4,5,6};
        char(*p)[6]=&arr1;
        int(*parr3[10])[5]; // parr3是一个数组，该数组有十个元素，每个元素是一个数组指针，且该数组指针指向的数组有5个int类型的元素

   
    }

    {
        //3.  数组指针
        char*p="o234adf";  //数组首元素地址给了p
        printf("%s\n",p);
        printf("%p\n",p);
        printf("%c\n",*p);

    }

    printf("------------------------------------------------\n");
    
        //4. strcmp,strcpy,_stricmp函数介绍
    {
    char tmp[5];
    int result;
    /* Case sensitive 字典比较，依次向后取出数组元素比较 */
    char string1[] = "THe quick brown dog jumps over the lazy fox";
    char string2[] = "The QUICK brown dog jumps over the lazy fox";
    printf( "Compare strings:\n\t%s\n\t%s\n\n", string1, string2 );
    result = strcmp( string1, string2 );
    if( result > 0 )
        strcpy( tmp, "greater than" );   // 把后面的字符串复制到前面的字符串中，不考虑第一个数组长度问题
    else if( result < 0 )
        strcpy( tmp, "less than" );  // 传入数组首元素地址
    else
        strcpy( tmp, "equal to" );
    printf( "\tstrcmp:   String 1 is %s string 2\n", tmp );
    /* Case insensitive (could use equivalent _stricmp) */

    result = _stricmp( string1, string2 );  // 转化为小写再比较
    if( result > 0 )
        strcpy( tmp, "greater than" );
    else if( result < 0 )
        strcpy( tmp, "less than" );
    else
        strcpy( tmp, "equal to" );
    printf( "\t_stricmp:  String 1 is %s string 2\n", tmp );
    }
    
    printf("----------------------------------------------------------------\n");

    {
        //5.深刻理解 数组指针和指针数组
        // 将若干字符串按照字母顺序（由小到大输出)
        // 思路：定义一个指针数组name ,存放各个字符串的首元素地址,然后使用选择排序。改变数组元素的指向
        char*name[]={"Follow me","BASIC","Great Wall","FORTRAN","Computer design","James Harden"
        ,"Stereoscopic","Digital","champion","264sASD","sDae2971"};
        int n=sizeof(name)/sizeof(name[0]);
        // 函数声明
        void sort(char*name[],int n);
        void print(char*name[],int n);
        // 函数调用
        sort(name,n);  //排序
        print(name,n); //输出

    }
    printf("----------------------------------------------------------------\n");
     
    {
        //6.防止野指针
        int *p,i,a[10];
        p=a;
        printf("please enter 10 integer numbers: ");
        for(i=0;i<10;i++)
        {
            scanf("%d",p++);     // 通过第一次for循环，指针已经指向数组最后
        } 
        for(i=0;i<10;i++,p++);
        {
            printf("%d ",*p);  // 此处指针已经指向数组外
        }
        printf("\n");
        /// 修改代码
        while(getchar()!=EOF)
        {
        }
        printf("please enter 10 integer numbers again:");
        for(int *p1=a, i=0;i<10;i++)
        {
            scanf("%d",p1++);
        }
        for (int *p1 = a,i=0; i < 10; i++)
        {
            printf("%d ",*p1++);
        }
        

    }
    
    printf("\n----------------------------------------------------------------\n");

    {
        // 7. 数组指针在二维数组的应用
        int arr[3][5]={{1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7}};
        //以数组指针的方式打印数组
        print1(arr,3,5); // 二维数组首元素的地址其实就是第一行的一维数组地址，且地址加1跳过1行

    }
}