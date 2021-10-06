#include<bits/stdc++.h>
using namespace std;

// Recursive Approach
bool helper(vector<int>& arr, int i) {
    if (i >= arr.size())
        return false;
    if (i == arr.size() - 1)
        return true;
    for (int j = 1; j <= arr[i]; j++) {
        if (helper(arr, i + j))
            return true;
    }
    return false;
}

bool canJump(vector<int>& nums) {
    return helper(nums, 0);
}

// DP Approach
bool canJump(vector<int>& nums) {
    int n = nums.size();
    if (n == 1)
        return true;
    vector<bool> dp(n, false);
    dp[n - 1] = true;
    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] != 0) {
            for (int j = 1; j <= nums[i]; j++) {
                dp[i] = dp[i] || dp[i + j];
                if (dp[i])
                    break;
            }
        }
    }
    return dp[0];
}

// Linear Solution
bool canJump(vector<int>& nums) {
    int n = nums.size(), farthest = 0;
    for (int i = 0; i < n; i++) {
        if (farthest < i)   // If at any point the index is less than our farthest reach we can't reach the end.
            return false;
        farthest = max(i + nums[i], farthest);  // The farthest index we can reach.
    }
    return true;
}