#define _CRT_SECURE_NO_WARNINGS

# include<stdio.h>
# include<string.h>

int main()
{
	char s[80];
	char* p = s;
	char* sp = "Hello";
	p++;
	sp = strcpy(p, sp);
	*(p++) = 'h';
	puts(sp);  //strcpy返回的是++s的地址
}

