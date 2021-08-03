/**
  * It can be solved using brute force approach.
  * We will begin by taking an array of m + n size and then put the values of both the arrays in the new array, in a sorted order.
  * Then put the values back in the array. This method will use extra space O(n) and can be done within a time complexity of O(m + n).
  * A better approach will be using insertion sort.
  * Both the arrays are sorted so we can check individual numbers from one array and compare with the other array.
  * Then swap them accordingly and after that we can insertion sort the other array so that it is sorted again.
  * No extra space is used and time complexity is O(n * m).
  *
  * Now the optimal approach will be to use the GAP algorithm. It is the same algorithm taken from shell sort.
  * We will take a certain gap according to the size of both the arrays.
  * The gap will be used to compare the numbers and then swap.
  * The gaps will decrease by 2, and comparing the whole m + n numbers will be done accordingly.
  * Hence this algorithm takes O((m + n) * log(m + n).
  */

#include <bits/stdc++.h>
using namespace std;

// Insertion Sort Approach.
void merge(long long arr1[], long long arr2[], int n, int m) {
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (arr1[i] <= arr2[j])
            i++;
        else {
            swap(arr1[i], arr2[j]);
            i++;
            long long x = arr2[j], k;
            for (k = j + 1; k < m; k++) {
                if (arr2[k] < x)
                    arr2[k - 1] = arr2[k];
                else
                    break;
            }
            arr2[k - 1] = x;
        }
    }
}

// Shell Sort Approach(GAP Method).
void merge(long long arr1[], long long arr2[], int n, int m) {
    int gap = ceil((double)(m + n) / 2);
    while (gap > 0) {
        int i = 0, j = i + gap;
        while (j < m + n) {
            if (j < n && arr1[i] > arr1[j]) {
                swap(arr1[i], arr1[j]);
            } else if (j >= n && j < m + n && i < n && arr1[i] > arr2[j - n]) {
                swap(arr1[i], arr2[j - n]);
            } else if (i >= n && j < m + n && arr2[i - n] > arr2[j - n]) {
                swap(arr2[i - n], arr2[j - n]);
            }
            i++;
            j++;
        }
        gap = (gap <= 1) ? 0 : gap / 2 + gap % 2;
    }
}
