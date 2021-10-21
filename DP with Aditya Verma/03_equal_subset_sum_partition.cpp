#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    bool isSubsetSum(vector<int>& arr, int sumi) {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(sumi + 1, 0));
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sumi; j++) {
                if (arr[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][sumi];
    }
public:
    bool canPartition(vector<int>& nums) {
        int sumi = 0;
        for (int it : nums)
            sumi += it;
        if (sumi & 1)   // If sum is odd we can't partition the sum.
            return false;
        return isSubsetSum(nums, sumi >> 1);    // Else we call isSubsetSum on half the sum.
    }
};