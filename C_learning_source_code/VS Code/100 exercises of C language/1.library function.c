# include<stdio.h>
# include<string.h>

int main()
{
    // 1.strcpy 的返回值
    char s[80],*sp="Hello, world!";
    char*p=s;
    p++;
    sp=strcpy(p,sp); //返回值是目标字符串的首地址
    p[0]='h';
    puts(sp);
    puts("--------------------------------");

    // 2.strcat的返回值
    
}