#include <stdio.h>
#include <string.h>
void squeeze(char s[],char c) //1.????????????��?c???
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

void print_table(int n)         //4.2 ???????????
{
    int i=0;
    for ( i = 0; i <=n; i++)
    {
        int j=0;
        for(j=1;j<=i;j++)
        {
            printf("%d*%d=%-3d",i,j,i*j);
        }
        printf("\n");
    }
    
}

void main()
{
    {
    //1. ????????????????????????
    char test[]="sadwqfeasxxxdexxx";
    squeeze(test,'x');
    char arr1[]="abcd";
    arr1[1]=arr1[1];
    arr1[2]=arr1[0];
    printf("\n%c",arr1[1]);
    printf("\n%c\n",arr1[2]);
    }
    printf("\n1.--------------------------\n");

    //2.??????????????????????????????
    {
        //2.1?????,????????��????????
        int a=3;
        int b=5;
        a=a+b;
        b=a-b;
        a=a-b;
        printf("\nafter swap a=%d,b=%d\n",a,b);
    }
    printf("\n2.1--------------------------\n");
      
    {
        //2.2???????
        long long a=45105565000007;
        long long b=60000064000452;
        a=a^b;
        b=a^b;
        a=a^b;
        printf("\nafter swap a=%lld,b=%lld\n",a,b);
    }
    printf("\n2.2--------------------------\n");
    {
        //3. ????????????????��??1?????
        //3.1 /2%2????,?????????,???????num?????????????
        unsigned num=0;
        int count=0;
        printf("\n??????????????num=");
        scanf("%d", &num);
        while (((unsigned)num))
        {
            if((unsigned)num%2==1)
                count++;
            num=num/2;
        }
        printf("??????1??????%d\n",count);
    }
    printf("\n3.1--------------------------\n");

    {
        //3.2 ??��??&????????????????
        int i=0;
        int num1=0;
        int count1=0;
        printf("\n??????????????num1=");
        scanf("%d",&num1);
        for ( i = 0;i<32;i++)
        {
            if ((num1>>i)&1)
            {
               count1++;
            }
        }
        printf("\n??????1??????%d\n",count1);   
    }
    printf("\n3.2--------------------------\n");

    {
        //3.3????????
        //exp1,exp2,exp3..expn?????????????1??n??????????????n???
    }
    {
        //4.1 ????????????????????????��?????��
        int num1=0;
        printf("????????????????");
        scanf("%d",&num1);
        for ( int i = 0; i < 16; i++)
        {
           if((num1>>(2*i))&1)
           {
            printf("??%2d��?????????��1\n",(2*i+1));
           }
           else 
           {
            printf("??%2d��?????????��0\n",(2*i+1));
           }
        }
        printf("\n");
        for ( int i = 0; i < 16; i++)
        {
           if((num1>>(2*i+1))&1)
           {
            printf("??%2d��?????????��1\n",(2*(i+1)));
           }
           else 
           {
            printf("??%2d��?????????��0\n",(2*(i+1)));
           }
        
        }
        
    }

    {
        //4.2 ?????????????????
        int n=0;
        printf("???????????????");
        scanf("%d",&n);
        void print_table(int n);
        print_table(n);
        
    }
    printf("\n4.2--------------------------\n");
    {
        //5. unsigned char
        char a=-1;  //????????????????
        //ff ff ff ff ??
        // char??????? ff
        // a ..ff
        signed char b=-1;//ff
        unsigned char c=-1;//ff
        printf ("a=%d,b=%d,c=%d",a,b,c);
        // ???????��????��????????????  
        //char a ??????????? ff ff ff ff,????? 80 00 00 01
        //unsigned char c ????????��??0 ???????? 00 00 00 ff


    }
    
    printf("\n5.--------------------------\n");

    {    // 6.
         char a=-128;
         printf("%u\n",a);  //4294967168  0x ffffff80
         // %u???????????????
    }

    {
        //6.7
        char b=127;
        char c=b+1;
        // (char)127+1 ??????????????????? ??01111111(127)->10000000(-128)
        printf("%d",c);  // char ??��??��??-128????127  

    }
}

