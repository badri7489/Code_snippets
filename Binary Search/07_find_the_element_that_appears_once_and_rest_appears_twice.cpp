/**
  * The given array contains all elements twice except for one element, and the array is sorted.
  * So we can apply binary search in this.
  * We know for sure that an element with frequency 1 is present.
  * There is a partition at the index where there is the single element.
  * The left contains all elements with 1st instance at even position and 2nd instance at odd.
  * The right contains all elements with 1st instance at odd position and 2nd instance at even.
  * Hence we apply binary search and determine if the mid and the mid + 1 or mid - 1 (according to the even or odd positioning)
  * are equal or not.
  * If yes then we update the low else we update the right.
  * At an instance when low > high then we stop.
  * Then the low is pointing at the single element and the high is pointing at the end of the left side.
  * Time complexity is O(log(n)).
  */

// Problem link : https://leetcode.com/problems/single-element-in-a-sorted-array/

#include<bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int low = 0, high = nums.size() - 2, mid;
    while (low <= high) {
        mid = (low + high) >> 1;
        if (nums[mid] == nums[mid ^ 1])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return nums[low];
}
