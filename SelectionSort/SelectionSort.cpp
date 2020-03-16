#include <iostream>
using namespace std;

void selectionSort(int *, int);
int searchMinElementIndex(int *, int);
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
	selectionSort(A, n);

	return 0;
}
int searchMinElementIndex(int *arr, int n)
{
	int min = arr[0];
	int i, iSaver = 0;
	for (i = 1; i < n; i++)
	{
		if (min > arr[i])
		{
			min = arr[i];
			iSaver = i;
		}
	}

	return iSaver; // index of min element
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

void selectionSort(int *arr, int n)
{
	int min = searchMinElementIndex(arr, n);
	swap(arr[0], arr[min]); // first element of the array is min

	for (size_t min = 1; min < n; min++)
		for (size_t j = min; j < n; j++) // searching for next min element
			if (arr[j] < arr[min])
				swap(arr[j], arr[min]);

	printArr(arr, n);
}