#include <stdio.h>
#include <string.h>
int main(int argc,const char* argv[])

{  
	{ //1.������Ϊ�β�ʱ�����ݵ��ǵ�ֵַ������ʱע���ǵ��ö�Ӧ��ַ��ֵ
		int age[3]={1,5,8};
		void change2 (int array[3]);//��������д��printf�Ȳ���֮ǰ
		printf("age[0]=%d\n",age[0]);
		change2(age);
		printf("age[0]=%d\n",age[0]);
	}

	{
			//2.�������򷽷�
			//����������
			int list[]={4,3,6,2,7,1,18,26,54,32,12,33,24,26,87,45};
			//��������Ķ��������Ԫ�ظ���Ϊmax value in original array
			int sort[87]={0};
			//д������������ĳ���
			int len=sizeof(list)/sizeof(list[0]);
			int sorted[16]={0}; //����һ�����������ڽ���������ɵ�����
			//��������������
			int i;int n=0;int j=0;int m;int k=0;
			for( i=0;i<len;i++)  //for ѭ����� �п��Զ�����������и�ֵ��ע���÷ֺŸ���
			{
				//ȡ����ǰ�������鵱ǰֵ
				int index=list[i];
				//�����������鵱ǰֵ��Ϊ�������������
				//���������������Ӧ������ԭ��ֵ+1,
				sort[index-1]=sort[index-1]+1;
			}
			while(k<87)
			{	
				if (sort[k]!=0)
				{
					while(n<len)
					{
						for(j=0;j<sort[k];j++)
						{
							sorted[n]=k+1;
							n++;
						}
						break;
					}
				}
				k++;
			}


			printf("����������Ϊ[");
			for(m=0;m<len;m++)
				printf("%d ",sorted[m]);
			printf("]\n");
	}
}


void change2(int array[3])
{
	array[0]=88;
}

