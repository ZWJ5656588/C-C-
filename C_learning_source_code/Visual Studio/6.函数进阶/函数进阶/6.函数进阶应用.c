#include <string.h>
#include <stdio.h>

void Swap2(int*pa,int* pb) //�β���ʵ��ʵ�ε�һ����ʱ���������ֻ�ı��βε�ֵ����Ӱ��ʵ�Σ����ı��ַ���Ӱ��ʵ��,��ַ���ã��ı�ʵ��
{
	int tmp=0;
	tmp=*pa;
	*pa=*pb;
	*pb=tmp;
}                           //����ֵ����ʵ��

int Search(int arr[],int k,int sz)  //�β�int arr[]���ݵ��������ָ�� ,��ָ��Ĵ�С��32λϵͳ����4���ֽڣ�����һ��32��bitλ��ַ�Ĵ�С��ת����byte)
{
	int left=0;
	int right=sz-1;
	while(left<=right)
	{
		int mid=(left+right)/2;
		if(arr[mid]>k)
		{
			right=mid-1;
		}
		else if(arr[mid]<k)
		{
			left=mid+1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}


int main()
{
	{
	char arr1[]="hallo";
	char arr2[20]="###########"; //�����#������\0�������ַ��������
	strcpy(arr2,arr1);
	printf("%s\n",arr2);
	}
	printf("----------------------------\n");

	{
		char arr[]="hallo,world";  //���ַ���ǰ���Ԫ�ظĳ�*
		memset(arr,97,5);         //�ַ��洢����ASCII��ֵ������Ҳ��ASCII��ֵ�����ܷ��ַ���������
		//����97����a��
		printf("%s\n",arr);
	}
	printf("----------------------------\n");
	{

		int x=0;
		int y=0;
		printf("������δ����ǰ����������\n");
		scanf("%d %d",&x,&y);
		Swap2(&x,&y);
		printf("����ֵ����������ֱ�Ϊ%d,%d",x,y);

	}
	printf("\n----------------------------\n");

	{
		int arr1[16]={1,2,3,4,6,7,9,12,13,15,17,19,21,24,26,29};
		int k=0;
		int sz=sizeof(arr1)/sizeof(arr1[0]);
		int search_result;
		printf("��������Ҫ��ѯ������1-30֮�䣺");
		scanf("%d",&k);
		search_result=Search(arr1,k,sz);
		if(search_result!=-1)
		{
			printf("�ҵ��ˣ��±���%d\n",search_result);
		}
		else
		{
			printf("û���ҵ�\n");
		}
	}
	
}
