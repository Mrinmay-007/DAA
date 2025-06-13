#include <iostream>
using namespace std;

// Utility to print array
void show(int arr[], int n) {
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Selection Sort with pass print
void selectionSort(int arr[], int n) {
    int pass = 1;
    for(int i = 0; i < n - 1; i++) {
        int minIndex = i;

        // Find the index of the minimum element
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap only if needed
        if(minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }

        // Print current pass
        cout << "Pass " << pass << ": ";
        show(arr, n);
        pass++;
    }
}

int main() {
    int arr[] = {4, 5, 3, 1, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array: ";
    show(arr, n);
    cout << "\nSorting steps:\n";
    selectionSort(arr, n);
    cout << "\nSorted array: ";
    show(arr, n);
    return 0;
}
