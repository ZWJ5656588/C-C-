#include<stdio.h>

#define IN 1 //�ڵ�����
#define OUT 0 //�ڵ�����

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
    //�ݹ�ķ������������ʱ������ѭ������
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
//�Ӻ���ǰ�ݹ飬�������㷨�ظ����󣡣���������

int Fib2 (int n)  //��ǰ�������
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
//  1.1  ͳ����������������������ַ���
{
    {
    int c,n1,nw,nc,state;
    n1=nw=nc=0;
    state=OUT;
    printf("�������ַ���\n");
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
    printf("�ַ���%d,����%d,������%d",nc,n1,nw);
    }
    printf("\n----------------------------------------\n");
    //  2.1  ��1234�����������λ�������
    {
        unsigned int num=0;
        printf("����������\n");
        scanf("%d",&num); //����1234
        //�õݹ������⣬�����Լ������Լ�
        print(num);  //��װ��һ������
         //print(1234)
         //print(123) 4
         //print(12)3 4
         //print(1) 2 3 4
    }
    printf("\n----------------------------------------\n");
    {  
        //2.2  ��д��������������ʱ���� ���ַ�������
        char arr[]="bit";
        int len=my_strlen(arr);  //arr�����飬����ȥ���ǵ�һ������Ԫ�صĵ�ַ
        printf("\nlen=%d\n",len);
        //1+my_strlen("it")
        //1+1+my_strlen("t")
        //1+1+1+my_strlen("\0")
    }
    printf("\n----------------------------------------\n");
    {
        //2.3  ���n��쳲�������
        int n=0;
        int ret=0;
        printf("������쳲�����������n\n");
        scanf("%d",&n);
        ret=Fib2(n);
        //TDD����������������
        printf("ret=%d\n",ret);

    }
        
    // ��ŵ�����⣬����������̨���⣡������
    
}



    
    

