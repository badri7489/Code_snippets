/**
  * Brute force approach would be O(n^2) hence we should try to better it.
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

#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    long long inv_count = 0;
    vector<int> temp;

    void merge(vector<int>& arr, int l, int m, int r) {
        int i = l, j = m + 1, k = l;
        for (; i <= m; i++) {
            while (j <= r && arr[i] > 2LL * arr[j])
                j++;
            inv_count += (j - (m + 1));
        }
        i = l, j = m + 1;
        while (i <= m && j <= r) {
            if (arr[i] <= arr[j])
                temp[k++] = arr[i++];
            else {
                temp[k++] = arr[j++];
            }
        }
        while (i <= m)
            temp[k++] = arr[i++];
        while (j <= r)
            temp[k++] = arr[j++];
        for (i = l; i <= r; i++)
            arr[i] = temp[i];
    }

    void mergeSort(vector<int>& arr, int l, int r) {
        if (l < r) {
            int m = l + (r - l) / 2;
            mergeSort(arr, l, m);
            mergeSort(arr, m + 1, r);
            merge(arr, l, m, r);
        }
    }
public:
    int reversePairs(vector<int>& arr) {
        temp.resize(arr.size());
        mergeSort(arr, 0, arr.size() - 1);
        return inv_count;
    }
};