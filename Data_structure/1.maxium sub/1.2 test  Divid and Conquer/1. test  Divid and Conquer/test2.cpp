#define _CRT_SECURE_NO_WARNINGS
# include<iostream>
# include<algorithm>
# include<stdio.h>
using namespace std;
int arr[3] = {1,2,3};
int resove(int n); // µÝ¹éº¯Êý

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
		for (int m = 0; m < 3; m++)
			cout << arr[m];
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