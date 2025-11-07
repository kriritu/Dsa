#include <bits/stdc++.h>
using namespace std;

int randomized_partition(int arr[], int low, int high) {
    int random = low + rand() % (high - low + 1);
    swap(arr[random], arr[high]);
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void randomized_quick_sort(int arr[], int low, int high) {
    if(low < high) {
        int pi = randomized_partition(arr, low, high);
        randomized_quick_sort(arr, low, pi - 1);
        randomized_quick_sort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;
    int arr[n];
    cout << "Enter array elements:\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    // Random seed for true randomness
    srand(time(0));
    randomized_quick_sort(arr, 0, n - 1);

    cout << "Sorted array:\n";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
