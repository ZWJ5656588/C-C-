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
    // 递归出口 ,当只有一个元素的时候，大于0的将其返回，否则返回0
    if (left == right)
    {
        if (a[left] > 0)
            return a[left];
        else
            return 0;
    }
    int mid = (left + right) / 2; // 找到中点e

    // 分的过程
    int maxLeft = maxsub(left, mid);
    int maxRight = maxsub(mid + 1, right);
    cout << maxLeft << endl;
    cout << maxRight << endl;

    // 求跨界，该子列包括 a[mid],所以由mid为中心向两边求跨界的最大子列和
    int borderLeft = 0;
    int borderRight = 0;
    int sumLeft = 0;
    int sumRight = 0;

    // 由中点mid向左扫描
    for (int i = mid; i >= left; i--)
    {
        borderLeft += a[i];
        if (borderLeft > sumLeft) // 向左更新左边最大子列和
            sumLeft = borderLeft;
    }
    // 由中点mid向右扫描
    for (int i = mid + 1; i <= right; i++)
    {
        borderRight += a[i];
        if (borderRight > sumRight) // 向右更新右边的最大子列和
            sumRight = borderRight;
    }
    // sumRight+sumLeft为该范围跨界的最大子列和
    // maxLeft为left到mid范围内的最大子列和
    // maxRight为mid+1到right的最大子列和
    // 返回三者的最大值
    return Max3(maxLeft, maxRight, sumRight + sumLeft);  // 利用C++中的max函数
}


int main()
{
    int n;
    cout << "请输入n";
    cin >> n;
    cout << "请输入List元素:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int sum = maxsub(0, n - 1);
    cout << "最大子列和是：" << sum << endl;
}
*/