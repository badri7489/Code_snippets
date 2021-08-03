/**
  * We need to trap rainwater in between buildings.
  * Basic understanding from the question is that we need to find
  * the max left and max right on both sides of a building and then take its minimum.
  * Then get the difference between the minimum and the height of the present building.
  * This will be the water stored over that building.
  * Brute force is to find the max on the left subarray and right subarray for all the elements in the array.
  * This will take O(n^2) time complexity and a constant space.
  * Better approach would be to pre-compute the max left and max right for each element in the array and store it in an array.
  * Then in just one pass we can get the total water stored.
  * Time will be O(n) and space will be O(n).
  * Optimal approach would be to take two pointers and keep a track of the left maximum and the right maximum
  * and calculate the water stored on each building.
  */

#include<bits/stdc++.h>
using namespace std;

int trap(vector<int>& arr) {
    if (arr.size() == 0)
        return 0;
    int n = arr.size(), left_max = 0, right_max = 0, low = 0, high = n - 1, ans = 0;
    while (low <= high) {
        if (arr[low] <= arr[high]) {
            if (arr[low] > left_max)
                left_max = arr[low];
            else
                ans += left_max - arr[low];
            low++;
        } else {
            if (arr[high] > right_max)
                right_max = arr[high];
            else
                ans += right_max - arr[high];
            high--;
        }
    }
    return ans;
}
