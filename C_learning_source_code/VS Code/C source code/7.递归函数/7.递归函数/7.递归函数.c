#include <stdio.h>
#include <string.h>
int main()
{
	//��дһ��ͳ�ƿո��Ʊ�������з������ĳ���
	int c,nb,nt,n1;
	nb=0;
	nt=0;
	n1=0;
	while (((c=getchar())!=EOF))
	{
			//�˴�ע�����ţ�������=�����ȼ����ڸ�ֵ=�����Բ�������getchar()!=	EOF�Ľ����ֵ��c,whileִ��ʱc==1����ѭ��c==0,����nb,nt,n1ֵȫΪ0
		if (c ==  ' ')  
			++nb;
		if (c == '\t')
			++nt;
		if (c =='\n')
			++n1;
	}
	printf("�ո�,�Ʊ�������з��ĸ���������%d,%d,%d",nb,nt,n1);
}



