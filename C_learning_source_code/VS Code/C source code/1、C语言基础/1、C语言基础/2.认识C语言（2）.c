#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
//int  main()
//{
//	int num1=0;
//	int num2=0;
//	int sum=0;
//	scanf("%d%d",&num1,&num2);
//	sum=num1+num2;
//	printf("\nsum=%d",sum);
//}
//2.1����
//2.1.1���泣�� 4,3.14,5684....

//2.1.2const �����������������賣����
//int main()
//{
//	const int n=10;
//	int arr[n]={1,2,10};//���鱨�������ڱ���Ϊ�������ʽ��n�����ϻ��Ǳ���
//}

//2.1.3  #define ����ı�ʶ������
//#define MAX 10
//int main()
//{
//	int arr [MAX]={10};
//	printf("%d\n",MAX);//MAX������Ϊ����
//	return 0;
//}
//
//2.1.4ö�ٳ���
//enum Sex
//{  
//	MALE,
//	FEMALE,
//	SECRET,
//};//ö�ٳ���
//int main()
//{
//	printf("%d\n",MALE);//0
//	printf("%d\n",FEMALE);//1
//	printf("%d\n",SECRET);//2
//
//}

int main()
{
	{
	char arr1[]="abc";//���飬��abc�����Դ�����'\0',�������ĸ�Ԫ��
	char arr2[]={'a','b','c','\0'};//'\0'���ַ���������־
	char arr3[]={'a','b','c'};
	//'0'-0
	//'a'-97
	//'b'-98
	//'A'-65
	printf("%s\n",arr1);
	printf("%s\n",arr2);
	printf("%d\n",strlen(arr1));//��ӡ3��strlen �����ַ������ȣ�'\0'��ͳ�����ڣ���
	printf("%d\n",strlen(arr3));//��ӡ���ֵ���޽�����־'\0'
	printf("%s\n","\"");//ת��
	printf("%d\n",strlen("c:\test\32\test.c"));
	//'\t'ת���ַ�Ϊһ���ַ���\32Ҳ��һ��ת���ַ�
	//32��Ϊ�˽��ƴ����ʮ�������֣���ΪASCII��ֵ����Ӧ���ַ�
	//32-->ʮ����Ϊ26����Ӧ��ASCII��ֵd��Ӧ���ַ�Ϊ->
	//\ddd(�˽���ת�壩,//\xdd(ʮ������ת�壩
	printf("%d\n",strlen("c:\test\x56\test.c"));
	printf("%s\n","\x56");//5*16^1+6*16^0
	printf("%s\n","\32");
	printf("-------------\n"); 
	}
//C���Է�֧����ʽ
	{	
		int input=0;
		printf("����ͼ��\n");
		printf("��Ҫ�ú�ѧϰ��<1/0>:");
		scanf("%d",&input);//1/0
		if (input==1)
			printf("%s\n","�õ�һ����offer");
		else
			printf("GG\n");
		printf("-------------\n");
	}
	
 //C����ѭ������ʽ
	{
		int line=1;
		printf("��������\n");
		while(line<=500)
		{
			printf("�ô���ĵ�%d��\n",line);
			line++;
		}
		printf("��offer\n");
		printf("-------------\n");
	}
//����
	{
		int arr[10]={1,2,3,4,5,6,7,8,9,10};
		//�±�0-9
		int i=0;
		while( i<10)
		{
			printf("%d\n",arr[i]);
			i++;
		}
		printf("-------------\n");
	}

}





