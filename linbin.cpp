#include <iostream>
using namespace std;

// Linear Search function
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return index if found
        }
    }
    return -1; // Return -1 if not found
}

// Binary Search function (array must be sorted)
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Return index if found
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // Return -1 if not found
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    // Linear Search
    int linearResult = linearSearch(arr, size, target);
    if (linearResult != -1) {
        cout << "Linear Search: Element found at index " << linearResult << endl;
    } else {
        cout << "Linear Search: Element not found" << endl;
    }

    // Binary Search
    int binaryResult = binarySearch(arr, size, target);
    if (binaryResult != -1) {
        cout << "Binary Search: Element found at index " << binaryResult << endl;
    } else {
        cout << "Binary Search: Element not found" << endl;
    }

    return 0;
}
