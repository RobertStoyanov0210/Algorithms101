#include <iostream>
using namespace std;

int maxElement(int*, int);
void sortInAnotherArray(int*, int*, int);
void printArr(int*, int);

int main() {

		int A[] = { 5, 6, 2, 3, 1, 4, -1, 7, 0 };
		int B[9];
		cout << "Array A: ";
		printArr(A, 9); // print before sort

		cout << endl << "Sorting arrays.\n\n";

		sortInAnotherArray(A, B, 9);

		cout << "Array A: ";
		printArr(A, 9); // print after sort
		cout << endl << "Array B: ";
		printArr(B, 9);

		return 0;
}

int maxElement(int* arr1, int n) { // max element in given array
		int max = arr1[0];
		for (size_t i = 1; i < n; i++)
				if (max < arr1[i])
						max = arr1[i];
		return max;
}

void sortInAnotherArray(int* arr1, int* arr2, int n) {
		int min, flag;
		int max = maxElement(arr1, n);
		arr2[n - 1] = max;
		for (size_t i = 0; i < n - 1; i++) // current element in arr2
		{
				min = arr1[0];
				flag = 0;
				for (size_t j = 0; j < n; j++) // searching next min element
				{
						if (arr1[j] < min)
						{
								min = arr1[j];
								flag = j;
						}
				}
				arr2[i] = min; // putting elements in arr2
				arr1[flag] = max; // eliminating current element in arr1
		}
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