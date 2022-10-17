
#include <stdio.h>
#include <string.h>
//#define MAX 100 //#define定义标识符常量
//int Max(int x,int y)
//{
//	if (x>y)
//		return x;
//	else
//		return y;
//}
//
//int main()
//{
//	int num1=10;
//	int num2=20;
//	int max=0;
//	//if(num1>num2)
//	//	printf("较大值为%d\n",num1); 
//	//else
//	//	printf("较大值为%d\n",num2);*/
//	max=Max(num1,num2);
//	printf("较大值为%d\n",max);
//	return 0;
//}
void test()
{
		//int a=1;//a是局部变量，调用一次消灭一次
		static int a=1;//加上static a变成了静态变量，a不再销毁
		//static 修饰局部变量，使得局部变量周期延长
		//static 修饰全局变量时，改变其作用域，使其智能在本源文件内使用
		//static 修饰函数时，改变其链接属性，使其只能在源文件内被调用
		a++;
		printf("a=%d\n",a);
}



struct Book //创建结构体类型
{	char name1[20];//C语言程序设计
	short price1;//55
};
struct Book2 
{
	char name2 [20];//Python语言
	short price2;//45
};


int main()
{
	{
	int input=0;
	printf("加入我们\n");
	printf("你会好好学习吗？（1/0）：");
	scanf("%d",&input);
	if (input==1)
		printf("拿到好offer\n");
	else
		printf("烤红薯\n");
	}
// "&&"逻辑与，与Python中and类似
//"||"逻辑或，与Python中or类似
//条件操作符(三目操作符） exp1? exp2:exp3 -------exp1为真，执行exp2，否则执行exp3

	{
		int arr1[10]={0};
		printf("%d\n",arr1[4]);//-下标引用操作符
	}
    {	
	int i=0;
	while (i<5)
		{
			test();
			i++;
		}
	}
	//#define 定义的标识符常量
	//#define 还可以定义宏
	{
		//分别用函数、宏来实现两数的大小比较
		int m=10;
		int n=20;
		//

	}
	//内存中一个空间为一个字节，32位表示内存中有32根地址线可以传达0101的正负电信号
	//共可以产生2^32次方个地址，一个地址可以存放一个字节，32位内存byte为4GB
	//&	取地址符号，&a；//取地址，指针变量在32位平台是4byte,64位是8byte
	{
		int k=10;
		int*p; //int*是一个变量类型，整体
		double d=3.14;
		double*pd=&d;
		*pd=5.5;
		printf("%lf\n",d);
		printf("%p\n",pd);
		printf("%d\n",sizeof(pd));//地址的大小与操作平台有关，32位4个字节，64位8个字节
		printf("%p\n",&k);//打印出16进制序列 00AAFDDC
		p=&k; //专门存放地址的变量—指针变量
		printf("%p\n",p);
		*p=20;//解引用操作符，通过*p地址查询到的值改为20；
		printf("%d\n",k);
	}

	{
		struct Book b1={"C语言程序设计",55}; 
		struct Book2 b2={"Python语言",45};
		struct Book2* p2=&b2;
		//利用结构体类型创建一个结构体变量
		printf("书名:%s\n",b1.name1);
		printf("价格:%d元\n",b1.price1);
		b1.price1=15;//price是变量 可以修改，而name是数组名，不能直接修改
		strcpy(b1.name1,"C++");//name是数组名，，引用strcpy函数进行字符串拷
		printf("修改后的书名为：%s\n",b1.name1);
		printf("修改后的价格：%d元\n",b1.price1);//可以修改结构体变量的值
		printf("书名:%s\n",(*p2).name2);
		printf("价格:%d元\n",(*p2).price2);

	}
	{/*
		int k=0;
		int m=2;
		if(1==k)
			if(2==m)
				printf("hehe\n");
			else                        //else与最近的if匹配，悬空else
			printf("haha\n");
		*/

	}
	{
		int day=0;
		printf("输入数字");
		scanf("%d",&day);
		switch(day)            // day必须是整形
		{
		case 1:              
			printf("星期一");
			break;            //如果不加break,从case进去，会一直执行之后的语句
		case 2:              
			printf("星期二");
			break;
		case 3:              
			printf("星期三");
			break;
		case 4:              
			printf("星期四");
			break;
		case 5:;            
			printf("星期五");
			break;
		default:
			printf("休息日");
			break;
		}
	}

}






