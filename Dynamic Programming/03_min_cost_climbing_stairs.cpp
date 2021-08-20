#include<bits/stdc++.h>
using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
    vector<int> dp(cost.size() + 1);
    for (int i = 2; i <= cost.size(); i++) {
        int oneStep = dp[i - 1] + cost[i - 1];
        int twoStep = dp[i - 2] + cost[i - 2];
        dp[i] = min(oneStep, twoStep);
    }
    return dp[cost.size()];
}