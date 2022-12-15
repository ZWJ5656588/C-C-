#include <stdio.h>
#include<string.h>
#include<Windows.h>
int main()
{
	{
	//1.二分查找算法；
	int arr[]={3,7,8,9,10,11,12,13,15,17,18,23,35};
	int k=13;
	int left=0;   //左下标
	int sz=sizeof(arr)/sizeof(arr[0]);
	int right=sz-1;   //右下标
	while(left<=right) //二分查找进行条件
	{
		int mid=(left+right)/2;
		if(arr[mid]>k)
			right=mid-1;
		else if(arr[mid]<k)
			left=mid+1;
		else
		{
			printf("找到了，下标是%d\n",mid);
			break;
		}
	}
	if(left>right)
		printf("没有找到\n");
	}
	printf("----------------------\n");

	//2.字符串向两端移动并汇聚
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
		int right=strlen(arr1)-1;  //等效于sizeof(arr1)/sizeof(arr1[0])-2
		while (left<=right)
		{
			arr2[left]=arr1[left];  
			arr2[right]=arr1[right];
			printf("%s\n",arr2);
			//每次打印之后停留一秒
			Sleep(100);  //单位为毫秒 1000毫秒
			left++;
			right--;
		}
		printf("----------------------\n");
	}
	
	{
	//3.三次登录
	int i=0;
	char account[20]={0};
	char password[20]={0};
	for (i=0;i<3;i++)
	{
			printf("请输入登录账号:>");
			scanf("%s",account);
			printf("请输入登录密码:>");
			scanf("%s",password);
			if ((strcmp(password,"zwj123456")==0) && (strcmp(account,"6654320")==0))//"=="不能比较两个字符串的值是否相等,使用库函数strcmp，相等时返回0，
			{
				printf("输入正确，请稍后\n");
				break;
			}
			else
				printf("密码错误\n");
    }
	if (i==3)
		printf("三次军输入错误，退出程序\n");

	}
		printf("----------------------\n");
	
	//4.输入三个数，从大到小输出
		{
			int a=0;
			int b=0;
			int c=0;
			scanf("%d%d%d",&a,&b,&c);
			//算法实现,通过交换值，使得a,b,c为符合条件输出
			//a中最大值，b次之，c放最小值
			if(a<b)
			{
				int tmp=a; //创建临时变量
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
		//5.辗转相除法求最大公约数、
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
			printf("49和378的最大公约数是%d\n",m);
		}
			printf("----------------------\n");

		//6.for循环中定义变量的生存与销毁
		//6.1,for循环内省略变量初始化
		{
			{
			int i=0;
			int j=0;//循坏体外给变量赋值
			for(; i<10; i++)  
			{
				for(; j<10; j++)
				{
				printf("hehe\n"); //只打印十次，内层循环j=10时返回外层，i++再进入内层时，j仍等于10，不会执行内层循环
												
				}
			}
			}
			printf("----------------------\n");
		//6.2 在for循环内部进行变量初始化
			{
				int i;
				int j;
				for(i=0; i<10; i++)  
				{
					for(j=0; j<10; j++)  //当每一次从外层循环进入内层时，j都会重新赋值为0，
						printf("hehe\n"); //打印100次呵呵
												
				}
			}
		}	
			printf("----------------------\n");
		//7、  0-100中数字中出现多少次数字9 

		//!!!（隐含条件99要算两次，用if不能用else if)
			{
				int i=0;
				int count=0;
				for(i=1;i<=100;i++)
				{
					if(i%10==9)
						count++;
					if(i/10==9)  //第一个if执行后，第二个if仍要判断
						count++;
				}
				printf("个数是%d\n",count);
			}

					
   
}