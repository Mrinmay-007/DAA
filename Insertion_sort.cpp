#include <iostream>
using namespace std;

// Function to print the array
void show(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Insertion sort with pass output
void insertionSort(int arr[], int n) {
    int pass = 1;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Shift elements greater than key
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;

        // Print the array after each pass
        cout << "Pass " << pass << ": ";
        show(arr, n);
        pass++;
    }
}

int main() {
    int n;

    // Input array size
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];  // Use static array size (safe for small inputs)

    // Input array elements
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Show original array
    cout << "\nOriginal array: ";
    show(arr, n);

    // Sorting steps
    cout << "\nSorting steps:\n";
    insertionSort(arr, n);

    // Final result
    cout << "\nSorted array: ";
    show(arr, n);

    return 0;
}
