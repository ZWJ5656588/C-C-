#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//1.猜数字游戏
//1.1电脑生成一个随机数
//1.2猜数字

void menu()
{
	printf("******************************\n");
	printf("****  1. paly   0. exit   ****\n");
	printf("******************************\n");
}
 
void game() //函数实现
{
	//=<1>.生成一个随机数
	int ret;	//接受随机数
	int guess;	//接收猜的数字
	//rand，生成0-RAND_MAX（32767）的随机整数
	//RAND_MAX 0x7fff-> 十进制为：32767
	//用时间戳设置随机数起点，time now 至1970/1/1 00；00的
	//使用time()函数，返回time_t类型，转定义查看其实是long型
	//srand((unsigned int) time(NULL));   //time()函数应调用指针，此处添加NULL空指针

	// 注意srand函数不要频繁调用，在代码块中调用一次即可，这样随机数种子不会相距很近

	ret=rand()%100+1;  //生成随机数，并且对100取模，控制随机数处在1-100之间
	//printf("%d\n",ret);

	//<2>.猜数字
	while(1)
	{
		printf("猜数字：->");
		scanf("%d",&guess);
		if(guess<ret)
		{
			printf("猜小了\n");
		}
		else if(guess>ret)
		{
			printf("猜大了\n");
		}
		else 
		{
			printf("恭喜你，猜对了\n");
			break;
		}

	}
}
int main()
{
	{
		int input;
		srand((unsigned int) time(NULL));   //time()函数应调用指针，此处添加NULL空指针
		do
		{
			menu();
			printf("请选择->:");
			scanf("%d",&input);
			switch(input)
			{
			case 1:
				game();//猜数字游戏的函数
				break;
			case 0:
				printf("退出游戏\n");
				break;
			default:
				printf("选择错误\n");
				break;
			}

		}while(input);
	}

printf("------------------------------------\n");

	{
		//2.找出数组中的最大值，并且打印，输出对应下标
		//采用先比较，再赋值的方法
		int arr[]={1,2,8,5,3,4,10,-8,-6,-2,-1,15,11,13};
		int max=arr[0];     //max为最后输出的最大值变量
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
		printf("该数组中的最大值为%d,下标为arr[%d]\n",max,k);
	}




	
}
	


