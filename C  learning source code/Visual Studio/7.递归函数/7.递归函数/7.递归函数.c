#include <stdio.h>
#include <string.h>
int main()
{
	//编写一个统计空格、制表符、换行符个数的程序
	int c,nb,nt,n1;
	nb=0;
	nt=0;
	n1=0;
	while (((c=getchar())!=EOF))
	{
			//此处注意括号！！，！=的优先级高于赋值=，所以不加括号getchar()!=	EOF的结果赋值给c,while执行时c==1，出循环c==0,导致nb,nt,n1值全为0
		if (c ==  ' ')  
			++nb;
		if (c == '\t')
			++nt;
		if (c =='\n')
			++n1;
	}
	printf("空格,制表符，换行符的个数依次是%d,%d,%d",nb,nt,n1);
}



