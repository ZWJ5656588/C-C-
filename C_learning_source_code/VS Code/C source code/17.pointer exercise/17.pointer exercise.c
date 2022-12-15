#include<stdio.h>
#include<math.h>
#include<string.h>
#include<assert.h>

// 1.1 ����λ
int get_digit_capacity(int i)
{
    if(i/10)
        return get_digit_capacity(i/10)+1;
    else
        return 1;
}


// 1.2 ʵ��n��������Ѱ�Һ���
int is_number(int n,int i)
{
    double sum = 0; //��sum��ת��double���ͣ���ֹ���ȶ�ʧ
    int j=i;
    while(j)
    {
        sum+=pow(j%10,(double)n);
        j/=10;
    }
    if(i==sum)  //�Ƚϵ�ʱ���ǰ�intת����double�Ƚϣ�û������
        return 1;
    else
        return 0;
}


// 3.1 ʵ���ƶ���ż��move����
void move(int* arr1,int sz)
{
    assert(arr1 != NULL);
    int left=0;
    int right=sz-1;
    while (left<right)
    {
       // �������ż��
        while((left<right) && (arr1[left]%2==1))
        {
            left++;
        }
        // ���ұ�������
        while((left<right) && (arr1[right]%2==0))
        {
            right--;
        }
        // ���ҽ���
        if (left<right) // left��++�Ĺ��������һ����ѭ�����ڲ�һ����left>right���˴�����������
        {
            int tmp=arr1[left];
            arr1[left] = arr1[right];
            arr1[right] = tmp;
        }
    }
    
}


// 4.1 ����ת�ַ�����һ
void left_move(char*arr2,int k,int size)
{
    assert(arr2);
    int i=0;
    for( i=0;i<k;i++)
    {
        //����һ���ַ�
        //����k��
        char tmp=*arr2; // Ҫ��ת�����ַ��ȴ�����ʱ������������ɷ������
        // ����Ԫ��������ǰ�ƶ�
        int j=0;
        for(j=0;j<size-1;j++)
        {
            *(arr2+j) = *(arr2+j+1);
        }
        // ������Ԫ�������λ��
        *(arr2+size-1) = tmp;
    }
}


// 4.2 �����ַ�������
void left_move2(char *arr3, int k,int size)
{
    assert(arr3);
    // ������reverse
    void reverse(char *left,char *right);   // ��������
    reverse(arr3,arr3+k-1);
    reverse(arr3+k,arr3+size-1);
    reverse(arr3,arr3+size-1);
}

// 4.2.1 ������reverseʵ��
void reverse(char *left,char *right)  // ������ʼ����ʱ�ĵ�ַ
{
    assert(left);
    assert(right);
    while(left++<right--)
    {
        char tmp = *left;
        *left = *right;
        *right = tmp;
    }
}






int main()
{
    {   
        // 1. ��100000�������n��λ��n��������
        int n=0;
        for (int i = 0; i < 100000; i++)
        {
            int n=get_digit_capacity(i);
            if(is_number(n,i)) 
            {
                 printf("%d ",i);   //�������%d��������и���ض�
            }
        
        }
    }
    puts("\n-------------------------------");


    {
        //2��������ָ��
        int a[5]={5,4,2,1,-3};
        char *ptr=(char*)(&a+1);
        printf("%d,%d,%X\n",*(a+2),*(ptr-1),*(ptr-4)); // ff ff ff fd,�õ��ֽ�ff
        // %d ���ʱҪ������������������λΪ1���в��벹��������λ��1����ff ff ff ff ���%d��ӡ��Դ��ֵ-1
        // %X ʵ������Ȼ�����ͣ������������� ֱ�Ӵ�ӡ�����ʮ������
        int a1=0xfffffffb;
        printf("%d",a1);
    }
    puts("\n-------------------------------");


    {
        // 3. ��һ�����飬���Ҫ��ȫ���������ұ�ȫ��ż��
        int arr1[]={5,4,6,7,3,12,7,13,17,25,14,15,18,16,23,24,32,21,30};
        int sz=sizeof(arr1)/sizeof(arr1[0]);
        for(int i=0; i<sz; i++)
        {
            move(arr1,sz);
            printf("%d ",*(arr1+i));
        }

    }

    puts("\n-------------------------------");

    {
        // 4. ����ת�ַ���
        char arr2[]="swjtubuaa";
        int sz2=strlen(arr2);
        int k=0;            // Ҫ�������ַ�������
        puts("������Ҫ�����ĳ��ȣ�");
        again:
            scanf("%d",&k);
        while(k>sz2)
        {
            puts("������һ���Ϸ����ȣ�");
            goto again;
        }

        // 4.1����������
        left_move(arr2,k,sz2);  
        printf("%s\n",arr2);

        puts("-------------------------------");

        // 4.2 ������ת��
        //ab->ba, cdef->fedc,bafedc->cdefab;
        //ֻ��Ҫдһ�������������벻ͬ�Ĳ�������
        char arr3[]="zwjdashuaibi";
        int sz3=strlen(arr3);
        left_move2(arr3,k,sz3);  
        printf("%s\n",arr3);


    }
}



//size_t ��unsigned int W64����������������unsigned int  strlen�ķ���ֵ���;���size_t




