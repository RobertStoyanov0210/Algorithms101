#include <iostream>
using namespace std;

void merge(int *, int *, int *, int, int, int);
void mergeSort(int *, int);
void printArr(int *, int);

int main()
{
	int arr[] = {90, 7, 8, 29, 9, 1, 0};
	int n = sizeof(arr) / sizeof(arr[0]);

	mergeSort(arr, n);

	printArr(arr, n);
	cout << endl;
	return 0;
}

// merge L & R into arr
void merge(int *L, int *R, int *arr, int sizeL, int sizeR, int sizeArr)
{
	int i = 0, j = 0, k = 0;
	// i is index for L
	// j is index for R
	// k is index for arr

	cout << "Merge array [";
	printArr(L, sizeL);
	cout << "] whith array [";
	printArr(R, sizeR);
	cout << ']' << endl;
	while (i < sizeL && j < sizeR)
	{
		if (L[i] < R[j])
			arr[k++] = L[i++];
		else
			arr[k++] = R[j++];
	}
	while (i < sizeL)
	{
		arr[k++] = L[i++];
	};
	while (j < sizeR)
	{
		arr[k++] = R[j++];
	};

	cout << "Result: [";
	printArr(arr, sizeArr);
	cout << ']' << endl;
}

// Recursive function to sort an array of integers.
void mergeSort(int *arr, int n)
{
	int mid, *L, *R;
	if (n < 2)
		return;

	mid = n / 2;

	L = (int *)malloc(mid * sizeof(int));				// 0 to mid-1
	R = (int *)malloc((n - mid) * sizeof(int)); // mid to n-1

	for (int i = 0; i < mid; i++) // left side of the array
		L[i] = arr[i];

	for (int i = mid; i < n; i++) // right side of the array
		R[i - mid] = arr[i];

	// Logic of Merge Sort
	mergeSort(L, mid);
	mergeSort(R, n - mid);
	merge(L, R, arr, mid, n - mid, mid + (n - mid));

	free(L);
	free(R);
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
}