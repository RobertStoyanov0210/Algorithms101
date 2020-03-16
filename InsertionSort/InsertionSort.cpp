#include <iostream>
using namespace std;

void printArr(int *, int);
void insertionSort(int *, int);

int main()
{
	int A[] = {5, 6, 7, 8, 1, 4, -1, 7, 0};
	int n = (sizeof(A) / sizeof(*A));
	printArr(A, n);
	insertionSort(A, n);

	return 0;
}

void insertionSort(int *arr, int n)
{
	// cnt - index of sorted array
	// i - search spot for current number
	// x - current number
	int cnt = 1, i, x;
	while (cnt < n)
	{
		x = arr[cnt];
		i = cnt - 1;
		while (i >= 0 && arr[i] > x)
		{
			arr[i + 1] = arr[i];
			i--;
		}
		arr[i + 1] = x;
		cnt++;
	}
	printArr(arr, n);
}
void printArr(int *arr, int n)
{
	for (size_t i = 0; i < n; i++)
	{
		if (i < n - 1)
			cout << arr[i] << ", ";
		else
			cout << arr[i];
	}
	cout << endl;
}