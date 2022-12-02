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
//2.1常量
//2.1.1字面常量 4,3.14,5684....

//2.1.2const 常变量，将变量赋予常属性
//int main()
//{
//	const int n=10;
//	int arr[n]={1,2,10};//数组报错，数组内必须为常量表达式，n本质上还是变量
//}

//2.1.3  #define 定义的标识符常量
//#define MAX 10
//int main()
//{
//	int arr [MAX]={10};
//	printf("%d\n",MAX);//MAX本质上为常量
//	return 0;
//}
//
//2.1.4枚举常量
//enum Sex
//{  
//	MALE,
//	FEMALE,
//	SECRET,
//};//枚举常量
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
	char arr1[]="abc";//数组，“abc”中自带结束'\0',数组中四个元素
	char arr2[]={'a','b','c','\0'};//'\0'是字符串结束标志
	char arr3[]={'a','b','c'};
	//'0'-0
	//'a'-97
	//'b'-98
	//'A'-65
	printf("%s\n",arr1);
	printf("%s\n",arr2);
	printf("%d\n",strlen(arr1));//打印3，strlen 计算字符串长度，'\0'不统计在内！！
	printf("%d\n",strlen(arr3));//打印随机值，无结束标志'\0'
	printf("%s\n","\"");//转义
	printf("%d\n",strlen("c:\test\32\test.c"));
	//'\t'转义字符为一个字符，\32也是一个转义字符
	//32作为八进制代表的十进制数字，作为ASCII码值，对应的字符
	//32-->十进制为26，对应的ASCII码值d对应的字符为->
	//\ddd(八进制转义）,//\xdd(十六进制转义）
	printf("%d\n",strlen("c:\test\x56\test.c"));
	printf("%s\n","\x56");//5*16^1+6*16^0
	printf("%s\n","\32");
	printf("-------------\n"); 
	}
//C语言分支语句格式
	{	
		int input=0;
		printf("加入图灵\n");
		printf("你要好好学习吗？<1/0>:");
		scanf("%d",&input);//1/0
		if (input==1)
			printf("%s\n","拿到一个好offer");
		else
			printf("GG\n");
		printf("-------------\n");
	}
	
 //C语言循环语句格式
	{
		int line=1;
		printf("加入我们\n");
		while(line<=500)
		{
			printf("敲代码的第%d天\n",line);
			line++;
		}
		printf("好offer\n");
		printf("-------------\n");
	}
//数组
	{
		int arr[10]={1,2,3,4,5,6,7,8,9,10};
		//下标0-9
		int i=0;
		while( i<10)
		{
			printf("%d\n",arr[i]);
			i++;
		}
		printf("-------------\n");
	}

}





