#include"stdio.h"
#include"stdlib.h"
#include"iostream"
using namespace std;

int GetMax(int a, int b)   //得到两个数的最大值
{
	return (a) > (b) ? (a) : (b);
}

int GetMaxAddOfArray(int* arr, int sz)
{
	int i = 0;
	int k = 0;
	if (arr == NULL || sz <= 0)
		return 0;

	for (i = 0; i < sz; i++)
	{
		if (arr[i] < 0) {
			k++;
		}
	}

	if (k == sz)
		return 0;


	int Sum = arr[0];   //临时最大值
	int MAX = arr[0];   //比较之后的最大值

	for (int i = 1; i < sz; i++)
	{
		Sum = GetMax(Sum + arr[i], arr[i]);   //状态方程

		if (Sum >= MAX)
			MAX = Sum;
	}
	return MAX;
}

int zuoye1(int n0, int* array1) {
	int array[20];
	int i = 0;
	int n;
	n = n0;
	for (i = 0; i < n; i++)
	{
		array[i] = array1[i];
	}
	int sz = n;
	int MAX = GetMaxAddOfArray(array, sz);
	return MAX;
}

int main()
{
	int zs;
	int array2[20];
	int i,max;
	scanf_s("%d",&zs);
	for (i = 0; i < zs; i++) {
		scanf_s("%d",&array2[i]);
	}
	max = zuoye1(zs, array2);
	printf_s("%d",max);
	return 0;
}