#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int left[n1], right[n2];
    for (int i = 0; i < n1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < n2; i++)
        right[i] = arr[m + i + 1];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {  // Putting the elements back in the sorted way using both the left and right array.
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }
    while (i < n1)  // If left has elements left.
        arr[k++] = left[i++];
    while (j < n2)  // If right has elements left.
        arr[k++] = right[j++];
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);       // left side.
        mergeSort(arr, m + 1, r);   // right side.
        merge(arr, l, m, r);        // Sorting and merging both the sides.
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
        mergeSort(arr, 0, n - 1);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}