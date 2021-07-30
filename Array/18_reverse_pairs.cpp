/** Brute force approach would be O(n^2) hence we should try to better it.
  * Optimal approach would be to use the merge sort algorithm.
  * We will divide the array into parts and then while merging it back,
  * we will count the numbers which are on the right hand side and satisfy arr[i] <= 2 * arr[j].
  * Then we will have the count of those which are supposed to be arr[i] > 2 * arr[j].
  * For the rest of the values on the left hand side we will keep j the same and add it to the count for each i on the left.
  * This is because each time the subparts will be sorted
  * so we can say those on the beginning of the left side will be greater than all those
  * who are at the beginning of the right side.
  * The time complexity will be O(n * log(n)) + O(n) + O(n).
  * Space complexity will be O(n).
  */

#include <bits/stdc++.h>
using namespace std;

int merge(vector<int>& arr, int low, int mid, int high) {
    int count = 0, j = mid + 1;
    for (int i = low; i <= mid; i++) {
        while (j <= high && arr[i] > 2LL * arr[j])
            j++;
        count += (j - (mid + 1));
    }
    vector<int> temp;
    int left = low, right = mid + 1;
    while (left <= mid && right <= high) {
        if (arr[left] < arr[right])
            temp.push_back(arr[left++]);
        else
            temp.push_back(arr[right++]);
    }
    while (left <= mid)
        temp.push_back(arr[left++]);
    while (right <= high)
        temp.push_back(arr[right++]);
    for (int i = low; i <= high; i++)
        arr[i] = temp[i - low];
    return count;
}

int mergeSort(vector<int>& arr, int low, int high) {
    if (low >= high)
        return 0;
    int mid = (low + high) / 2;
    int inv = 0;
    inv += mergeSort(arr, low, mid);
    inv += mergeSort(arr, mid + 1, high);
    inv += merge(arr, low, mid, high);
    return inv;
}
int reversePairs(vector<int>& nums) {
    return mergeSort(nums, 0, nums.size() - 1);
}
