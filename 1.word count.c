#include<stdio.h>

#define IN 1 //在单词内
#define OUT 0 //在单词外

void print(int num)
{
    if(num>9)
    {
        print(num/10);
    }
    printf("%d ",num%10);
    
}

int my_strlen (char*str)
{
    //递归的方法解决不用临时变量的循环问题
    if(*str!=0)
    {   
        return 1+my_strlen(str+1) ;
    }
    else
        return 0;
}
int Fib (int n)
{
    if (n<=2)
        return 1;
    else
        return Fib(n-1)+Fib(n-2);
} 
//从后往前递归，，这种算法重复量大！！！运行慢

int Fib2 (int n)  //从前往后计算
{
    int a=1;
    int b=1;
    int c=1;
    while(n>2)
    {
        c=a+b;
        a=b;
        b=c;
        n--;
    }
    return c;

}

int main()
//  1.1  统计输入的行数，单词数，字符数
{
    {
    int c,n1,nw,nc,state;
    n1=nw=nc=0;
    state=OUT;
    printf("请输入字符串\n");
    while((c=getchar())!=EOF)
    {
        ++nc;
        if(c=='\n')
            ++n1;
        if(c==' '||c=='\n'||c=='\t')
            state=OUT;
        else if(state==OUT)
        {
            state=IN;
            ++nw;
        }
    }
    printf("字符数%d,行数%d,单词数%d",nc,n1,nw);
    }
    printf("\n----------------------------------------\n");
    //  2.1  将1234这个数各个数位依次输出
    {
        unsigned int num=0;
        printf("请输入整数\n");
        scanf("%d",&num); //输入1234
        //用递归解决问题，函数自己调用自己
        print(num);  //封装成一个函数
         //print(1234)
         //print(123) 4
         //print(12)3 4
         //print(1) 2 3 4
    }
    printf("\n----------------------------------------\n");
    {  
        //2.2  编写函数，不创建临时变量 求字符串长度
        char arr[]="bit";
        int len=my_strlen(arr);  //arr是数组，传过去的是第一个数组元素的地址
        printf("\nlen=%d\n",len);
        //1+my_strlen("it")
        //1+1+my_strlen("t")
        //1+1+1+my_strlen("\0")
    }
    printf("\n----------------------------------------\n");
    {
        //2.3  求第n个斐波那契数
        int n=0;
        int ret=0;
        printf("请输入斐波那契数序列n\n");
        scanf("%d",&n);
        ret=Fib2(n);
        //TDD——测试驱动开发
        printf("ret=%d\n",ret);

    }
        
    // 汉诺塔问题，，，青蛙跳台问题！！！！
    
}



    
    

