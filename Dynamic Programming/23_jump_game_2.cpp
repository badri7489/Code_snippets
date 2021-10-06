#include<iostream>
#include<vector>
using namespace std;

// Similar to the jump game 1.
// We just need to store the minimum number of jumps required.
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 0;
        vector<int> dp(n, 1e9);
        dp[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 1; j <= nums[i]; j++) {
                if (i + j < n)
                    dp[i] = min(dp[i], dp[i + j] + 1);
            }
        }
        return dp[0];
    }
};

// Linear BFS approach.
class Solution {
public:
    int jump(vector<int>& nums) {
        int l = 0, r = 0, ans = 0, farthest = 0, n = nums.size();
        while (r < n - 1) {
            farthest = 0;
            for (int i = l; i < r + 1; i++)
                farthest = max(farthest, nums[i] + i);
            l = r + 1;
            r = farthest;
            ans++;
        }
        return ans;
    }
};