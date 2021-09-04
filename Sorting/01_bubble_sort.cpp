#include<bits/stdc++.h>
using namespace std;

// Normal Bubble Sort.
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

// Optimised Bubble Sort.
void bubbleSort(int arr[], int n) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                s = 1;  // Keeping track if an element is sorted or not.
            }
        }
        if (s == 0)     // If s = 0 then there are no swaps so we can break from the loop as all the elements are sorted.
            break;
    }
}

// Recursive Implementation of Bubble Sort.
void bubbleSort(int arr[], int n) {
    if (n == 1)
        return;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1])
            swap(arr[i], arr[i + 1]);
    }
    bubbleSort(arr, n - 1);
}