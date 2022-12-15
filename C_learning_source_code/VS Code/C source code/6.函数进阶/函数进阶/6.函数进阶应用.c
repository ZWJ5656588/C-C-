#include <string.h>
#include <stdio.h>

void Swap2(int*pa,int* pb) //形参其实是实参的一份临时拷贝，如果只改变形参的值，则不影响实参，而改变地址则会影响实参,传址调用，改变实参
{
	int tmp=0;
	tmp=*pa;
	*pa=*pb;
	*pb=tmp;
}                           //交换值函数实现

int Search(int arr[],int k,int sz)  //形参int arr[]传递的是数组的指针 ,而指针的大小在32位系统中是4个字节，就是一串32个bit位地址的大小（转换成byte)
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
	char arr2[20]="###########"; //多余的#遇到“\0”结束字符不会输出
	strcpy(arr2,arr1);
	printf("%s\n",arr2);
	}
	printf("----------------------------\n");

	{
		char arr[]="hallo,world";  //该字符串前五个元素改成*
		memset(arr,97,5);         //字符存储的是ASCII码值，传参也是ASCII码值，不能放字符串！！！
		//这里97代表‘a’
		printf("%s\n",arr);
	}
	printf("----------------------------\n");
	{

		int x=0;
		int y=0;
		printf("请输入未交换前的两个整数\n");
		scanf("%d %d",&x,&y);
		Swap2(&x,&y);
		printf("交换值后的两个数分别为%d,%d",x,y);

	}
	printf("\n----------------------------\n");

	{
		int arr1[16]={1,2,3,4,6,7,9,12,13,15,17,19,21,24,26,29};
		int k=0;
		int sz=sizeof(arr1)/sizeof(arr1[0]);
		int search_result;
		printf("请输入您要查询的数字1-30之间：");
		scanf("%d",&k);
		search_result=Search(arr1,k,sz);
		if(search_result!=-1)
		{
			printf("找到了，下标是%d\n",search_result);
		}
		else
		{
			printf("没有找到\n");
		}
	}
	
}
