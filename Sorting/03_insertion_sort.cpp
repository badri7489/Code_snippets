/**
  * We take an element from the array and name it as key.
  * Then we consider that left side of the array is sorted and we try to find the correct position for the key.
  * Until we find the position we shift all the element greater than the key to the right.
  * When we find the correct position of the element we put it there.
  * Time complexity, average and worst case: O(n^2).
  * Time complexity, best case: O(n).
  * Space Complexity: O(1).
  */

#include<iostream>
using namespace std;

void insert(int arr[], int i) {
    int key = arr[i], j = i - 1;    // Key is the one which we compare with others to find the correct position for it.
    while (j >= 0 && arr[j] > key) {
        arr[j + 1] = arr[j];    // Duplicating the value and shifting it to the left.
        j--;
    }
    arr[j + 1] = key;   // At the jth position we find that all element left of it is lesser than the key, so we swap.
}
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++)
        insert(arr, i); // Finding the place of ith element in the sorted part of the array.
}
