#include <iostream>
using namespace std;

void binarySearch(int *, int, int);
void printArr(int *, int);

int main()
{
	int A[] = {0, 1, 2, 3, 5, 6, 7, 8, 9};
	int n = (sizeof(A) / sizeof(*A));
	int x;
	printArr(A,n);
	cout << "Number you want to search for: ";
	cin >> x;
	binarySearch(A, n, x);

	return 0;
}

void binarySearch(int *arr, int n, int x)
{
	int left = 0;
	int right = n;
	int searchIndex;
	bool notFound = true;
	while (left <= right) // if left and right are crossed then x is not in the array
	{
		searchIndex = (left + right) / 2;
		if (arr[searchIndex] == x)
		{
			cout << "X is in the array and it is on position " << searchIndex << endl;
			notFound = false;
			break;
		}
		// shrink the searching area
		else if (arr[searchIndex] > x)
			right = searchIndex - 1;

		else
			left = searchIndex + 1;
	}
	if (notFound)
		cout << "X is not in this array!" << endl;
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