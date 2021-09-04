#include<bits/stdc++.h>
using namespace std;

int select(vector<int>& arr, int i) {
    int m = i, n = arr.size();
    for (int j = i; j < n; j++) {
        if (arr[m] > arr[j])
            m = j;
    }
    return m;   // Index of the minimum element from i to the end of the array.
}

void selectionSort(vector<int>& arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int m = select(arr, i); // Getting the minimum of the unsorted array.
        swap(arr[i], arr[m]);   // Swapping it to put it at the ith place.
    }
}

int main() {
    vector<int> arr(10000, 0);
    int n, t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        selectionSort(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}