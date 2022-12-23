#include <stdio.h>

// 求最大子列和的算法分析

// 1.分而治之的算法
int max3(int a, int b, int c) // 返回三个数的最大值
{
    // 比较 MaxLeftSum,MaxRightSum,MaxLeftBorderSum+MaxRightBorderSum
    int max = a;
    if (b > max)
        max = b;
    if (c > max)
        max = c;
    return max;
}

int DivideAndConquer(int List[], int left, int right) // 分治法求List[left]到List[right]的最大子列和
{
    int MaxLeftSum, MaxRightSum;             /*存放左右子问题的解*/
    int MaxLeftBorderSum, MaxRightBorderSum; /*存放夸跨分解线的结果*/

    int LeftBorderSum, RightBorderSum;
    int center, i;

    if (left == right) // 递归终止的条件 子列只有1个数字
    {
        if (List[left] > 0)
            return List[left];
        else
            return 0;
    }

    // 下面是分的过程
    center = (center + right) / 2; // 找到中分点
    // 递归求得两边子列最大和
    MaxLeftSum = DivideAndConquer(List, left, center);
    MaxRightSum = DivideAndConquer(List, center + 1, right);

    // 下面是跨分界线的最大子列和
    MaxLeftBorderSum = 0;
    LeftBorderSum = 0;
    for (i = center; i >= left; i--) // 从中线向左扫描
    {
        LeftBorderSum += List[i];
        if (LeftBorderSum > MaxLeftBorderSum)
            MaxLeftBorderSum = LeftBorderSum;
    } // 左边扫描结束

    MaxRightBorderSum = 0;
    RightBorderSum = 0;
    for (i = center + 1; i <= right; i++)
    {
        RightBorderSum += List[i];
        if (RightBorderSum > MaxRightBorderSum)
            MaxRightBorderSum = RightBorderSum;

    } // 右边扫描结束

    /*下面返回治的结果*/
    return max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}

int main()
{
    int list[] = {4, -3, 5, -2, -1, 2, 6, -2};
    int maxsumlist = DivideAndConquer(list, 0, 7);
    printf("%d\n", maxsumlist);
}
