/**
  * We are storing in dp all the arithmetic slices which are ending at that value.
  * Then we count all those arithmetic slices.
  *   2  5  9 12 15 18 22 26 30 34 36 38 40 41
  *   0  0  0  0  1  2  0  1  2  3  0  1  2  0
  */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<int> dp(n);
        for (int i = 2; i < n; i++) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {   // If the last 3 numbers form are in AP.
                dp[i] = dp[i - 1] + 1;  // Then we include the it and the previous one also.
                ans += dp[i];   // All the APs are included.
            }
        }
        return ans;
    }
};