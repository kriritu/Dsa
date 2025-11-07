#include <bits/stdc++.h>
using namespace std;

void selection_sort(int a[], int n){
    for(int i = 0; i < n - 1; i++){
        int min_idx = i;
        for(int j = i + 1; j < n; j++){
            if(a[j] < a[min_idx]){
                min_idx = j;
            }
        }
        // Swap outside the inner loop
        int temp = a[i];
        a[i] = a[min_idx];
        a[min_idx] = temp;
    }
}

int main(){
    int n;
    cout << "enter n:";
    cin >> n;
    int arr[n];
    cout<<"Give array to sort:";

    for(int i = 0; i < n; i++){
        
        cin >> arr[i];
    }
        

    selection_sort(arr, n);
    cout<<"Sorted array: ";
    for(int i = 0; i < n; i++){
        
        cout << arr[i] << " ";
    }
    return 0;
}
