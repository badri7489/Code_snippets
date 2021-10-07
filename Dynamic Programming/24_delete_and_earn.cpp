#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 10005;
        vector<int> sum(n, 0);  // Total sum by each number.
        vector<int> dp(n, 0);   // DP to solve the house robber problem.
        for (int num : nums)
            sum[num] += num;
        dp[0] = sum[0];
        dp[1] = max(sum[0], sum[1]);
        // Similar to the house robber problem.
        for (int i = 2; i < n; i++)
            dp[i] = max(dp[i - 2] + sum[i], dp[i - 1]);
        return dp[n - 1];
    }
};


class Solution {
private:
    int helper(vector<int>& nums, int i, vector<int>& dp) {
        if (i == nums.size())   // Base condition reached
            return 0;
        if (dp[i] != 0) // If we already have a subsequence of it.
            return dp[i];
        int ele = nums[i], nextIndex = i, sumi = 0;
        // Skipping the duplicates and including it in the sum.
        while (nextIndex < nums.size() && nums[nextIndex] == ele) {
            sumi += ele;
            nextIndex++;
        }
        // Skipping the element + 1 elements.
        while (nextIndex < nums.size() && nums[nextIndex] == ele + 1)
            nextIndex++;
        // Either we pick that element or skip that element.
        return dp[i] = max(helper(nums, nextIndex, dp) + sumi, helper(nums, i + 1, dp));
    }
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Sorting, so that we can skip elements easily.
        vector<int> dp(nums.size(), 0);
        return helper(nums, 0, dp);
    }
};