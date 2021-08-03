/**
  * The elements of the array are sorted and then rotated some number of times.
  * We need to search an element in the array in O(log(n)) time.
  * We apply normal binary search in the array.
  * We find the mid, check if that's the target, if not then we check which side of the array is sorted
  * and if that part is sorted then try to check if the target may appear there or not.
  * This continues until we find the element.
  * This is done in log(n) time and constant space.
  */

#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1, mid;
    while (low <= high) {
        mid = (low + high) >> 1;
        if (nums[mid] == target)
            return mid;
        if (nums[low] <= nums[mid]) {
            if (nums[low] <= target && nums[mid] >= target)
                high = mid - 1;
            else
                low = mid + 1;
        } else {
            if (nums[mid] <= target && nums[high] >= target)
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}
