#include<iostream>
#include<vector>
using namespace std;

int helper(vector<int>& nums, int i) {
    if (i >= nums.size())
        return 0;
    return max(nums[i] + helper(nums, i + 2), helper(nums, i + 1));
}

int rob(vector<int>& nums) {
    return helper(nums, 0);
}

int rob(vector<int>& nums) {
    if (nums.size() == 1)
        return nums[0];
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[n - 1] = nums[n - 1];
    dp[n - 2] = max(nums[n - 2], nums[n - 1]);
    for (int i = n - 3; i >= 0; i--)
        dp[i] = max(nums[i] + dp[i + 2], dp[i + 1]);
    return dp[0];
}

int rob(vector<int>& nums) {
    int prev1 = 0, prev2 = 0, temp;
    for (int num : nums) {
        temp = prev1;
        prev1 = max(prev1, num + prev2);
        prev2 = temp;
    }
    return prev1;
}