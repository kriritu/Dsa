#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

// Partition function similar to quicksort
int partition(vector<int>& arr, int left, int right) {
    int pivotIndex = left + rand() % (right - left + 1);
    int pivotValue = arr[pivotIndex];
    swap(arr[pivotIndex], arr[right]); // Move pivot to end
    int storeIndex = left;

    for (int i = left; i < right; ++i) {
        if (arr[i] < pivotValue) {
            swap(arr[i], arr[storeIndex]);
            storeIndex++;
        }
    }
    swap(arr[storeIndex], arr[right]); // Move pivot to its final place
    return storeIndex;
}

// Quickselect function to find kth smallest element
int quickSelect(vector<int>& arr, int left, int right, int k) {
    if (left == right) // Only one element
        return arr[left];

    int pivotIndex = partition(arr, left, right);

    int length = pivotIndex - left + 1;
    if (length == k)
        return arr[pivotIndex];
    else if (k < length)
        return quickSelect(arr, left, pivotIndex - 1, k);
    else
        return quickSelect(arr, pivotIndex + 1, right, k - length);
}

int kthSmallestElement(vector<int>& arr, int k) {
    if (k < 1 || k > arr.size()) {
        throw invalid_argument("k is out of bounds");
    }
    return quickSelect(arr, 0, arr.size() - 1, k);
}

int main() {
    vector<int> arr = {12, 3, 5, 7, 19, 26};
    int k;
    cout<< "Enter k value: ";
    cin>> k;
    try {
        int kth_smallest = kthSmallestElement(arr, k);
        cout << k << "rd smallest element is " << kth_smallest << "\n";
    } catch (const exception& ex) {
        cout << ex.what() << "\n";
    }
    return 0;
}
