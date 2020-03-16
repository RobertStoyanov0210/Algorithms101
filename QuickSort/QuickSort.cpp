#include <iostream>
using namespace std;

void QuickSort(int *, int, int, int);
int partition(int *, int, int, int);
void printArr(int *, int);
void swap(int *a, int *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

int main()
{
  int A[] = {5, 6, 7, 8, 1, 4, -1, 7, 0};
  int n = (sizeof(A) / sizeof(*A));
  QuickSort(A, n, 0, n - 1);
  printArr(A, n);
  return 0;
}

int partition(int *arr, int n, int low, int high)
{
  int pivot = arr[high];

  int i = low - 1;

  for (int j = low; j <= high - 1; j++)
  {
    if (arr[j] < pivot)
    {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[high]);
  return (i + 1);
}

void QuickSort(int *arr, int n, int low, int high)
{
  if (low < high)
  {
    int pivot = partition(arr, n, low, high);

    QuickSort(arr, n, low, pivot - 1);  // left side
    QuickSort(arr, n, pivot + 1, high); // right side
  }
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