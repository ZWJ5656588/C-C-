#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//1.��������Ϸ
//1.1��������һ�������
//1.2������

void menu()
{
	printf("******************************\n");
	printf("****  1. paly   0. exit   ****\n");
	printf("******************************\n");
}
 
void game() //����ʵ��
{
	//=<1>.����һ�������
	int ret;	//���������
	int guess;	//���ղµ�����
	//rand������0-RAND_MAX��32767�����������
	//RAND_MAX 0x7fff-> ʮ����Ϊ��32767
	//��ʱ��������������㣬time now ��1970/1/1 00��00��
	//ʹ��time()����������time_t���ͣ�ת����鿴��ʵ��long��
	//srand((unsigned int) time(NULL));   //time()����Ӧ����ָ�룬�˴����NULL��ָ��

	// ע��srand������ҪƵ�����ã��ڴ�����е���һ�μ��ɣ�������������Ӳ������ܽ�

	ret=rand()%100+1;  //��������������Ҷ�100ȡģ���������������1-100֮��
	//printf("%d\n",ret);

	//<2>.������
	while(1)
	{
		printf("�����֣�->");
		scanf("%d",&guess);
		if(guess<ret)
		{
			printf("��С��\n");
		}
		else if(guess>ret)
		{
			printf("�´���\n");
		}
		else 
		{
			printf("��ϲ�㣬�¶���\n");
			break;
		}

	}
}
int main()
{
	{
		int input;
		srand((unsigned int) time(NULL));   //time()����Ӧ����ָ�룬�˴����NULL��ָ��
		do
		{
			menu();
			printf("��ѡ��->:");
			scanf("%d",&input);
			switch(input)
			{
			case 1:
				game();//��������Ϸ�ĺ���
				break;
			case 0:
				printf("�˳���Ϸ\n");
				break;
			default:
				printf("ѡ�����\n");
				break;
			}

		}while(input);
	}

printf("------------------------------------\n");

	{
		//2.�ҳ������е����ֵ�����Ҵ�ӡ�������Ӧ�±�
		//�����ȱȽϣ��ٸ�ֵ�ķ���
		int arr[]={1,2,8,5,3,4,10,-8,-6,-2,-1,15,11,13};
		int max=arr[0];     //maxΪ�����������ֵ����
		int i;
		int k=0;
		int sz=sizeof(arr)/sizeof(arr[0]);
		for(i=1;i<sz;i++)
		{
			if(max<arr[i])
			{
				max=arr[i];
				k=i;
			}
		}
		printf("�������е����ֵΪ%d,�±�Ϊarr[%d]\n",max,k);
	}




	
}
	


