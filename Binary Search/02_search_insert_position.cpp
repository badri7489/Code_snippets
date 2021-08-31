/**
  * When we implement binary search on a sorted array, there are two cases that originate.
  * First is if we search the array and find the element, then we return the index.
  * Second is if the element is not found and here we need to return the position to put that element.
  * The low and high pointer crosses each other if an element is not found.
  * So we know that the element is to be put at position low or high + 1.
  * Time Complexity: O(log(n)).
  */

#include<bits/stdc++.h>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int l = 0, h = nums.size() - 1, m;
    while (l <= h) {
        m = (l + h) >> 1;
        if (nums[m] == target)
            return m;
        else if (nums[m] > target)
            h = m - 1;
        else
            l = m + 1;
    }
    return h + 1;   // return l
}