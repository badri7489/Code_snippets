#include<iostream>
#include<vector>
using namespace std;

// Bottom up approach.
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& arr) {
        int m = arr.size(), n = arr[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1)
                    dp[i][j] = min(0, arr[i][j]);
                else if (i == m - 1)
                    dp[i][j] = min(0, arr[i][j] + dp[i][j + 1]);
                else if (j == n - 1)
                    dp[i][j] = min(0, arr[i][j] + dp[i + 1][j]);
                else
                    dp[i][j] = min(0, arr[i][j] + max(dp[i + 1][j], dp[i][j + 1]));
            }
        }
        return abs(dp[0][0]) + 1;
    }
};