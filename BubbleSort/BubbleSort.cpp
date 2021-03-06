#include <iostream>
using namespace std;

void bubbleSort(int *, int);
void printArr(int *, int);
void swap(int *a, int *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

int main()
{
	int A[] = {5, 6, 2, 3, 1, 4, -1, 7, 0};
	int n = (sizeof(A) / sizeof(*A));
	printArr(A, n);
	bubbleSort(A, n);
	return 0;
}

void bubbleSort(int *arr, int n)
{
	// swaping first & second index while they reach the sorted part
	for (size_t i = 0; i < n - 1; i++)	 // first index
		for (size_t j = i + 1; j < n; j++) // second index
			if (arr[i] > arr[j])
				swap(arr[i], arr[j]); 

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