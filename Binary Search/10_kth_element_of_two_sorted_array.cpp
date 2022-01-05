/**
  * We are given two sorted arrays and we need to find the kth element when both the arrays are joined and sorted.
  * This can be done by simply using a new array of size m + n.
  * We will use the merge sort technique to put the elements in the new array.
  * This will take O(m + n) time and O(m + n) space.
  * Optimal approach would be to use the algorithm that is used in finding the median of two sorted arrays.
  * We will take the array which is smaller in size.
  * Then we will apply binary search on it.
  * As we know that the cut is supposed to be there where k elements from both the array are on one side
  * and the rest elements are on the other side.
  * We using binary search techniques find where the cut is supposed to be made in the 1st array.
  * Then we find the cut to be made in the second array.
  * We stop when all the elements on the left side of the cut are lesser than all the elements on the right side of the cut.
  * When such a condition arises we find the maximum of all the elements on the left side.
  * That is the kth element.
  * We need to keep in mind two edge conditions.
  * First is when k < size(arr1) then we need high = k, because we can’t pick size(arr1) elements from the first array.
  * Second is when k > size(arr2) then low = k - size(arr2), because we can’t pick 0 elements from the first array.
  * Then we must have to pick k - size(arr2) elements from the first array.
  * The time complexity comes out to be O(log(min(m, n))).
  * Space complexity is O(1).
  */

 // Problem link : https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1

#include<bits/stdc++.h>
using namespace std;

int kthElement(int arr1[], int arr2[], int n, int m, int k) {
    if (n > m)
        kthElement(arr2, arr1, m, n, k);
    int low = max(0, k - m), high = min(n, k);
    while (low <= high) {
        int cut1 = (low + high) >> 1;
        int cut2 = k - cut1;
        int l1 = (cut1 == 0) ? INT_MIN : arr1[cut1 - 1];
        int l2 = (cut2 == 0) ? INT_MIN : arr2[cut2 - 1];
        int r1 = (cut1 == n) ? INT_MAX : arr1[cut1];
        int r2 = (cut2 == m) ? INT_MAX : arr2[cut2];

        if (l1 <= r2 && l2 <= r1)
            return max(l1, l2);
        else if (l1 > r2)
            high = cut1 - 1;
        else
            low = cut1 + 1;
    }
    return 1;
}