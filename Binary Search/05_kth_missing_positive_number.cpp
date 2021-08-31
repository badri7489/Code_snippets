/**
  * Here we need to find the kth missing number from the array, where number starts from 1 to size of array.
  * Brute Force is to traverse the whole array and try to find the which of the numbers are missing.
  * Simultaneously we decrease the value of k.
  * When k == 0 we stop the loop and return the value of j accordingly.
  * Binary Search Approach is to check how many of the numbers are there before the mid, which are placed correctly.
  * If the count of the numbers which are not placed correctly is more than k then we decrease the search space of high to m.
  * Else we move the search space of low to m + 1.
  */

#include<bits/stdc++.h>
using namespace std;

// Brute Force.
int findKthPositive(vector<int>& nums, int k) {
    int i = 0, j = 0, n = nums.size();
    while (k > 0) {
        j++;
        if (i < n && j == nums[i])
            i++;
        else
            k--;
    }
    return j;
}

// Binary Search.
int findKthPositive(vector<int>& nums, int k) {
    int l = 0, h = nums.size(), m;
    while (l < h) {
        m = l + (h - l) / 2;
        if (nums[m] - 1 - m < k)
            l = m + 1;
        else
            h = m;
    }
    return l + k;
}