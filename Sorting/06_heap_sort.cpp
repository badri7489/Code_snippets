// Time Complexity of heapsort: O(n * log(n)).
// Build Heap Time Complexity: O(n).
// Time Complexity of Heapify: O(log(n)).
// Time Complexity of deleting an element from heap: O(log(n)).
#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int> arr, int n, int i) {
    int left = 2 * i + 1, right = 2 * i + 2, largest = i;
    if (left < n && arr[left] > arr[largest])   // Checking if left child is greater.
        largest = left;
    if (right < n && arr[right] > arr[largest]) // Checking if right child is greater.
        largest = right;
    if (largest != i) {     // If any of the child is greater then we swap.
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);   // After swapping we heapify the rest.
    }
}

void buildHeap(vector<int> arr, int n) {
    // Heapifying all the non leaf nodes.
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

void heapSort(vector<int> arr, int n) {
    buildHeap(arr, n);
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);   // Swapping the top of the heap with the last element, said to be deleted.
        heapify(arr, i, 0);     // Heapifying all elements except the ones which have been deleted.
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
        heapSort(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}