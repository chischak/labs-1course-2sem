#include <iostream>
#include <ctime>
using namespace std;

// function to sort arr using shellSort
int shellSort(int arr[], int n)
{
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < n; i += 1)
		{
			int j;
			int temp = arr[i];
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
				arr[j] = arr[j - gap];
			}
			arr[j] = temp;
		}
	}
	return 0;
}

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

int main()
{
	srand(time(NULL));
	int size;
	cout << "Enter array's size: ";
	cin >> size;
	cout << endl;
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 101;
	}
	cout << "Array before sorting: ";
	printArray(arr, size);
	cout << endl;
	shellSort(arr, size);
	cout << "\nArray after sorting: ";
	printArray(arr, size);

	return 0;
}