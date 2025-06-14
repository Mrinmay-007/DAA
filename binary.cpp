#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;  // Avoid overflow

        if (arr[mid] == target)
            return mid;  // Found
        else if (arr[mid] < target)
            low = mid + 1;  // Search in right half
        else
            high = mid - 1;  // Search in left half
    }

    return -1;  // Not found
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    cout << "Enter element to search: ";
    cin >> target;

    int index = binarySearch(arr, size, target);

    if (index != -1)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element not found." << endl;

    return 0;
}
