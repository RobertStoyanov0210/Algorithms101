#include <iostream>
using namespace std;

void printArr(int*, int);
void insertionSort(int*, int);
void swap(int& a, int& b) {
		a ^= b;
		b ^= a;
		a ^= b;
}
int main() {

		int A[] = { 5, 6, 2, 3, 1, 4, -1, 7, 0 };
		printArr(A, 9);
		insertionSort(A, 9);

		return 0;
}
void insertionSort(int* arr, int n) {
		int i = 1, j, x;
		while (i < n)
		{
				x = arr[i];
				j = i - 1;
				while (j >= 0 && arr[j] > x)
				{
						arr[j + 1] = arr[j];
						j = j - 1;
				}
				arr[j + 1] = x;
				i++;
		}
		printArr(arr, n);
}
void printArr(int* arr, int n) {
		for (size_t i = 0; i < n; i++)
		{
				if (i < n - 1)
						cout << arr[i] << ", ";
				else
						cout << arr[i];
		}
		cout << endl;
}