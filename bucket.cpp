#include <iostream>
#include <vector>
#include <algorithm> // For sort()
using namespace std;

void bucketSort(float arr[], int n) {
    // Create n empty buckets
    vector<float> buckets[n];

    // Put array elements in different buckets
    for(int i = 0; i < n; i++) {
        int index = n * arr[i]; // index in bucket
        buckets[index].push_back(arr[i]);
    }

    // Sort individual buckets
    for(int i = 0; i < n; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // Concatenate all buckets into arr[]
    int idx = 0;
    for(int i = 0; i < n; i++) {
        for(size_t j = 0; j < buckets[i].size(); j++) {
            arr[idx++] = buckets[i][j];
        }
    }
}

int main() {
    int n;
    cout << "Enter number of elements (between 0 and 1): ";
    cin >> n;
    float arr[n];
    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    bucketSort(arr, n);

    cout << "Sorted array:\n";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
