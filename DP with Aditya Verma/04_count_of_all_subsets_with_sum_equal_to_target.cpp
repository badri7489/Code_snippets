#include<iostream>
#include<vector>
using namespace std;

int countSubsetSum(vector<int>& arr, int target) {
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= target; j++) {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][target];
}

int main() {
    vector<int> arr{ 2, 3, 5, 6, 8, 10, 4, 3, 2, 5, 2, 4, 7, 3, 4, 5, 6, 7, 7, 5, 2, 3, 4, 5, 2, 6, 10, 3, 2, 5, 5, 6, 4};
    int x = 10;
    cout << countSubsetSum(arr, x);
    return 0;
}