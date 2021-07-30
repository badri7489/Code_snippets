/** Simple brute force solution for this would be O(n^3) complexity,
  * which is to iterate the array twice and find every subarray and find the sum and storing the maximum.
  * This can be improved to a better solution of O(n^2), which would be to calculate the sum while considering the subarray.
  *
  * An optimal solution would be of time complexity O(n), which can be done using Kadane’s Algorithm.
  * We just need the sum of subarrays and then find the max from them.
  * So we don’t exactly need the subarrays. We can take the sum of numbers one by one and then find the max.
  * If at any point the sum is less than 0 then we can initialise the sum to again 0,
  * which means we will start taking a new subarray.
  * Hence a linear traversal to get the max sum subarray.
  */

#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int sumi = 0, maxi = nums[0];
    for (int i = 0; i < nums.size(); i++) {
        sumi += nums[i];
        if (maxi < sumi)
            maxi = sumi;
        if (sumi < 0)
            sumi = 0;
    }
    return maxi;
}
