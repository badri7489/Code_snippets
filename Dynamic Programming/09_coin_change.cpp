#include<bits/stdc++.h>
using namespace std;

// I wrote this DP.
int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    int dp[n + 1][amount + 1];
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 0; i <= amount; i++)
        dp[0][i] = INT_MAX - 1;
    for (int i = 1; i <= amount; i++) {
        if (i % coins[0] == 0)
            dp[1][i] = i / coins[0];
        else
            dp[1][i] = INT_MAX - 1;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= amount; j++) {
            if (coins[i - 1] <= j)
                dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][amount] == INT_MAX - 1 ? -1 : dp[n][amount];
}

// Concise DP.
int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    int dp[n + 1][amount + 1];  // To store number of coins which sum up to the given amount. For a given number of coins.
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= amount; j++) {
            if (j == 0)         // Amount is 0 so there is 0 coins needed.
                dp[i][j] = 0;
            else if (i == 0)    // Coins is 0 so infinite coins are needed to make up the amount.
                dp[i][j] = INT_MAX - 1;
            else if (coins[i - 1] <= j)     // Value of coin is less than amount.
                dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][amount] == INT_MAX - 1 ? -1 : dp[n][amount];
}