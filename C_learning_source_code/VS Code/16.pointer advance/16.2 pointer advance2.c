# include <stdio.h>
# include <string.h>
# include <stdlib.h>


char str[] =    "rown";
char string[] = "The quick brown dog jumps over the lazy fox";
char fmt1[] =   "         1         2         3         4         5";
char fmt2[] =   "12345678901234567890123456789012345678901234567890";

//3.1��д��ð������
void bubble_sort(int*arr,int sz)
{
    int i=0;
    int j=0;
    int count=0;
    for( i=0;i<sz;i++)
    {
        for ( j=0;j<sz-i-1;j++)  //j��0��ʼ
        {
            if (arr[j] > arr[j+1])
            {
                int temp=0;
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                count++;
            }
        }
        if (count==0)
            break;
    }
}

// 3.2�ṹ������
struct Stu
{
    char name [20];
    int age;
};

// 3.3.1qsort�����еıȽϷ�������,�Ƚ���������
int cmp_int(const void *a, const void *b)
{
    //�Ƚ���������ֵ
    return *((int*)a)-*((int*)b);
}

// 3.3.2 qsort�ȽϽṹ���е�Ԫ��
int cmp_stu_struct_by_age(const void *a, const void *b)
{
    // ����ת��Ϊ�ṹ��ָ������
    return ((struct Stu*)a)->age - ((struct Stu*)b)->age;

}


//

//------------------------------------------------------------------------------


void main( void )
{
    //1.strstr�⺯����Ӧ��
    {
        char *pdest;
        int  result;
        printf( "String to be searched:\n\t%s\n", string );
        printf( "\t%s\n\t%s\n\n", fmt1, fmt2 );
        pdest = strstr( string, str );
        result = pdest - string + 1;  //��ȡstr��Ԫ����string�����е�λ��
        if ( pdest != NULL )
        {
            printf( "%s found at position %d\n\n", str, result );
            printf("%s\n",pdest);
        }
        else 
           printf( "%s not found\n", str );
    }

    {
        //2.����ָ�����Ӧ��
        int arr[10];
        int(*p)[10]=&arr; //ȡ������ĵ�ַ

        int (*pfarr[4])(int,int); // ����ָ�������
        int (*(*ppfarr)[4])(int,int)=&pfarr; // ppfarr��һ������ָ�� ָ����ָ�������ָ��     
    }

    {
        //3.�ص�������ʹ�ó���
        // C���Ա�׼��qsort��������
        int arr[10]={9,8,6,7,5,4,2,3,1,0};
        int sz=sizeof(arr)/sizeof(arr[0]);
        // 3.1 ��д��ð������
        bubble_sort(arr,sz);
        int i=0;
        for ( i = 0; i < sz; i++)
        {
            printf("%d ",arr[i]);
        }
        
        //3.2 ����һ���ṹ���е�Ԫ��
        // ����һ���ṹ������,��ʱ�Զ����ð���������鲻����
        struct Stu s[3]={{"zhagsan",20},{"lisi",30},{"wnagwu",10}};
        
        //3.3 qsort����������
        void qsort( void *base, size_t num, size_t width, int (__cdecl *compare )(const void *elem1, const void *elem2 ) );

        //3.3.1 ����һ����������
        // ��һ��������������ʼ��ַ���ڶ��������鳤�ȣ�������������Ԫ���ֽ��������ĸ������Ǻ���ָ��,ʵ������ıȽϷ���
        int arr1[10]={45,75,52,47,36,40,44,75,61,45};
        qsort(arr1,sz,sizeof(arr[0]),cmp_int); //�޷���ֵ
        printf("\nʹ��qsort��������������\n");
        for ( i = 0; i < sz; i++)
        {
            printf("%d ",arr[i]);
        }

        // 3.3.2 ����ṹ��

    }


}




