#include <stdio.h>
#include<string.h>
#include<Windows.h>
int main()
{
	{
	//1.���ֲ����㷨��
	int arr[]={3,7,8,9,10,11,12,13,15,17,18,23,35};
	int k=13;
	int left=0;   //���±�
	int sz=sizeof(arr)/sizeof(arr[0]);
	int right=sz-1;   //���±�
	while(left<=right) //���ֲ��ҽ�������
	{
		int mid=(left+right)/2;
		if(arr[mid]>k)
			right=mid-1;
		else if(arr[mid]<k)
			left=mid+1;
		else
		{
			printf("�ҵ��ˣ��±���%d\n",mid);
			break;
		}
	}
	if(left>right)
		printf("û���ҵ�\n");
	}
	printf("----------------------\n");

	//2.�ַ����������ƶ������
	//welcome to bit!!!!
	//##################
	//w################!
	//...
	//welcome to bit!!!!

	{
		char arr1[]="welcome to bit!!!!";
		char arr2[]="##################";
		int left=0;
		//
		int right=strlen(arr1)-1;  //��Ч��sizeof(arr1)/sizeof(arr1[0])-2
		while (left<=right)
		{
			arr2[left]=arr1[left];  
			arr2[right]=arr1[right];
			printf("%s\n",arr2);
			//ÿ�δ�ӡ֮��ͣ��һ��
			Sleep(100);  //��λΪ���� 1000����
			left++;
			right--;
		}
		printf("----------------------\n");
	}
	
	{
	//3.���ε�¼
	int i=0;
	char account[20]={0};
	char password[20]={0};
	for (i=0;i<3;i++)
	{
			printf("�������¼�˺�:>");
			scanf("%s",account);
			printf("�������¼����:>");
			scanf("%s",password);
			if ((strcmp(password,"zwj123456")==0) && (strcmp(account,"6654320")==0))//"=="���ܱȽ������ַ�����ֵ�Ƿ����,ʹ�ÿ⺯��strcmp�����ʱ����0��
			{
				printf("������ȷ�����Ժ�\n");
				break;
			}
			else
				printf("�������\n");
    }
	if (i==3)
		printf("���ξ���������˳�����\n");

	}
		printf("----------------------\n");
	
	//4.�������������Ӵ�С���
		{
			int a=0;
			int b=0;
			int c=0;
			scanf("%d%d%d",&a,&b,&c);
			//�㷨ʵ��,ͨ������ֵ��ʹ��a,b,cΪ�����������
			//a�����ֵ��b��֮��c����Сֵ
			if(a<b)
			{
				int tmp=a; //������ʱ����
				a=b;
				b=tmp;
			}
			if(a<c)
			{
				int tmp=a;
				a=c;
				c=tmp;
			}
			if(b<c)
			{
				int tmp=b;
				b=c;
				c=tmp;
			}
			printf("%d %d %d ",a,b,c);
		}
		printf("----------------------\n");
		//5.շת����������Լ����
		{	
			int m=49;
			int n=378;
			int r;
			while(n%m)
			{
				r=n%m;
				n=m;
				m=r;
			}
			printf("49��378�����Լ����%d\n",m);
		}
			printf("----------------------\n");

		//6.forѭ���ж������������������
		//6.1,forѭ����ʡ�Ա�����ʼ��
		{
			{
			int i=0;
			int j=0;//ѭ�������������ֵ
			for(; i<10; i++)  
			{
				for(; j<10; j++)
				{
				printf("hehe\n"); //ֻ��ӡʮ�Σ��ڲ�ѭ��j=10ʱ������㣬i++�ٽ����ڲ�ʱ��j�Ե���10������ִ���ڲ�ѭ��
												
				}
			}
			}
			printf("----------------------\n");
		//6.2 ��forѭ���ڲ����б�����ʼ��
			{
				int i;
				int j;
				for(i=0; i<10; i++)  
				{
					for(j=0; j<10; j++)  //��ÿһ�δ����ѭ�������ڲ�ʱ��j�������¸�ֵΪ0��
						printf("hehe\n"); //��ӡ100�κǺ�
												
				}
			}
		}	
			printf("----------------------\n");
		//7��  0-100�������г��ֶ��ٴ�����9 

		//!!!����������99Ҫ�����Σ���if������else if)
			{
				int i=0;
				int count=0;
				for(i=1;i<=100;i++)
				{
					if(i%10==9)
						count++;
					if(i/10==9)  //��һ��ifִ�к󣬵ڶ���if��Ҫ�ж�
						count++;
				}
				printf("������%d\n",count);
			}

					
   
}