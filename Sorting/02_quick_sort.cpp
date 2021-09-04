#include<bits/stdc++.h>
using namespace std;

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);  // Placing an element in its correct position.
        quickSort(arr, low, p - 1);         // Call for left side.
        quickSort(arr, p + 1, high);        // Call for right side.
    }
}

// Lomuto Partition.
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // pivot
    int i = low - 1;        // index of smaller element
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {  // If current element is smaller than or equal to pivot
            i++;    // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);  // Placing an element in its correct position.
        quickSort(arr, low, p);         // Call for left side.
        quickSort(arr, p + 1, high);    // Call for right side.
    }
}

// Hoare's Partition.
int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low - 1, j = high + 1;
    while (true) {
        // Leftmost element greater than or equal to pivot.
        do {
            i++;
        } while (arr[i] < pivot);
        // Rightmost element smaller than or equal to pivot.
        do {
            j--;
        } while (arr[j] > pivot);
        // If two pointers meet then we break.
        if (i >= j)
            return j;
        swap(arr[i], arr[j]);
    }
}