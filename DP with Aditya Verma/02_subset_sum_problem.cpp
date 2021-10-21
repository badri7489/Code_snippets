#include<iostream>
#include<vector>
using namespace std;

// Recursive Code
class Solution {
public:
    bool isSubsetSum(int n, int arr[], int sum) {
        if (sum == 0)
            return true;
        if (n == 0)
            return false;
        if (arr[n - 1] <= sum)
            return isSubsetSum(n - 1, arr, sum - arr[n - 1]) || isSubsetSum(n - 1, arr, sum);
        return isSubsetSum(n - 1, arr, sum);
    }
};

// Memoized Code.
class Solution {
private:
    vector<vector<int>> dp;
    bool isSubset(int n, int arr[], int sum) {
        if (sum == 0)
            return true;
        if (n == 0)
            return false;
        if (dp[n][sum] != -1)
            return dp[n][sum];
        if (arr[n - 1] <= sum)
            return dp[n][sum] = isSubset(n - 1, arr, sum - arr[n - 1]) || isSubset(n - 1, arr, sum);
        return dp[n][sum] = isSubset(n - 1, arr, sum);
    }
public:
    bool isSubsetSum(int n, int arr[], int sum) {
        dp.resize(n + 1, vector<int>(sum + 1, -1));
        return isSubset(n, arr, sum);
    }
};

// Top Down DP
class Solution {
public:
    bool isSubsetSum(int n, int arr[], int sum) {
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (arr[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][sum];
    }
};