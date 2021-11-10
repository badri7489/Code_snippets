#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());   // Sort all the coins
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        int n = coins.size();
        for (int i = 0; i <= amount; i++) {
            for (int j = 0; j < n; j++) {
                if (coins[j] <= i)  // If coin value is less than the ith amount then we take it into consideration
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                else    // Else we don't need to check for any other bigger coins.
                    break;
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};