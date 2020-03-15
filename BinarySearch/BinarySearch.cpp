#include <iostream>
using namespace std;

void binarySearch(int *, int, int);

int main()
{
	int A[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int x;
	cout << "Number you want to search for: ";
	cin >> x;
	binarySearch(A, 10, x);

	return 0;
}

void binarySearch(int *arr, int n, int x)
{
	int left = 0; 
	int right = n;
	int searchIndex = (left + right) / 2;
	bool notFound = true;
	while (left <= right) // if left and right are crossed then x is not in the array
	{
		if (arr[searchIndex] == x)
		{
			cout << "X is in the array and it is on position " << searchIndex << endl;
			notFound = false;
			break;
		}
		// move left and right indexes with 1 to the middle
		else if (arr[searchIndex] > x)
			right = searchIndex - 1;

		else
			left = searchIndex + 1;
	}
	if (notFound)
		cout << "X is not in this array!" << endl;
}