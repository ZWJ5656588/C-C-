
#include <stdio.h>
#include <string.h>
//#define MAX 100 //#define�����ʶ������
//int Max(int x,int y)
//{
//	if (x>y)
//		return x;
//	else
//		return y;
//}
//
//int main()
//{
//	int num1=10;
//	int num2=20;
//	int max=0;
//	//if(num1>num2)
//	//	printf("�ϴ�ֵΪ%d\n",num1); 
//	//else
//	//	printf("�ϴ�ֵΪ%d\n",num2);*/
//	max=Max(num1,num2);
//	printf("�ϴ�ֵΪ%d\n",max);
//	return 0;
//}
void test()
{
		//int a=1;//a�Ǿֲ�����������һ������һ��
		static int a=1;//����static a����˾�̬������a��������
		//static ���ξֲ�������ʹ�þֲ����������ӳ�
		//static ����ȫ�ֱ���ʱ���ı���������ʹ�������ڱ�Դ�ļ���ʹ��
		//static ���κ���ʱ���ı����������ԣ�ʹ��ֻ����Դ�ļ��ڱ�����
		a++;
		printf("a=%d\n",a);
}



struct Book //�����ṹ������
{	char name1[20];//C���Գ������
	short price1;//55
};
struct Book2 
{
	char name2 [20];//Python����
	short price2;//45
};


int main()
{
	{
	int input=0;
	printf("��������\n");
	printf("���ú�ѧϰ�𣿣�1/0����");
	scanf("%d",&input);
	if (input==1)
		printf("�õ���offer\n");
	else
		printf("������\n");
	}
// "&&"�߼��룬��Python��and����
//"||"�߼�����Python��or����
//����������(��Ŀ�������� exp1? exp2:exp3 -------exp1Ϊ�棬ִ��exp2������ִ��exp3

	{
		int arr1[10]={0};
		printf("%d\n",arr1[4]);//-�±����ò�����
	}
    {	
	int i=0;
	while (i<5)
		{
			test();
			i++;
		}
	}
	//#define ����ı�ʶ������
	//#define �����Զ����
	{
		//�ֱ��ú���������ʵ�������Ĵ�С�Ƚ�
		int m=10;
		int n=20;
		//

	}
	//�ڴ���һ���ռ�Ϊһ���ֽڣ�32λ��ʾ�ڴ�����32����ַ�߿��Դ���0101���������ź�
	//�����Բ���2^32�η�����ַ��һ����ַ���Դ��һ���ֽڣ�32λ�ڴ�byteΪ4GB
	//&	ȡ��ַ���ţ�&a��//ȡ��ַ��ָ�������32λƽ̨��4byte,64λ��8byte
	{
		int k=10;
		int*p; //int*��һ���������ͣ�����
		double d=3.14;
		double*pd=&d;
		*pd=5.5;
		printf("%lf\n",d);
		printf("%p\n",pd);
		printf("%d\n",sizeof(pd));//��ַ�Ĵ�С�����ƽ̨�йأ�32λ4���ֽڣ�64λ8���ֽ�
		printf("%p\n",&k);//��ӡ��16�������� 00AAFDDC
		p=&k; //ר�Ŵ�ŵ�ַ�ı�����ָ�����
		printf("%p\n",p);
		*p=20;//�����ò�������ͨ��*p��ַ��ѯ����ֵ��Ϊ20��
		printf("%d\n",k);
	}

	{
		struct Book b1={"C���Գ������",55}; 
		struct Book2 b2={"Python����",45};
		struct Book2* p2=&b2;
		//���ýṹ�����ʹ���һ���ṹ�����
		printf("����:%s\n",b1.name1);
		printf("�۸�:%dԪ\n",b1.price1);
		b1.price1=15;//price�Ǳ��� �����޸ģ���name��������������ֱ���޸�
		strcpy(b1.name1,"C++");//name����������������strcpy���������ַ�����
		printf("�޸ĺ������Ϊ��%s\n",b1.name1);
		printf("�޸ĺ�ļ۸�%dԪ\n",b1.price1);//�����޸Ľṹ�������ֵ
		printf("����:%s\n",(*p2).name2);
		printf("�۸�:%dԪ\n",(*p2).price2);

	}
	{/*
		int k=0;
		int m=2;
		if(1==k)
			if(2==m)
				printf("hehe\n");
			else                        //else�������ifƥ�䣬����else
			printf("haha\n");
		*/

	}
	{
		int day=0;
		printf("��������");
		scanf("%d",&day);
		switch(day)            // day����������
		{
		case 1:              
			printf("����һ");
			break;            //�������break,��case��ȥ����һֱִ��֮������
		case 2:              
			printf("���ڶ�");
			break;
		case 3:              
			printf("������");
			break;
		case 4:              
			printf("������");
			break;
		case 5:;            
			printf("������");
			break;
		default:
			printf("��Ϣ��");
			break;
		}
	}

}






