#include <iostream>
using namespace std;



// Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1; // index of smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Function to print array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Quick Sort function with pass printing
void quickSort(int arr[], int low, int high, int size, int &pass) {
    if (low < high) {
        int pi = partition(arr, low, high);

        cout << "Pass " << pass++ << ": ";
        printArray(arr, size);

        quickSort(arr, low, pi - 1, size, pass);
        quickSort(arr, pi + 1, high, size, pass);
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int pass = 1;

    cout << "Original array: ";
    printArray(arr, n);

    quickSort(arr, 0, n - 1, n, pass);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
