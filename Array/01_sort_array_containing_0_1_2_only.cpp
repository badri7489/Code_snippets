/**
  * We will sort the array inplace.
  * We can do preprocessing like count the number of 0’s, 1’s and 2’s in the array.
  * Then we can loop the array and write all the values accordingly.
  * But if we want to do inplace sort without preprocessing
  * then we can sort by pointing the values of each one of them.
  * The low pointer points the index before which all are 0's.
  * The high pointer points the position after which all are 2's
  * The loop stops when mid crosses high.
  */
// https://leetcode.com/problems/sort-colors/

#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;
    while (mid <= high) {
        if (nums[mid] == 0)
            swap(nums[low++], nums[mid++]);
        else if (nums[mid] == 1)
            mid++;
        else if (nums[mid] == 2)
            swap(nums[mid], nums[high--]);
    }
}