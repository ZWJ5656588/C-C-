/*
#define _CRT_SECURE_NO_WARNINGS
# include<iostream>
# include "test2.cpp"
using namespace std;

int Max3(int a, int b, int c)
{
    int max = a;
    if (b > max)
        max = b;
    if (c > max)
        max = c;
    return max;
}

int a[100001];
int maxsub(int left, int right)
{
    // �ݹ���� ,��ֻ��һ��Ԫ�ص�ʱ�򣬴���0�Ľ��䷵�أ����򷵻�0
    if (left == right)
    {
        if (a[left] > 0)
            return a[left];
        else
            return 0;
    }
    int mid = (left + right) / 2; // �ҵ��е�e

    // �ֵĹ���
    int maxLeft = maxsub(left, mid);
    int maxRight = maxsub(mid + 1, right);
    cout << maxLeft << endl;
    cout << maxRight << endl;

    // ���磬�����а��� a[mid],������midΪ���������������������к�
    int borderLeft = 0;
    int borderRight = 0;
    int sumLeft = 0;
    int sumRight = 0;

    // ���е�mid����ɨ��
    for (int i = mid; i >= left; i--)
    {
        borderLeft += a[i];
        if (borderLeft > sumLeft) // ����������������к�
            sumLeft = borderLeft;
    }
    // ���е�mid����ɨ��
    for (int i = mid + 1; i <= right; i++)
    {
        borderRight += a[i];
        if (borderRight > sumRight) // ���Ҹ����ұߵ�������к�
            sumRight = borderRight;
    }
    // sumRight+sumLeftΪ�÷�Χ����������к�
    // maxLeftΪleft��mid��Χ�ڵ�������к�
    // maxRightΪmid+1��right��������к�
    // �������ߵ����ֵ
    return Max3(maxLeft, maxRight, sumRight + sumLeft);  // ����C++�е�max����
}


int main()
{
    int n;
    cout << "������n";
    cin >> n;
    cout << "������ListԪ��:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int sum = maxsub(0, n - 1);
    cout << "������к��ǣ�" << sum << endl;
}
*/