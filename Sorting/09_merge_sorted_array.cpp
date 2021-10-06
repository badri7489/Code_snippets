#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& arr1, int m, vector<int>& arr2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        // We start filling the array from the back of arr1.
        while (i >= 0 && j >= 0) {
            if (arr1[i] > arr2[j])
                arr1[k--] = arr1[i--];
            else
                arr1[k--] = arr2[j--];
        }
        // If the second array is bigger than the first so we copy that.
        while (j >= 0)
            arr1[k--] = arr2[j--];
    }
};