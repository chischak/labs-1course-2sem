#include <iostream>
#include <ctime>


using namespace std;
int partition(int arr[], int low, int high)
{
    int x = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < x) {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}


void quickSort(int arr[], int low, int high)
{
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


int main()
{
    srand(time(0));
    int size;
    cout << "enter unsorted array: ";
    cin >> size;
    int* arr = new int[size];
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 101;
        cout << arr[i] << " ";
    }
    cout << endl;

    quickSort(arr, 0, size - 1);
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    return 0;
}