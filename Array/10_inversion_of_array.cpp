/**
  * Here,inversion count is the number of pairs where i < j and arr[i] > arr[j].
  * It could be done using mergesort. During merging of the two halves,
  * if the smaller element belongs to second half then increase the inv_count by
  * mid - i , which is the count of pairs that could be made with that jth element.
  * Time complexity is O(n * log(n)) and space complexity is O(n).
  */

// https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

#include <bits/stdc++.h>
using namespace std;

long long int merge(long long arr[], long long temp[], long long left, long long mid, long long right) {
    long long i = left, j = mid, k = left, inv_count = 0;

    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }

    while (i <= mid - 1)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];
    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

long long int mergeSort(long long arr[], long long temp[], long long left, long long right) {
    long long mid, inv_count = 0;
    if (right > left) {
        mid = (left + right) / 2;

        inv_count += mergeSort(arr, temp, left, mid);
        inv_count += mergeSort(arr, temp, mid + 1, right);

        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

long long int inversionCount(long long arr[], long long N) {
    long long temp[N];
    return mergeSort(arr, temp, 0, N - 1);
}