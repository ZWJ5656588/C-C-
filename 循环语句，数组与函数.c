#include <stdio.h>
#include <string.h>
int main(int argc,const char* argv[])

{  
	{ //1.数组作为形参时，传递的是地址值，调用时注意是调用对应地址的值
		int age[3]={1,5,8};
		void change2 (int array[3]);//函数声明写在printf等操作之前
		printf("age[0]=%d\n",age[0]);
		change2(age);
		printf("age[0]=%d\n",age[0]);
	}

	{
			//2.计数排序方法
			//待排序数组
			int list[]={4,3,6,2,7,1,18,26,54,32,12,33,24,26,87,45};
			//用于排序的定义数组的元素个数为max value in original array
			int sort[87]={0};
			//写出待排序数组的长度
			int len=sizeof(list)/sizeof(list[0]);
			int sorted[16]={0}; //定义一个空数组用于接收排序完成的数组
			//遍历待排序数组
			int i;int n=0;int j=0;int m;int k=0;
			for( i=0;i<len;i++)  //for 循环语句 中可以定义变量并进行赋值，注意用分号隔开
			{
				//取出当前排序数组当前值
				int index=list[i];
				//将待排序数组当前值作为排序数组的索引
				//将用于排序数组对应的索引原有值+1,
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


			printf("排序后的数组为[");
			for(m=0;m<len;m++)
				printf("%d ",sorted[m]);
			printf("]\n");
	}
}


void change2(int array[3])
{
	array[0]=88;
}

