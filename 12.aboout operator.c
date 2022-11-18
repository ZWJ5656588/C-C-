#include <stdio.h>
#include <string.h>
void squeeze(char s[],char c) //删除数组中所有的c字符
{

    int  i,j,len;
    for (i=j=0;s[i]!='\0';i++)
    {
        if (s[i]!=c)
        {
            s[j]=s[i];
            j++;
        }
    }
    s[j]='\0';
    len=strlen(s);
    for (i=0;i<len;i++)
    {
        printf("%c",s[i]);
    }
}

void main()
{
    {
    //1. 实现字符数组中删除给定的字符
    char test[]="sadwqfeasxxxdexxx";
    squeeze(test,'x');
    char arr1[]="abcd";
    arr1[1]=arr1[1];
    arr1[2]=arr1[0];
    printf("\n%c",arr1[1]);
    printf("\n%c\n",arr1[2]);
    }
    printf("\n1.--------------------------\n");

    //2.不创建临时变量。交换两个整数的值
    {
        //2.1加减法,这种方法有空间缺陷溢出
        int a=3;
        int b=5;
        a=a+b;
        b=a-b;
        a=a-b;
        printf("\nafter swap a=%d,b=%d\n",a,b);
    }
    printf("\n2.1--------------------------\n");
      
    {
        //2.2异或的方法
        long long a=45105565000007;
        long long b=60000064000452;
        a=a^b;
        b=a^b;
        a=a^b;
        printf("\nafter swap a=%lld,b=%lld\n",a,b);
    }
    printf("\n2.2--------------------------\n");
    {
        //3. 求解一个整数二进制位中1的个数
        //3.1 /2%2方法,只适用于非负
        int num=0;
        int count=0;
        printf("\n请输入整形数字num=");
        scanf("%d",&num);
        while ((num))
        {
            if(num%2==1)
                count++;
            num=num/2;
        }
        printf("二进制1的个数为%d\n",count);
    }
    printf("\n3.1--------------------------\n");

    {
        //3.2 按位与&方法，适用于所有
        int i=0;
        int num1=0;
        int count1=0;
        printf("\n请输入整形数字num1=");
        scanf("%d",&num1);
        for ( i = 0;i<32;i++)
        {
            if ((num1>>i)&1)
            {
               count1++;
            }
        }
        printf("\n二进制1的个数为%d\n",count1);   
    }
    printf("\n3.2--------------------------\n");

    {
        //3.3逗号表达式
        //exp1,exp2,exp3..expn，顺序算出表达式1到n的值，结果是表达式n的值
    }
}

