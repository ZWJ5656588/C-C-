#define _CRT_SECURE_NO_WARNINGS
# include<iostream>
# include<algorithm>
# include<stdio.h>
using namespace std;
int arr[3] = {1,2,3};
int resove(int n); // 递归函数

void my_swap(int arr[], int k, int j)
{
	int tmp = arr[k];
	arr[k] = arr[j];
	arr[j] = tmp;
}

int resove(int n)
{
	if (n == 3)
	{
		for (int i = 0; i < 3; i++)
			cout << arr[i];
		cout<< endl;
		return 0;
	
	}
	for (int i = n; i < 3; i++)
	{
		my_swap(arr, n,i);
		resove(n + 1);
		my_swap(arr, n,i);
	}
}
int main()
{
	resove(0);
}