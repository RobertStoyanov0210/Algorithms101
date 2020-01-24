#include <iostream>
using namespace std;
// number of comparisons: n-1

void searchMinElement(int*, int);
void searchMaxElement(int*, int);

int main() {
	int arr[] = { -1, 1, 10, 0, -10 };
	searchMinElement(arr, 5);
	searchMaxElement(arr, 5);
	return 0;
}

void searchMinElement(int* arr, int n) {
	int min = arr[0];
	for (size_t i = 1; i < n; i++)
		if (min > arr[i])
			min = arr[i];
	cout << "Min element: " << min << endl;
}

void searchMaxElement(int* arr, int n) {
	int max = arr[0];
	for (size_t i = 1; i < n; i++)
		if (max < arr[i])
			max = arr[i];
	cout << "Max element: " << max << endl;
}